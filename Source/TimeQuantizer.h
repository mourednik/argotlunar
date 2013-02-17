#ifndef TIMEQUANTIZER_H
#define TIMEQUANTIZER_H

#include <map>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Misc.h"
#include "Parameters.h"
#include "ParametersEnum.h"

class Parameters;

class TimeQuantizer
{
public:
    TimeQuantizer(Parameters* parameters, const int internal_block_size);
    ~TimeQuantizer();
    void setPositionInfo(AudioPlayHead::CurrentPositionInfo* pos);
    void incrementPositionInfo();
    String getQuantModeString(const ParameterType parameter);
    String getQuantValueString(const ParameterType parameter, float value);
    void setQuantizeMode(const ParameterType parameter, const float value);
    const QuantizeMode getQuantizeMode(const ParameterType parameter);
    int quantizeLength(const ParameterType parameter, float value);
    int quantizeStartPos(const ParameterType parameter, float value);
    void setSampleRate(float samplerate);

private:
    void initialize();
    float getBarPos();
    float getQuantFactor(const QuantizeMode quantize_mode);
    int getQuantStepRange(const ParameterType parameter,
                          const QuantizeMode quantize_mode);
    int getQuantValue(const ParameterType parameter, float value);

    bool quantization_enabled;
    int internal_block_size;
    double prev_ppqpos;
    float pos_bpm;
    float pos_beatpos;
    float pos_seconds;
    float samplerate;
    float beatpos_increment;
    const Parameters* parameters;
    QuantizeMode delay_quant_mode;
    QuantizeMode iot_quant_mode;
    QuantizeMode dur_quant_mode;
    std::map<QuantizeMode, int> delay_quant_range;
    std::map<QuantizeMode, int> iot_quant_range;
    std::map<QuantizeMode, int> dur_quant_range;
    std::map<QuantizeMode, float> quant_factors;
    std::map<QuantizeMode, String> quant_mode_strings;
};

#endif //TIMEQUANTIZER_H
