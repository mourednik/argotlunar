#include "DelayLine.h"

DelayLine::DelayLine(const int buffer_seconds, const int internal_block_size)
{
    this->buffer_seconds = buffer_seconds;
    this->internal_block_size = internal_block_size;
    highpass_filter = new Filter();
    initialized = false;
}

void DelayLine::initialize(float samplerate)
{
    deleteBuffers();
    delay_buffer_length = static_cast<int>(samplerate * buffer_seconds);
    delay_buffer = new float[delay_buffer_length + 3];
    feedback_buffer = new float[internal_block_size];
    highpass_filter->initializeHz(100.0f, 0.0f, FILTER_HIGH, samplerate);
    delay_buffer_start = 1;
    delay_write_pos = delay_buffer_start;
    delay_buffer_end = delay_buffer_length;
    feedback_write_pos = 0;
    initialized = true;

    for(int i = 0; i < (delay_buffer_length + 3); i++)
        delay_buffer[i] = 10E-12f;
    for (int i = 0; i < internal_block_size; i++)
        feedback_buffer[i] = 10E-12f;
}

DelayLine::~DelayLine()
{
    deleteBuffers();
    delete highpass_filter;
}

void DelayLine::deleteBuffers()
{
    if (!initialized)
        return;
    delete[] delay_buffer;
    delete[] feedback_buffer;
    initialized = false;
}

void DelayLine::writeDelayBuffer(float* chan1, float* chan2,
                                 int sampleframes, bool freeze, float input_gain, float feedback_gain)
{
    block_read_pos = delay_write_pos;

    if (freeze) {
        delay_write_pos += sampleframes;
        if (delay_write_pos > delay_buffer_length)
            delay_write_pos -= delay_buffer_length;

    } else {
        float sample;
        feedback_read_pos = feedback_write_pos;

        for (int i = 0; i < sampleframes; i++) {
            sample = (chan1[i] + chan2[i]) / 2.0f;
            sample *= input_gain;
            sample += feedback_gain * feedback_buffer[feedback_read_pos];

            delay_buffer[delay_write_pos] = sample;
            feedback_read_pos++;

            if (feedback_read_pos == internal_block_size) {
                feedback_read_pos = 0;
            }
            if (delay_write_pos == delay_buffer_start) {
                delay_buffer[delay_buffer_end + 1] = sample;
            } else if (delay_write_pos == (delay_buffer_start + 1)) {
                delay_buffer[delay_buffer_end + 2] = sample;
            } else if (delay_write_pos == delay_buffer_end) {
                delay_buffer[0] = sample;
                delay_write_pos = (delay_buffer_start - 1);
            }
            delay_write_pos++;
        }
    }
}

void DelayLine::writeFeedbackBuffer(float* chan1, float* chan2, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        feedback_buffer[feedback_write_pos++] = (chan1[i] + chan2[i]) / 2.0f;
        if (feedback_write_pos == internal_block_size)
            feedback_write_pos = 0;
    }
    highpass_filter->process(feedback_buffer, sampleframes);
}

int DelayLine::getDelayLength()
{
    return delay_buffer_length;
}

float* DelayLine::getDelayPointer()
{
    return delay_buffer;
}

/* Returns cached start-position of previously written block */
int DelayLine::getBlockReadPos()
{
    return block_read_pos;
}

