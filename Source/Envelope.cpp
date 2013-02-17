#include "Envelope.h"

Envelope::Envelope()
{
    pi = 4.0f * atan(1.0f);
}

void Envelope::initialize(int env_type, int grain_dur, float grain_dur_ratio,
                          float env_shape, float env_skew, float grain_amp)
{
    this->env_type = env_type;
    this->grain_amp = grain_amp;
    process_counter = 0;
    env_amp = 0.0f;
    env_shape = env_shape * 0.9f + 0.05f;
    env_skew = env_skew * 0.9f + 0.05f; 
    
    if (env_type == ENV_PARABOLIC) {
        float d = 1.0f / grain_dur;
        float d2 = d * d;
        slope = 4.0f * grain_amp * (d - d2);
        curve = -8.0f * grain_amp * d2;

    } else if (env_type == ENV_TRIANGLE) {
        triangle_midpoint = static_cast<int>(grain_dur * env_skew);
        triangle_attack_increment = grain_amp / triangle_midpoint;
        triangle_decay_increment = grain_amp / (grain_dur - triangle_midpoint);

    } else if (env_type == ENV_RCB) {
        // reduce skew for shorter grains
        env_skew = 0.5f + ((env_skew - 0.5f) * grain_dur_ratio);        
        // reduce sustain for shorter grains
        sustain_samples = static_cast<int>(env_shape * grain_dur_ratio * grain_dur);
        attack_samples = static_cast<int>(env_skew * (grain_dur - sustain_samples));
        release_samples = grain_dur - sustain_samples - attack_samples;
        attack_angle = pi;
        attack_angle_increment = pi / attack_samples;
        release_angle = 0.0f;
        release_angle_increment = pi / release_samples;
        release_boundary = attack_samples + sustain_samples;
    }
}

void Envelope::process(float* input, int sampleframes)
{
    switch(env_type) {
    case ENV_PARABOLIC:
        processParabolic(input, sampleframes);
        break;
    case ENV_TRIANGLE:
        processTriangle(input, sampleframes);
        break;
    case ENV_RCB:
        processRCB(input, sampleframes);
    }
}

void Envelope::processParabolic(float* input, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        env_amp += slope;
        slope += curve;
        input[i] *= env_amp;
    }
}

void Envelope::processTriangle(float* input, int sampleframes)
{
    int blockEnd = (process_counter + sampleframes);

    if (blockEnd < triangle_midpoint) {
        for (int i = 0; i < sampleframes; i++) {
            env_amp += triangle_attack_increment;
            input[i] *= env_amp;
        }
    } else if (process_counter >= triangle_midpoint
               && blockEnd < duration) {
        for (int i = 0; i < sampleframes; i++) {
            env_amp -= triangle_decay_increment;
            input[i] *= env_amp;
        }
    } else {
        processTriangleBoundary(input, sampleframes);
        return;
    }
    process_counter += sampleframes;
}

void Envelope::processTriangleBoundary(float* input, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        if (process_counter < triangle_midpoint) {
            env_amp += triangle_attack_increment;
        } else {
            env_amp -= triangle_decay_increment;
        }
        input[i] *= env_amp;
        process_counter++;
    }
}

void Envelope::processRCB(float* input, int sampleframes)
{
    int blockEnd = (process_counter + sampleframes);

    if (blockEnd < attack_samples) {
        for (int i = 0; i < sampleframes; i++) {
            input[i] *= grain_amp * (0.5f + 0.5f * fastCosine(attack_angle));
            attack_angle += attack_angle_increment;
        }
    } else if (process_counter >= attack_samples
               && blockEnd < release_boundary) {
        for (int i = 0; i < sampleframes; i++) {
            input[i] *= grain_amp;
        }
    } else if (process_counter >= release_boundary
               && blockEnd < duration) {
        for (int i = 0; i < sampleframes; i++) {
            input[i] *= grain_amp * (0.5f + 0.5f * fastCosine(release_angle));
            release_angle += release_angle_increment;
        }
    } else {
        processRCBBoundary(input, sampleframes);
        return;
    }
    process_counter += sampleframes;
}

void Envelope::processRCBBoundary(float* input, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        if (process_counter < attack_samples) {
            input[i] *= grain_amp * (0.5f + 0.5f * fastCosine(attack_angle));
            attack_angle += attack_angle_increment;
        } else if (process_counter < release_boundary) {
            input[i] *= grain_amp;
        } else {
            input[i] *= grain_amp * (0.5f + 0.5f * fastCosine(release_angle));
            release_angle += release_angle_increment;
        }
        process_counter++;
    }
}

inline float Envelope::fastCosine(float angle)
{
    angle += 1.57079632f;
    if (angle >  3.14159265f) {
        angle -= 6.28318531f;
    }
    if (angle < 0) {
        return 1.273239545f * angle + 0.405284735f * angle * angle;
    } else {
        return 1.273239545f * angle - 0.405284735f * angle * angle;
    }
}

