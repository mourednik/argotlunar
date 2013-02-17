#ifndef GRAIN_H
#define GRAIN_H

#include "../JuceLibraryCode/JuceHeader.h"
#include "Debug.h"
#include "CombFilter.h"
#include "Envelope.h"
#include "Filter.h"
#include "GrainParameters.h"
#include "Misc.h"

class Grain
{
public:
    Grain(const float samplerate, const int buflen, const int internal_block_size,
          float* buffer, float* out1, float* out2);
    ~Grain();
    void initialize(const GrainParameters& grain_parameters);
    void process(int sampleframes);
    void activate();
    void deactivate();

    bool activated, initialized;
    int iot;
    bool finished_processing;

private:
    void readBuffer(int sampleframes);
    inline void incrementReadPos();
    inline void incrementReadPosFrac();
    inline float cubicInterpolation(float frac, float y0, float y1, float y2, float y3);

    int internal_block_size;
    int duration, env_type, process_counter, buflen, buf_end, filter_type, delaybuf_readpos_int;
    float amp, pan_left, pan_right, trans, gliss, delaybuf_readpos_float, env_amp;
    float *output_buffer;
    float frac, c1, c2, c3; // interpolation
    float *buffer, *out1, *out2;
    float samplerate;
    bool gliss_enabled;
    bool marked_for_deactivation;
    Filter* multimode_filter;
    CombFilter* comb_filter;
    Envelope* env;
};

#endif //GRAIN_H
