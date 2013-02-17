#ifndef PARAMETERS_H
#define PARAMETERS_H

class Plugin;

#include <math.h>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"
#include "Filter.h"
#include "Misc.h"
#include "Plugin.h"
#include "ParametersEnum.h"
#include "TimeQuantizer.h"

class TimeQuantizer;

class Parameters
{
public:
    Parameters(Plugin* plugin, const int internal_block_size);
    ~Parameters();
    void initializeInternalParameters();
    const String getParameterName(int index);
    const String getParameterText(int index);
    void setParameter(int index, float new_value, bool initializing);
    float getParameterFloatValue(ParameterType param_index);
    float getDelayMilliseconds(float value);
    float getIOTMilliseconds(float value);
    float getDurMilliseconds(float value);
    int getScale();
    void setScale(int index);
    int getMatrixSource(int index);
    int getMatrixDest(int index);
    int getMatrixMode(int index);
    void setMatrixSource(int index, int param);
    void setMatrixDest(int index, int param);
    void setMatrixMode(int index, int param);
    void setSampleRate(float samplerate);
    float getSampleRate();
    void setQuantizationDisabled();

    static const int kMaxIot = 2000;
    static const int kMaxDuration = 5;

    ModSource matrix_source[3];
    ModDest matrix_dest[3];
    ModMode matrix_mode[3];
    float *param;
    float dry_mix;
    int scale;
    int selected_grains;
    bool freeze;
    int filter_type;
    int env_type;
    int scale_key;
    float amp_max;
    float pan_min, pan_max;
    float delay_max;
    float iot_max;
    float dur_max;
    float trans_min, trans_max;
    float gliss_min, gliss_max;
    float ffreq_max;
    float fq_max;
    float samplerate;
    TimeQuantizer* time_quantizer;

private:
    String getEnvTypeString();
    String getEnvSkewString();
    String getEnvSustainString();
    String getFilterTypeString();
    String getScaleKeyString();
    String getNumGrainsString();    
    String getMatrixmodString(int parameter);
    String getDecibelString(float value);
    String getToggleString(int parameter);
    String getPanString(float value);
    String getDelayString(float value);
    String getIOTString(float value);
    String getDurString(float value);
    String getTransString(float value);
    String getGlissString(float value);
    String getFFreqString(float value);
    String getFqString(float value);
    String getPercentString(float value);
    void setParametersSavedState(bool state);

    bool quantization_disabled;
    float delay_coeff;
    float iot_coeff;
    float dur_coeff;
    Plugin* plugin;
};

#endif //PARAMETERS_H
