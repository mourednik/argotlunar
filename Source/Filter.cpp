#include "Filter.h"


Filter::Filter()
{
    pi = 4.0f * atan(1.0f);
}

// valid params between 0.0f - 1.0f
void Filter::initialize(float freq_param, float q_param, int type, float samplerate)
{
    float freq_hz = pow(10.0f, freq_param * 3.0f) * 22.05f;
    freq = sin(pi * freq_hz / samplerate);
    q = sqrt(1.0f - atan(sqrt(100.0f * q_param)) * 2.0f / pi);
    scale = sqrt(q);
    low = high = band = 0.0f;
    this->type = type;
}

// valid freq_hz between 22.05f - 22050.0f
void Filter::initializeHz(float freq_hz, float q_param, int type, float samplerate)
{
    freq = sin(pi * freq_hz / samplerate);
    q = sqrt(1.0f - atan(sqrt(100.0f * q_param)) * 2.0f / pi);
    scale = sqrt(q);
    low = high = band = 0.0f;
    this->type = type;
}

void Filter::process(float* input, int sampleframes)
{
    switch (type) {
    case FILTER_BAND:
        processBand(input, sampleframes);
        return;
    case FILTER_LOW:
        processLow(input, sampleframes);
        return;
    case FILTER_HIGH:
        processHigh(input, sampleframes);
        return;
    case FILTER_NOTCH:
        processNotch(input, sampleframes);
        return;
    }
}

inline void Filter::algorithm(float input)
{
    // 2x oversampling
    low = low + freq * band;
    high = scale * input - low - q * band;
    band = freq * high + band;

    low = low + freq * band;
    high = scale * input - low - q * band;
    band = freq * high + band;
}

void Filter::processBand(float* input, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        algorithm(input[i]);
        input[i] = band;
    }
}

void Filter::processLow(float* input, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        algorithm(input[i]);
        input[i] = low;
    }
}

void Filter::processHigh(float* input, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        algorithm(input[i]);
        input[i] = high;
    }
}

void Filter::processNotch(float* input, int sampleframes)
{
    for (int i = 0; i < sampleframes; i++) {
        algorithm(input[i]);
        input[i] = high + low;
    }
}

