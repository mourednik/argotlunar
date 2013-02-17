#ifndef ENVELOPE_H
#define ENVELOPE_H

#include <math.h>
#include "Debug.h"

enum EnvType {
    ENV_RCB,
    ENV_PARABOLIC,
    ENV_TRIANGLE
};

class Envelope
{
public:
    Envelope();
    void process(float* input, int sampleframes);
    void initialize(int env_type, int grain_dur, float grain_dur_ratio,
                    float env_shape, float env_skew, float grain_amp);

private:
    void processParabolic(float* input, int sampleframes);
    void processTriangle(float* input, int sampleframes);
    void processTriangleBoundary(float* input, int sampleframes);
    void processRCB(float* input, int sampleframes);
    void processRCBBoundary(float* input, int sampleframes);
    inline float fastCosine(float angle);

    float pi;
    float env_amp, grain_amp;
    int env_type;
    int process_counter;
    int duration;
    // parabolic
    float slope, curve;
    // raised cosine bell
    float attack_angle, attack_angle_increment, release_angle, release_angle_increment;
    int attack_samples, sustain_samples, release_samples, release_boundary;
    // triangle
    float triangle_attack_increment;
    float triangle_decay_increment;
    int triangle_midpoint;
};

#endif //ENVELOPE_H
