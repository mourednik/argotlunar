#include "GrainParametersGenerator.h"

GrainParametersGenerator::GrainParametersGenerator(Parameters* parameters,
        DelayLine* delay_line,
        Granulator* granulator,
        const int internal_block_size)
{
    this->parameters = parameters;
    this->delay_line = delay_line;
    this->granulator = granulator;
    this->time_quantizer = parameters->time_quantizer;
    this->internal_block_size = internal_block_size;
    random = new Random(Time::currentTimeMillis());
    pitch_quantizer = new PitchQuantizer();
}

GrainParametersGenerator::~GrainParametersGenerator()
{
    delete random;
    delete pitch_quantizer;
}

const GrainParameters GrainParametersGenerator::getNewGrainParameters()
{
    copyExternalParametersToInstanceVariables();
    generateRandomizedParameters();
    for (int i = 0; i < 3; i++)
        applyModMatrix(i);
    return generateFinalParameters();
}

void GrainParametersGenerator::copyExternalParametersToInstanceVariables()
{
    mix = parameters->param[kMix];
    input_gain = parameters->param[kIngain];
    grains = parameters->param[kGrains];
    feedback = parameters->param[kFeedback];
    amp_min = parameters->param[kAmp];
    delay_min = parameters->param[kDelay];
    iot_min = parameters->param[kIot];
    dur_min = parameters->param[kDur];
    ffreq_min = parameters->param[kFfreq];
    fq_min = parameters->param[kFq];
    env_shape = parameters->param[kEnvSustain];
    env_skew = parameters->param[kEnvSkew];
    trans_toggle = parameters->param[kTransToggle];
    gliss_toggle = parameters->param[kGlissToggle];
    freeze_toggle = parameters->param[kFreezeToggle];
    matrixmod1 = parameters->param[kMatrixMod1];
    matrixmod2 = parameters->param[kMatrixMod2];
    matrixmod3 = parameters->param[kMatrixMod3];
}

void GrainParametersGenerator::generateRandomizedParameters()
{
    //============= Amp =============
    amp_value = amp_min + random->nextFloat()
                * (parameters->amp_max - amp_min);
    //============= Pan =============
    pan_value = parameters->pan_min + random->nextFloat()
                * (parameters->pan_max - parameters->pan_min);
    //============= Delay =============
    delay_value = delay_min + random->nextFloat()
                  * (parameters->delay_max - delay_min);
    //============= IOT =============
    iot_value = iot_min + random->nextFloat()
                * (parameters->iot_max - iot_min);
    //============= Duration =============
    dur_value = dur_min + random->nextFloat()
                * (parameters->dur_max - dur_min);
    //============= Transposition =============
    trans_value = parameters->trans_min + random->nextFloat()
                  * (parameters->trans_max - parameters->trans_min);
    //============= Glissando =============
    gliss_value = parameters->gliss_min + random->nextFloat()
                  * (parameters->gliss_max - parameters->gliss_min);
    //============= Filter =============
    if (parameters->filter_type == FILTER_RANDOM) {
        grain_parameters.filter_type = random->nextInt(5);
    } else {
        grain_parameters.filter_type = parameters->filter_type;
    }
    if (grain_parameters.filter_type != FILTER_OFF) {
        ffreq_value = ffreq_min + random->nextFloat()
                      * (parameters->ffreq_max - ffreq_min);
        fq_value = fq_min + random->nextFloat()
                   * (parameters->fq_max - fq_min);
    }
}

bool GrainParametersGenerator::modSourceEqualsDest(ModSource source, ModDest dest)
{
    switch (source) {
    case MOD_SRC_AMP:
        if (dest == MOD_DEST_AMP)
            return true;
        break;
    case MOD_SRC_PAN_LR:
    case MOD_SRC_PAN_WIDTH:
        if (dest == MOD_DEST_PAN_LR)
            return true;
        break;
    case MOD_SRC_DELAY:
        if (dest == MOD_DEST_DELAY)
            return true;
        break;
    case MOD_SRC_IOT:
        if (dest == MOD_DEST_IOT)
            return true;
        break;
    case MOD_SRC_DUR:
        if (dest == MOD_DEST_DUR)
            return true;
        break;
    case MOD_SRC_TRANS:
        if (dest == MOD_DEST_TRANS)
            return true;
        break;
    case MOD_SRC_GLISS:
        if (dest == MOD_DEST_GLISS)
            return true;
        break;
    case MOD_SRC_FFREQ:
        if (dest == MOD_DEST_FFREQ)
            return true;
        break;
    case MOD_SRC_FQ:
    default:
        if (dest == MOD_DEST_FQ)
            return true;
        break;

    }
    return false;
}

float GrainParametersGenerator::getModSourceValue(ModSource source, ModMode mode)
{
    if (mode == MOD_MODE_DIRECT) {
        switch (source) {
        case MOD_SRC_AMP:
            return amp_value;
        case MOD_SRC_PAN_LR:
            return pan_value;
        case MOD_SRC_PAN_WIDTH:
            return fabs((pan_value - 0.5f) * 2.0f);
        case MOD_SRC_DELAY:
            return delay_value;
        case MOD_SRC_IOT:
            return iot_value;
        case MOD_SRC_DUR:
            return dur_value;
        case MOD_SRC_TRANS:
            return trans_value;
        case MOD_SRC_GLISS:
            return gliss_value;
        case MOD_SRC_FFREQ:
            return ffreq_value;
        case MOD_SRC_FQ:
        default:
            return fq_value;
        }
    } else if (mode == MOD_MODE_SCALED) {
        float denominator;

        switch (source) {
        case MOD_SRC_AMP:
            denominator = (parameters->amp_max - amp_min);
            if (denominator == 0.0f) break;
            return (amp_value - amp_min) / denominator;
        case MOD_SRC_PAN_LR:
            denominator = (parameters->pan_max - parameters->pan_min);
            if (denominator == 0.0f) break;
            return (pan_value - parameters->pan_min) / denominator;
        case MOD_SRC_PAN_WIDTH: {
            denominator = (parameters->pan_max - parameters->pan_min);
            if (denominator == 0.0f) break;
            float modvalue = (pan_value - parameters->pan_min) / denominator;
            return fabs((modvalue - 0.5f) * 2.0f);
        }
        case MOD_SRC_DELAY:
            denominator = (parameters->delay_max - delay_min);
            if (denominator == 0.0f) break;
            return (delay_value - delay_min) / denominator;
        case MOD_SRC_IOT:
            denominator = (parameters->iot_max - iot_min);
            if (denominator == 0.0f) break;
            return (iot_value - iot_min) / denominator;
        case MOD_SRC_DUR:
            denominator = (parameters->dur_max - dur_min);
            if (denominator == 0.0f) break;
            return (dur_value - dur_min) / denominator;
        case MOD_SRC_TRANS:
            denominator = (parameters->trans_max - parameters->trans_min);
            if (denominator == 0.0f) break;
            return (trans_value - parameters->trans_min) / denominator;
        case MOD_SRC_GLISS:
            denominator = (parameters->gliss_max - parameters->gliss_min);
            if (denominator == 0.0f) break;
            return (gliss_value - parameters->gliss_min) / denominator;
        case MOD_SRC_FFREQ:
            denominator = (parameters->ffreq_max - ffreq_min);
            if (denominator == 0.0f) break;
            return (ffreq_value - ffreq_min) / denominator;
        case MOD_SRC_FQ:
        default:
            denominator = (parameters->fq_max - fq_min);
            if (denominator == 0.0f) break;
            return (fq_value - fq_min) / denominator;
        }
    }
    return -100.0f;
}

float* GrainParametersGenerator::getModDestPtr(ModDest dest)
{
    switch (dest) {
    case  MOD_DEST_AMP:
        return &amp_value;
    case MOD_DEST_PAN_LR:
        return &pan_value;
    case MOD_DEST_DELAY:
        return &delay_value;
    case MOD_DEST_IOT:
        return &iot_value;
    case MOD_DEST_DUR:
        return &dur_value;
    case MOD_DEST_TRANS:
        return &trans_value;
    case MOD_DEST_GLISS:
        return &gliss_value;
    case MOD_DEST_FFREQ:
        return &ffreq_value;
    case MOD_DEST_FQ:
        return &fq_value;
    case MOD_DEST_SUSTAIN:
        return &env_shape;
    case MOD_DEST_SKEW:
    default:
        return &env_skew;
    }
}

void GrainParametersGenerator::applyModMatrix(int index)
{
    float* dest_ptr;
    float source_value = 0.0f;
    float mod = 0.0f;
    float ratio = 0.0f;
    ModSource mod_source = parameters->matrix_source[index];
    ModDest mod_dest = parameters->matrix_dest[index];
    ModMode mod_mode = parameters->matrix_mode[index];

    if (mod_source == MOD_SRC_OFF || mod_dest == MOD_DEST_OFF)
        return;
    if (modSourceEqualsDest(mod_source, mod_dest))
        return;
    source_value = getModSourceValue(mod_source, mod_mode);
    if (source_value == -100.0f)
        return;
    dest_ptr = getModDestPtr(mod_dest);

    switch (index) {
    case 0:
        mod = matrixmod1;
        break;
    case 1:
        mod = matrixmod2;
        break;
    case 2:
        mod = matrixmod3;
        break;
    }
    mod = (mod * 2.0f) - 1.0f;
    ratio = fabs(mod);
    if (mod < 0.0f) {
        mod = ratio * (1.0f - source_value);
    } else {
        mod = ratio * source_value;
    }
    *dest_ptr = (*dest_ptr * (1.0f - ratio)) + mod;
}

const GrainParameters GrainParametersGenerator::generateFinalParameters()
{
    float millisecond_samples = parameters->getSampleRate() / 1000.0f;
    //============= Amp =============
    grain_parameters.amp = amp_value;
    //============= Pan =============
    grain_parameters.pan = pan_value;
    //============= IOT =============
    if (time_quantizer->getQuantizeMode(kIotQuant) == QUANT_MS) {
        grain_parameters.iot = static_cast<int>(
                                   parameters->getIOTMilliseconds(iot_value) * millisecond_samples);
    } else {
        grain_parameters.iot =
            parameters->time_quantizer->quantizeStartPos(kIotQuant, iot_value);
    }
    //============= Duration =============
    grain_parameters.duration_ratio = dur_value;

    if (time_quantizer->getQuantizeMode(kDurQuant) == QUANT_MS) {
        grain_parameters.duration = static_cast<int>(
                                        parameters->getDurMilliseconds(dur_value) * millisecond_samples);
    } else if (time_quantizer->getQuantizeMode(kDurQuant) == QUANT_MS_LONG) {
        grain_parameters.duration = static_cast<int>(
                                        parameters->getDurMilliseconds(dur_value) * millisecond_samples);
        grain_parameters.duration *= 10;
    } else {
        grain_parameters.duration =
            parameters->time_quantizer->quantizeLength(kDurQuant, dur_value);
    }
    //============= Transposition =============
    if (trans_toggle == 0.0f) {
        grain_parameters.trans = 1.0f;
    } else if (parameters->scale == 0) {
        grain_parameters.trans = pow(2.0f, (trans_value - 0.5f) * 4.0f);
    } else {
        grain_parameters.trans = pitch_quantizer->getQuantizedPitch(
                                     (parameters->scale - 1), parameters->scale_key, trans_value);
        trans_value = 0.25f * static_cast<float>((log(grain_parameters.trans)
                      / log(2.0)) + 2.0);
    }
    //============= Glissando =============
    float glissTrans = grain_parameters.trans;
    if (gliss_toggle > 0.0f) {
        if (trans_toggle > 0.0f) {
            gliss_value = trans_value + (gliss_value - 0.5f);
        }
        if (gliss_value > 1.0f) {
            gliss_value = 1.0f;
        } else if (gliss_value < 0.0f) {
            gliss_value = 0.0f;
        }
        glissTrans = pow(2.0f, (gliss_value - 0.5f) * 4.0f);
        grain_parameters.gliss = (glissTrans - grain_parameters.trans)
                                 / grain_parameters.duration;
    } else {
        grain_parameters.gliss = 0.0f;
    }
    //============= Delay =============
    int delay;
    if (time_quantizer->getQuantizeMode(kDelayQuant) == QUANT_MS) {
        delay = static_cast<int>(
                    parameters->getDelayMilliseconds(delay_value) * millisecond_samples);
    } else {
        delay = time_quantizer->quantizeStartPos(kDelayQuant, delay_value);
    }
    // increase delay if transposition increased
    float highestTrans;
    if (gliss_toggle == 1.0f && gliss_value != trans_value) {
        highestTrans = (grain_parameters.trans > glissTrans) ?
                       grain_parameters.trans : glissTrans;
    } else {
        highestTrans = grain_parameters.trans;
    }
    if (highestTrans > 1.0f) {
        delay += static_cast<int>((highestTrans-1.0f) * grain_parameters.duration);
    }
    //============= Envelope =============
    grain_parameters.env_type = parameters->env_type;
    grain_parameters.env_shape = env_shape;
    grain_parameters.env_skew = env_skew;
    //============= Filter =============
    grain_parameters.ffreq = ffreq_value;
    grain_parameters.fq = fq_value;
    //============= bufstart =============
    int buflen = delay_line->getDelayLength();
    int maxdelay = buflen - internal_block_size;
    if (delay > maxdelay)
        delay = maxdelay;
    grain_parameters.bufstart = static_cast<int>(delay_line->getBlockReadPos()
                                + grain_parameters.iot
                                - delay);
    if (grain_parameters.bufstart < 1) {
        grain_parameters.bufstart += buflen;
    } else if (grain_parameters.bufstart >= buflen) {
        grain_parameters.bufstart -= buflen;
    }
    return grain_parameters;
}


