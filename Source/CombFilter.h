#ifndef COMBFILTER_H
#define COMBFILTER_H

#include <math.h>
#include "Debug.h"

class CombFilter
{
public:
    CombFilter(float samplerate);
    ~CombFilter();
    void initialize(float freq_param, float q_param);
    void process(float* input, int sampleframes);

private:
    inline void processSample(float* input);

    float *buffer;
    float delaysample;
    float output;
    float samplerate;
    float ramp_increment;
    float ramp;
    float resonance;
    int rampsamples;
    int delay;
    int buflen;
    int delay_buf_write_pos, buf_read_pos;
    int process_counter;
};

#endif //COMBFILTER_H
