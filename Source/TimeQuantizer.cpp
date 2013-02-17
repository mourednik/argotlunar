#include "TimeQuantizer.h"

TimeQuantizer::TimeQuantizer(Parameters* parameters,
                             const int internal_block_size)
{
    this->parameters = parameters;
    this->internal_block_size = internal_block_size;
    initialize();
}

TimeQuantizer::~TimeQuantizer()
{
}

void TimeQuantizer::initialize()
{
    delay_quant_range[QUANT_128] = 64;
    delay_quant_range[QUANT_128T] = 96;
    delay_quant_range[QUANT_64] = 64;
    delay_quant_range[QUANT_64T] = 96;
    delay_quant_range[QUANT_32] = 64;
    delay_quant_range[QUANT_32T] = 96;
    delay_quant_range[QUANT_16] = 32;
    delay_quant_range[QUANT_16T] = 48;
    delay_quant_range[QUANT_8] = 16;
    delay_quant_range[QUANT_8T] = 24;
    delay_quant_range[QUANT_4] = 8;
    delay_quant_range[QUANT_4T] = 12;

    iot_quant_range[QUANT_128] = 32;
    iot_quant_range[QUANT_128T] = 48;
    iot_quant_range[QUANT_64] = 32;
    iot_quant_range[QUANT_64T] = 48;
    iot_quant_range[QUANT_32] = 32;
    iot_quant_range[QUANT_32T] = 48;
    iot_quant_range[QUANT_16] = 16;
    iot_quant_range[QUANT_16T] = 24;
    iot_quant_range[QUANT_8] = 8;
    iot_quant_range[QUANT_8T] = 12;
    iot_quant_range[QUANT_4] = 4;
    iot_quant_range[QUANT_4T] = 6;

    dur_quant_range[QUANT_128] = 32;
    dur_quant_range[QUANT_128T] = 48;
    dur_quant_range[QUANT_64] = 32;
    dur_quant_range[QUANT_64T] = 48;
    dur_quant_range[QUANT_32] = 32;
    dur_quant_range[QUANT_32T] = 48;
    dur_quant_range[QUANT_16] = 16;
    dur_quant_range[QUANT_16T] = 24;
    dur_quant_range[QUANT_8] = 8;
    dur_quant_range[QUANT_8T] = 12;
    dur_quant_range[QUANT_4] = 4;
    dur_quant_range[QUANT_4T] = 6;

    quant_mode_strings[QUANT_MS] = "ms";
    quant_mode_strings[QUANT_128] = "/128";
    quant_mode_strings[QUANT_128T] = "/128T";
    quant_mode_strings[QUANT_64] = "/64";
    quant_mode_strings[QUANT_64T] = "/64T";
    quant_mode_strings[QUANT_32] = "/32";
    quant_mode_strings[QUANT_32T] = "/32T";
    quant_mode_strings[QUANT_16] = "/16";
    quant_mode_strings[QUANT_16T] = "/16T";
    quant_mode_strings[QUANT_8] = "/8";
    quant_mode_strings[QUANT_8T] = "/8T";
    quant_mode_strings[QUANT_4] = "/4";
    quant_mode_strings[QUANT_4T] = "/4T";
    quant_mode_strings[QUANT_MS_LONG] = "long";

    quant_factors[QUANT_128] = 1.0f/128.0f;
    quant_factors[QUANT_128T] = 1.0f/196.0f;
    quant_factors[QUANT_64] = 1.0f/64.0f;
    quant_factors[QUANT_64T] = 1.0f/96.0f;
    quant_factors[QUANT_32] = 1.0f/32.0f;
    quant_factors[QUANT_32T] = 1.0f/48.0f;
    quant_factors[QUANT_16] = 1.0f/16.0f;
    quant_factors[QUANT_16T] = 1.0f/24.0f;
    quant_factors[QUANT_8] = 1.0f/8.0f;
    quant_factors[QUANT_8T] = 1.0f/12.0f;
    quant_factors[QUANT_4] = 1.0f/4.0f;
    quant_factors[QUANT_4T] = 1.0f/6.0f;

    pos_bpm = 0.0f;
    pos_beatpos = 0.0f;
    pos_seconds = 0.0f;
    beatpos_increment = 0.0f;
    samplerate = 0.0f;
    quantization_enabled = false;
    prev_ppqpos = 0.0;
}

int TimeQuantizer::getQuantStepRange(const ParameterType parameter,
                                     const QuantizeMode quantize_mode)
{
    switch (parameter) {
    case kDelayQuant:
        return delay_quant_range[quantize_mode];
    case kIotQuant:
        return iot_quant_range[quantize_mode];
    case kDurQuant:
    default:
        return dur_quant_range[quantize_mode];
    }
}

float TimeQuantizer::getQuantFactor(const QuantizeMode quantize_mode)
{
    return quant_factors[quantize_mode];
}

void TimeQuantizer::setQuantizeMode(const ParameterType parameter,
                                    const float value)
{
    switch (parameter) {
    case kDelayQuant:
        delay_quant_mode = static_cast<QuantizeMode>(
                               MathFunc::roundFtoI(value * NumQuantModes::delay));
        if(delay_quant_mode == 0)
            delay_quant_mode = QUANT_MS;
        return;
    case kIotQuant:
        iot_quant_mode = static_cast<QuantizeMode>(
                             MathFunc::roundFtoI(value * NumQuantModes::iot));
        if(iot_quant_mode == 0)
            iot_quant_mode = QUANT_MS;
        return;
    case kDurQuant:
    default:
        dur_quant_mode = static_cast<QuantizeMode>(
                             MathFunc::roundFtoI(value * NumQuantModes::dur));
        if(dur_quant_mode == 0)
            dur_quant_mode = QUANT_MS;
    }
}

const QuantizeMode TimeQuantizer::getQuantizeMode(const ParameterType parameter)
{
    switch (parameter) {
    case kDelayQuant:
        return delay_quant_mode;
    case kIotQuant:
        return iot_quant_mode;
    case kDurQuant:
    default:
        return dur_quant_mode;
    }
}

int TimeQuantizer::getQuantValue(const ParameterType parameter, float value)
{
    int quant_value = 0;

    switch (parameter) {
    case kDelayQuant:
        quant_value =
            MathFunc::roundFtoI(value * delay_quant_range[delay_quant_mode]);
        break;
    case kIotQuant:
        quant_value =
            MathFunc::roundFtoI(value * iot_quant_range[iot_quant_mode]);
        break;
    case kDurQuant:
    default:
        quant_value =
            MathFunc::roundFtoI(value * dur_quant_range[dur_quant_mode]);
    }
    if (quant_value == 0)
        quant_value++;
    return quant_value;
}

String TimeQuantizer::getQuantModeString(const ParameterType parameter)
{
    switch (parameter) {
    case kDelayQuant:
        return quant_mode_strings[delay_quant_mode];
    case kIotQuant:
        return quant_mode_strings[iot_quant_mode];
    case kDurQuant:
    default:
        return quant_mode_strings[dur_quant_mode];
    }
}

String TimeQuantizer::getQuantValueString(const ParameterType parameter,
        float value)
{
    return String(getQuantValue(parameter, value))
           + getQuantModeString(parameter);
}

float TimeQuantizer::getBarPos()
{
    float secondsPerBar = 60.0f / (pos_bpm / 4.0f);
    float barPos = (pos_seconds / secondsPerBar);
    barPos = barPos - static_cast<int>(barPos);
    return barPos;
}

int TimeQuantizer::quantizeLength(const ParameterType parameter, float value)
{
    int quant_steps = getQuantValue(parameter, value);
    float quant_factor = getQuantFactor(getQuantizeMode(parameter));
    float bar_length = 60.0f / (pos_bpm / 4.0f);
    int bar_samples = static_cast<int>(bar_length * samplerate);
    float quant_step_samples = bar_samples * quant_factor;
    return MathFunc::roundFtoI(quant_step_samples * quant_steps);
}

// finds distance (in samples) to nearest quantize boundary
// adds quant_steps * samples_per_quant_step to distance
int TimeQuantizer::quantizeStartPos(const ParameterType parameter, float value)
{
    int quant_steps = getQuantValue(parameter, value) - 1;
    float quant_factor = getQuantFactor(getQuantizeMode(parameter));
    float bar_length = 60.0f / (pos_bpm / 4.0f);
    int bar_samples = static_cast<int>(bar_length * samplerate);
    float samples_per_quant_step = bar_samples * quant_factor;
    float distance = getBarPos() / quant_factor;
    distance = ceil(distance) - distance;
    distance *= samples_per_quant_step;
    distance += (quant_steps * samples_per_quant_step);
    return MathFunc::roundFtoI(distance);
}

void TimeQuantizer::setSampleRate(float samplerate)
{
    this->samplerate = samplerate;
}

void TimeQuantizer::setPositionInfo(AudioPlayHead::CurrentPositionInfo* pos)
{
    quantization_enabled = true;
    pos_bpm = static_cast<float>(pos->bpm);
    pos_seconds = static_cast<float>(pos->timeInSeconds);
    pos_beatpos = static_cast<float>(pos->ppqPosition
                                     - pos->ppqPositionOfLastBarStart);
    beatpos_increment = (internal_block_size / samplerate) * (pos_bpm / 60.0f);
}

void TimeQuantizer::incrementPositionInfo()
{
    if (!quantization_enabled)
        return;
    pos_seconds += (internal_block_size / samplerate);
    pos_beatpos += beatpos_increment;
    if (pos_beatpos > 1.0f)
        pos_beatpos -= 1.0f;
}

