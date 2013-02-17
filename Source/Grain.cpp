#include "Grain.h"

Grain::Grain(const float samplerate, const int buflen, const int internal_block_size,
             float* buffer, float* out1, float* out2)
{
    this->samplerate = samplerate;
    this->buflen = buflen;
    this->internal_block_size = internal_block_size;
    this->buffer = buffer;
    this->out1 = out1;
    this->out2 = out2;
    activated = false;
    initialized = false;
    marked_for_deactivation = false;
    comb_filter = new CombFilter(samplerate);
    env = new Envelope();
    multimode_filter = new Filter();
    output_buffer = new float[internal_block_size];
}

Grain::~Grain()
{
    delete comb_filter;
    delete env;
    delete multimode_filter;
    delete[] output_buffer;
}

void Grain::activate()
{
    activated = true;
    initialized = false;
    marked_for_deactivation = false;
}

void Grain::deactivate()
{
    if (initialized) {
        marked_for_deactivation = true;
    } else {
        activated = false;
    }
}

inline void Grain::incrementReadPos()
{
    delaybuf_readpos_int++;
    if (delaybuf_readpos_int > buflen)
        delaybuf_readpos_int -= buflen;
}

inline void Grain::incrementReadPosFrac()
{
    delaybuf_readpos_float += trans;
    delaybuf_readpos_int = static_cast<int>(delaybuf_readpos_float);
    if (delaybuf_readpos_int > buflen) {
        delaybuf_readpos_float -= buflen;
        delaybuf_readpos_int = static_cast<int>(delaybuf_readpos_float);
    }
    trans += gliss;
}

void Grain::initialize(const GrainParameters& grain_parameters)
{
    amp = grain_parameters.amp;
    delaybuf_readpos_int = grain_parameters.bufstart;
    delaybuf_readpos_float = static_cast<float>(grain_parameters.bufstart);
    duration = grain_parameters.duration;
    filter_type = grain_parameters.filter_type;
    gliss = grain_parameters.gliss;
    gliss_enabled = (gliss == 0.0f) ? false : true;
    iot = grain_parameters.iot;
    pan_left = grain_parameters.pan;
    pan_right = 1.0f - grain_parameters.pan;
    trans = grain_parameters.trans;

    switch(filter_type) {
    case FILTER_OFF:
        break;
    case FILTER_COMB:
        comb_filter->initialize(grain_parameters.ffreq, grain_parameters.fq);
        break;
    default:
        multimode_filter->initialize(grain_parameters.ffreq,grain_parameters.fq,
                                     filter_type, samplerate);
        break;
    }

    env->initialize(grain_parameters.env_type,
                    duration,
                    grain_parameters.duration_ratio,
                    grain_parameters.env_shape,
                    grain_parameters.env_skew,
                    amp);

    for (int i = 0; i < internal_block_size; i++)
        output_buffer[i] = 10E-12f;

    process_counter = 0;
    initialized = true;
}

void Grain::process(int sampleframes)
{
    if (iot > 0) {
        iot -= sampleframes;
        if (iot < 0) {
            sampleframes = -iot;
        } else {
            return;
        }
    }

    int block_end = process_counter + sampleframes;
    if (block_end <= duration) {
        readBuffer(sampleframes);
    } else {
        int intrablock_offset = duration - process_counter;
        readBuffer(intrablock_offset);
	for (int i = sampleframes; i < internal_block_size; i++) {
	    output_buffer[i] = 10E-12f;
	}
        if (marked_for_deactivation) {
            activated = false;
            marked_for_deactivation = false;
        }
        initialized = false;
        return;
    }

    if (filter_type != FILTER_OFF && filter_type != FILTER_COMB)
        multimode_filter->process(output_buffer, sampleframes);

    env->process(output_buffer, sampleframes);

    // comb filter generally sounds better post-envelope
    if (filter_type == FILTER_COMB)
        comb_filter->process(output_buffer, sampleframes);

    for (int i = 0; i < sampleframes; i++) {
        out1[i] += (output_buffer[i] * pan_right);
        out2[i] += (output_buffer[i] * pan_left);
    }
}

void Grain::readBuffer(int sampleframes)
{
    if ((trans != 1.0f) || gliss_enabled) {
        for (int i = 0; i < sampleframes; i++) {
            output_buffer[i] = cubicInterpolation(
                                   (delaybuf_readpos_float - delaybuf_readpos_int),
                                   buffer[delaybuf_readpos_int - 1],
                                   buffer[delaybuf_readpos_int],
                                   buffer[delaybuf_readpos_int + 1],
                                   buffer[delaybuf_readpos_int + 2]);
            incrementReadPosFrac();
        }
    } else {
        for (int i = 0; i < sampleframes; i++) {
            output_buffer[i] = buffer[delaybuf_readpos_int];
            incrementReadPos();
        }
    }
    process_counter += sampleframes;
}

inline float Grain::cubicInterpolation(float frac, float y0, float y1, float y2, float y3)
{
    c1 = 0.5f * (y2 - y0);
    c3 = 1.5f * (y1 - y2) + 0.5f * (y3 - y0);
    c2 = y0 - y1 + c1 - c3;
    return ((c3 * frac + c2) * frac + c1) * frac + y1;
}
