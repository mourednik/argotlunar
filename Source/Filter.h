#ifndef FILTER_H
#define FILTER_H

#include <math.h>
#include "Debug.h"

enum FilterMode {
    FILTER_OFF,
    FILTER_BAND,
    FILTER_LOW,
    FILTER_HIGH,
    FILTER_NOTCH,
    FILTER_COMB,
    FILTER_RANDOM
};

class Filter
{
public:
    Filter();
    void initialize(float freq_param, float q_param, int type, float samplerate);
    void initializeHz(float freq_hz, float q_param, int type, float samplerate);
    void process(float* input, int sampleframes);

private:
    inline void algorithm(float input);
    void processHigh(float* input, int sampleframes);
    void processLow(float* input, int sampleframes);
    void processBand(float* input, int sampleframes);
    void processNotch(float* input, int sampleframes);

    float pi, low, high, band, freq, q, scale;
    int type;
};

#endif
