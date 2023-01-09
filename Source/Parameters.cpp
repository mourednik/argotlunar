#include "Parameters.h"

Parameters::Parameters(Plugin* plugin, const int internal_block_size)
{
    this->plugin = plugin;
    time_quantizer = new TimeQuantizer(this, internal_block_size);
    delay_coeff = sqrt(plugin->granulator->kBufferSeconds * 1000.0f);
    iot_coeff = log10(kMaxIot * 1.0f);
    dur_coeff = log10(kMaxDuration * 1.0f);
    param = new float[NUM_PARAMS];
    for (int i = 0; i < NUM_PARAMS; i++) {
        param[i]= 0.0f;
    }
    setParametersSavedState(true);
    quantization_disabled = false;
}

Parameters::~Parameters()
{
    delete[] param;
    delete time_quantizer;    
}

void Parameters::initializeInternalParameters()
{
    for (int i = 0; i < (NUM_PARAMS - 2); i++) {
        setParameter(i, param[i], true);
    }
    setParametersSavedState(true);
}

float Parameters::getParameterFloatValue(ParameterType param_index)
{
    return param[param_index];
}

void Parameters::setParameter(int index, float new_value, bool initializing)
{
    if (param[index] != new_value || initializing == true) {
        param[index] = new_value;
        
        switch(index) {
        case kGrains:
            selected_grains = MathFunc::roundFtoI(
                    new_value * plugin->granulator->kMaxGrains);
            break;            
        case kMix:
            dry_mix = 1.0f - new_value;
            break;
        case kAmp:
        case kAmpv:
            amp_max = param[kAmp] + param[kAmpv];
            if (amp_max > 1.0f)
                amp_max = 1.0f;
            break;
        case kPan:
        case kPanv:
            pan_min = param[kPan] - (0.5f * param[kPanv]);
            pan_max = param[kPan] + (0.5f * param[kPanv]);
            if (pan_min < 0.0f)
                pan_min = 0.0f;
            if (pan_max > 1.0f)
                pan_max = 1.0f;
            break;
        case kDelay:
        case kDelayv:
            delay_max = param[kDelay] + param[kDelayv];
            if (delay_max > 1.0f)
                delay_max = 1.0f;
            break;
        case kIot:
        case kIotv:
            iot_max = param[kIot] + param[kIotv];
            if (iot_max > 1.0f)
                iot_max = 1.0f;
            break;
        case kDur:
        case kDurv:
            dur_max = param[kDur] + param[kDurv];
            if (dur_max > 1.0f)
                dur_max = 1.0f;
            break;
        case kTrans:
        case kTransv:
            trans_min = param[kTrans] - (0.5f * param[kTransv]);
            trans_max = param[kTrans] + (0.5f * param[kTransv]);
            if (trans_min < 0.0f)
                trans_min = 0.0f;
            if (trans_max > 1.0f)
                trans_max = 1.0f;
            break;
        case kGliss:
        case kGlissv:
            gliss_min = param[kGliss] - (0.5f * param[kGlissv]);
            gliss_max = param[kGliss] + (0.5f * param[kGlissv]);
            if (gliss_min < 0.0f)
                gliss_min = 0.0f;
            if (gliss_max > 1.0f)
                gliss_max = 1.0f;
            break;
        case kFtype:
            filter_type = MathFunc::roundFtoI(new_value * 6.0f);
            break;            
        case kFfreq:
        case kFfreqv:
            ffreq_max = param[kFfreq] + param[kFfreqv];
            if (ffreq_max > 1.0f)
                ffreq_max = 1.0f;
            break;
        case kFq:
        case kFqv:
            fq_max = param[kFq] + param[kFqv];
            if (fq_max > 1.0f)
                fq_max = 1.0f;
            break;
        case kEnvType:
            env_type = MathFunc::roundFtoI(new_value * 2.0f);
            break;
            /*
        case kEnvSustain:            
            if (param[kEnvSustain] < 0.05f) {
                param[kEnvSustain] = 0.05f;
            } else if (param[kEnvSustain] > 0.95f) {
                param[kEnvSustain] = 0.95f;
            }
            break;            
        case kEnvSkew:
            if (param[kEnvSkew] < 0.05f) {
                param[kEnvSkew] = 0.05f;
            } else if (param[kEnvSkew] > 0.95f) {
                param[kEnvSkew] = 0.95f;
            }
            break;
            */
        case kDelayQuant:
            if (quantization_disabled)
                param[kDelayQuant] = 1.0f/NumQuantModes::delay;
            time_quantizer->setQuantizeMode(kDelayQuant, param[kDelayQuant]);
            break;
        case kIotQuant:
            if (quantization_disabled)
                param[kIotQuant] = 1.0f/NumQuantModes::iot;
            time_quantizer->setQuantizeMode(kIotQuant, param[kIotQuant]);
            break;
        case kDurQuant:
            if (quantization_disabled)
                param[kDurQuant] = 1.0f/NumQuantModes::dur;
            time_quantizer->setQuantizeMode(kDurQuant, param[kDurQuant]);
            break;
        case kFreezeToggle:
            freeze = (new_value == 0.0f) ? false : true;
            break;            
        case kScaleKey:
            // Should be 'new_value * 11'. Keeping '12' to maintain compatibility
            scale_key = MathFunc::roundFtoI(new_value * 12); 
            if(scale_key == 12) scale_key--;
            break;
        }
        if (initializing == false) {
            setParametersSavedState(false);
        }
    }
}

const String Parameters::getParameterName(int index)
{
    switch (index) {
    case kGrains:
        return "grains";        
    case kMix:
        return "mix";
    case kIngain:
        return "input_gain";
    case kFeedback:
        return "feedback";        
    case kAmp:
        return "amp";
    case kAmpv:
        return "ampv";
    case kPan:
        return "pan";
    case kPanv:
        return "panv";
    case kDelay:
        return "delay";
    case kDelayv:
        return "delayv";
    case kTrans:
        return "trans";
    case kTransv:
        return "transv";
    case kGliss:
        return "gliss";
    case kGlissv:
        return "glissv";
    case kIot:
        return "IOT";
    case kIotv:
        return "IOTv";
    case kDur:
        return "dur";
    case kDurv:
        return "durv";
    case kFtype:
        return "filter_type";        
    case kFfreq:
        return "ffreq";
    case kFfreqv:
        return "ffreqv";
    case kFq:
        return "fq";
    case kFqv:
        return "fqv";
    case kEnvType:
        return "env_type";        
    case kEnvSustain:
        return "env_sustain";
    case kEnvSkew:
        return "env_skew";
    case kDelayQuant:
        return "delay_quantize";
    case kDurQuant:
        return "dur_quantize";
    case kIotQuant:
        return "IOT_quantize";
    case kTransToggle:
        return "trans_toggle";
    case kGlissToggle:
        return "gliss_toggle";
    case kFreezeToggle:
        return "freeze_toggle";
    case kScaleKey:
        return "scale_key";
    case kMatrixMod1:
        return "matrix_mod_1";
    case kMatrixMod2:
        return "matrix_mod_2";
    case kMatrixMod3:
        return "matrix_mod_3";
    case kProgram:
        return "program";
    }
    return String();
}

const String Parameters::getParameterText(int index)
{
    String text;
    switch (index) {
    case kMix:
        return String(dry_mix, 2) + " dry | " + String(param[kMix], 2) + " wet";
    case kIngain:
        return getDecibelString(param[kIngain]);
    case kFeedback:
        return getDecibelString(param[kFeedback]);
    case kAmp:
    case kAmpv:
        if (param[kAmp] == amp_max) {
            return getDecibelString(param[kAmp]);
        } else {
            return getDecibelString(param[kAmp]) + ", " + getDecibelString(amp_max);
        }
    case kPan:
    case kPanv:
        if (pan_min == pan_max) {
            return getPanString(pan_min);
        } else {
            return getPanString(pan_min) + ", " + getPanString(pan_max);
        }
    case kDelay:
    case kDelayv:
        if (param[kDelay] == delay_max) {
            return getDelayString(param[kDelay]);
        } else {
            return getDelayString(param[kDelay]) + ", " + getDelayString(delay_max);
        }
    case kIot:
    case kIotv:
        if (param[kIot] == iot_max) {
            return getIOTString(param[kIot]);
        } else {
            return getIOTString(param[kIot]) + ", " + getIOTString(iot_max);
        }
    case kDur:
    case kDurv:
        if (param[kDur] == dur_max) {
            return getDurString(param[kDur]);
        } else {
            return getDurString(param[kDur]) + ", " + getDurString(dur_max);
        }
    case kTrans:
    case kTransv: {
        if (trans_min == trans_max) {
            return getTransString(trans_min);
        } else {
            text = getTransString(trans_min) + ", " + getTransString(trans_max);
            if (index == kTransv)
                text += " [+- " + String(static_cast<int>(param[kTransv] * 2400.0f)) + " c.]";
            return text;
        }
    }
    case kGliss:
    case kGlissv: {
        if (gliss_min == gliss_max) {
            return getGlissString(gliss_min);
        } else {
            text = getGlissString(gliss_min) + ", " + getGlissString(gliss_max);
            if (index == kGlissv)
                text += " [+- " + String(static_cast<int>(param[kGlissv] * 2400.0f)) + " c.]";
            return text;
        }
    }
    case kFfreq:
    case kFfreqv:
        if (param[kFfreq] == ffreq_max) {
            return getFFreqString(param[kFfreq]);
        } else {
            return getFFreqString(param[kFfreq]) + ", " + getFFreqString(ffreq_max);
        }
    case kFq:
    case kFqv:
        if (param[kFq] == fq_max) {
            return getFqString(param[kFq]);            
        } else {
            return getFqString(param[kFq]) + ", " + getFqString(fq_max);
        }
    case kFtype:
        return getFilterTypeString();
    case kEnvSustain:
        return getEnvSustainString();
    case kEnvSkew:
        return getEnvSkewString();
    case kEnvType:
        return getEnvTypeString();
    case kTransToggle:
        return getToggleString(kTransToggle);
    case kGlissToggle:
        return getToggleString(kGlissToggle);
    case kFreezeToggle:
        return getToggleString(kFreezeToggle);
    case kGrains:
        return getNumGrainsString();
    case kScaleKey:
        return getScaleKeyString();
    case kMatrixMod1:
        return getMatrixmodString(kMatrixMod1);
    case kMatrixMod2:
        return getMatrixmodString(kMatrixMod2);
    case kMatrixMod3:
        return getMatrixmodString(kMatrixMod3);
    case kDelayQuant:
        return time_quantizer->getQuantModeString(kDelayQuant);
    case kDurQuant:
        return time_quantizer->getQuantModeString(kDurQuant);
    case kIotQuant:
        return time_quantizer->getQuantModeString(kIotQuant);
    }
    return "";
}

void Parameters::setQuantizationDisabled()
{
    quantization_disabled = true;
}

String Parameters::getEnvSustainString()
{
    return String(param[kEnvSustain] * 100.0f, 1);
}

String Parameters::getEnvSkewString()
{
    float skew = (param[kEnvSkew] - 0.5f) * 200.0f;
    if (skew <= 0.0f) {
        return String(skew, 1);
    } else {
        return "+" + String(skew,1);
    }
}

String Parameters::getNumGrainsString()
{
    return String(MathFunc::roundFtoI(param[kGrains]
                                      * plugin->granulator->kMaxGrains)) + " grains";
}

String Parameters::getFqString(float value)
{
    return String(value, 2) + " Q";
}

String Parameters::getPercentString(float value)
{
    return String(value * 100, 1) + "% ";
}

String Parameters::getEnvTypeString()
{
    String types[] = {"raised cosine bell", "parabola", "triangle"};
    int index = MathFunc::roundFtoI(param[kEnvType] * 2.0f);
    return types[index];
}

String Parameters::getFilterTypeString()
{
    String types[] = {"off", "band", "low", "high", "notch", "comb", "random"};
    int index = MathFunc::roundFtoI(param[kFtype] * 6.0f);
    return types[index];
}

String Parameters::getScaleKeyString()
{
    String keys[] = {"C", "C#", "D", "D#", "E", "F",
                     "F#", "G", "G#", "A", "A#", "B"
                    };
    return keys[scale_key];
}

String Parameters::getMatrixmodString(int parameter)
{
    if (param[parameter] > 0.5f) {
        return "+" + String((int)((param[parameter] - 0.5f) * 200.0f)) + "%";
    } else if (param[parameter] < 0.5f) {
        return String((int)((param[parameter] - 0.5f) * 200.0f)) + "%";
    } else {
        return "0%";
    }
}

String Parameters::getDecibelString(float value)
{
    if (value < 0.006f) {
        return "-inf";
    } else {
        return String(log10(pow(value, 20)), 1) + " dB";
    }
}

String Parameters::getToggleString(int parameter)
{
    return (param[parameter] == 0.0f) ? "off" : "on";
}

String Parameters::getPanString(float value)
{
    if (value == 0.5f) {
        return "C";
    } else if (value < 0.5f) {
        return String((value - 0.5f) * -2.0f, 2) + "L";
    } else if (value > 0.5f) {
        return String((value - 0.5f) * 2.0f, 2) + "R";
    }
    return "";
}

float Parameters::getDelayMilliseconds(float value)
{
    return (value * delay_coeff) * (value * delay_coeff);
}

String Parameters::getDelayString(float value)
{
    QuantizeMode del_quant_mode = time_quantizer->getQuantizeMode(kDelayQuant);
    if (del_quant_mode == QUANT_MS) {
        return String(getDelayMilliseconds(value), 1) + " ms";
    } else return time_quantizer->getQuantValueString(kDelayQuant, value);
}

float Parameters::getIOTMilliseconds(float value)
{
    return static_cast<float>(pow(10.0f, value * iot_coeff));
}

String Parameters::getIOTString(float value)
{
    if (time_quantizer->getQuantizeMode(kIotQuant) == QUANT_MS) {
        return String(getIOTMilliseconds(value), 1) + " ms";
    } else return time_quantizer->getQuantValueString(kIotQuant, value);
}

float Parameters::getDurMilliseconds(float value)
{
    return static_cast<float>(pow(10.0f, dur_coeff + (value * 2.0f)));
}

String Parameters::getDurString(float value)
{
    QuantizeMode dur_quant_mode = time_quantizer->getQuantizeMode(kDurQuant);
    if (dur_quant_mode == QUANT_MS || dur_quant_mode == QUANT_MS_LONG) {
        float length = getDurMilliseconds(value);
        if (dur_quant_mode == QUANT_MS_LONG)
            length *= 10.0f;
        return String(length, 1) + " ms";
    } else return time_quantizer->getQuantValueString(kDurQuant, value);
}

String Parameters::getTransString(float value)
{
    if (value == 0.5f) {
        return "0";
    } else {
        if (scale == 0) {
            return String(static_cast<int>((value - 0.5f) * 4800.0f)) + " c.";
        } else {
            int semitones = MathFunc::roundFtoI((value - 0.5f) * 48.0f);
            return String(semitones);
        }
    }
}

String Parameters::getGlissString(float value)
{
    if (value == 0.5f) {
        return "0";
    } else {
        return String(static_cast<int>((value - 0.5f) * 4800.0f)) + " c.";
    }
}

String Parameters::getFFreqString(float value)
{
    return String(pow(10.0, value * 3.0) * 22.05f, 1) + " hz";
}

int Parameters::getScale()
{
    return scale;
}

int Parameters::getMatrixDest(int index)
{
    return matrix_dest[index] + 1;
}

int Parameters::getMatrixSource(int index)
{
    return static_cast<int>(matrix_source[index] + 1);
}

int Parameters::getMatrixMode(int index)
{
    return static_cast<int>(matrix_mode[index]);
}

void Parameters::setMatrixSource(int index, int param)
{
    param--;
    if (matrix_source[index] != param) {
        matrix_source[index] = static_cast<ModSource>(param);
        setParametersSavedState(false);
    }
	plugin->setParametersChangedState();
}

void Parameters::setMatrixDest(int index, int param)
{
    param--;
    if (matrix_dest[index] != param) {
        matrix_dest[index] = static_cast<ModDest>(param);
        setParametersSavedState(false);
    }
	plugin->setParametersChangedState();
}

void Parameters::setMatrixMode(int index, int param)
{
    if (matrix_mode[index] != param) {
        matrix_mode[index] = static_cast<ModMode>(param);
        setParametersSavedState(false);
    }
	plugin->setParametersChangedState();
}

void Parameters::setScale(int index)
{
    if (scale != index) {
        scale = index;
        setParametersSavedState(false);
    }
}

void Parameters::setParametersSavedState(bool state)
{
    plugin->setSavedState(state);
}

float Parameters::getSampleRate()
{
    return samplerate;
}

void Parameters::setSampleRate(float samplerate)
{
    this->samplerate = samplerate;
    time_quantizer->setSampleRate(samplerate);
}

