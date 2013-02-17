#include "CombFilter.h"

CombFilter::CombFilter(float samplerate)
{
    this->samplerate = samplerate;
    buflen = (int)(samplerate / 22.0f);
    buffer = new float[buflen];
    rampsamples = (int)(samplerate / 1000.0f); // initial 1ms ramp to avoid clicks
    ramp_increment = 1.0f / rampsamples;
}

CombFilter::~CombFilter()
{
    delete[] buffer;
}

// accepts params between 0.0f - 1.0f
void CombFilter::initialize(float freq_param, float q_param)
{
    float freq_hz = pow(10.0f, freq_param * 3.0f) * 22.05f;
    delay = (int)((1.0f / freq_hz) * samplerate);
    resonance = q_param;
    buf_read_pos = buflen - delay;

    if (buf_read_pos == buflen) {
        buf_read_pos = 0;
    }
    for(int i = 0; i < buflen; i++) {
        buffer[i] = 10E-12f;
    }

    delay_buf_write_pos = 0;
    process_counter = 0;
    ramp = 0.0f;
}

void CombFilter::process(float* input, int sampleframes)
{
    if ((delay_buf_write_pos + sampleframes) < buflen
            && (buf_read_pos + sampleframes) < buflen
            && (process_counter + sampleframes) > rampsamples) {
        for (int i = 0; i < sampleframes; i++) {
            processSample(&input[i]);
        }
    } else {
        for (int i = 0; i < sampleframes; i++) {
            processSample(&input[i]);
            if (delay_buf_write_pos == buflen) {
                delay_buf_write_pos = 0;
            }
            if (buf_read_pos == buflen) {
                buf_read_pos = 0;
            }
            if (process_counter < rampsamples) {
                process_counter++;
                ramp += ramp_increment;
            }
        }
    }
}
/*
inline void CombFilter::processSample(float* input)
{
  buffer[delay_buf_write_pos] = *input * resonance * ramp;
  *input = (*input * 0.5f) + (buffer[buf_read_pos] * 0.5f);
  delay_buf_write_pos++;
  buf_read_pos++;
  process_counter++;
}
*/
inline void CombFilter::processSample(float* input)
{
    *input = *input + buffer[buf_read_pos] * resonance;
    buffer[delay_buf_write_pos] = *input ;
    delay_buf_write_pos++;
    buf_read_pos++;
    process_counter++;
}
