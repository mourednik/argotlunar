#ifndef DELAYLINE_H
#define DELAYLINE_H

#include "Debug.h"
#include "Filter.h"

class DelayLine
{
public:
    DelayLine(const int buffer_seconds, const int internal_block_size);
    ~DelayLine();
    int getBlockReadPos();
    int getDelayLength();
    float* getDelayPointer();
    void initialize(float samplerate);
    void writeFeedbackBuffer(float* chan1, float* chan2, int sampleframes);
    void writeDelayBuffer(float* chan1, float* chan2, int sampleframes,
                          bool freeze, float input_gain, float feedback_gain);

private:
    void deleteBuffers();

    Filter* highpass_filter;
    float *delay_buffer;
    float *feedback_buffer;
    int delay_buffer_length;
    int delay_buffer_start;
    int delay_buffer_end;
    int delay_write_pos;
    int block_read_pos;
    int feedback_write_pos;
    int feedback_read_pos;
    int buffer_seconds;
    int internal_block_size;
    bool initialized;
};

#endif //DELAYLINE_H
