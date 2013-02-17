#ifndef PARAMETERSENUM_H
#define PARAMETERSENUM_H

const int NUM_PARAMS = 37;
const int NUM_MIDI_PARAMS = 36;

enum ParameterType {
    kGrains,
    kMix,
    kIngain,
    kFeedback,
    kAmp,
    kAmpv,
    kPan,
    kPanv,
    kDelay,
    kDelayv,
    kIot,
    kIotv,
    kDur,
    kDurv,
    kTrans,
    kTransv,
    kGliss,
    kGlissv,
    kFtype,
    kFfreq,
    kFfreqv,
    kFq,
    kFqv,
    kEnvType,
    kEnvSustain,
    kEnvSkew,
    kDelayQuant,
    kDurQuant,
    kIotQuant,
    kTransToggle,
    kGlissToggle,
    kFreezeToggle,
    kScaleKey,
    kMatrixMod1,
    kMatrixMod2,
    kMatrixMod3,
    kProgram,
    kNone,    
};

enum ModMode {
    MOD_MODE_SCALED,
    MOD_MODE_DIRECT
};

enum ModSource {
    MOD_SRC_OFF,
    MOD_SRC_AMP,
    MOD_SRC_PAN_LR,
    MOD_SRC_PAN_WIDTH,
    MOD_SRC_DELAY,
    MOD_SRC_IOT,
    MOD_SRC_DUR,
    MOD_SRC_TRANS,
    MOD_SRC_GLISS,
    MOD_SRC_FFREQ,
    MOD_SRC_FQ,
    MOD_SRC_NUM = 11
};

enum ModDest {
    MOD_DEST_OFF,
    MOD_DEST_AMP,
    MOD_DEST_PAN_LR,
    MOD_DEST_DELAY,
    MOD_DEST_IOT,
    MOD_DEST_DUR,
    MOD_DEST_TRANS,
    MOD_DEST_GLISS,
    MOD_DEST_FFREQ,
    MOD_DEST_FQ,
    MOD_DEST_SUSTAIN,
    MOD_DEST_SKEW,
    MOD_DEST_NUM = 12
};

enum QuantizeMode {
    QUANT_MS = 1,
    QUANT_128,
    QUANT_128T,
    QUANT_64,
    QUANT_64T,
    QUANT_32,
    QUANT_32T,
    QUANT_16,
    QUANT_16T,
    QUANT_8,
    QUANT_8T,
    QUANT_4,
    QUANT_4T,
    QUANT_MS_LONG // (dur *= 10)
};

namespace NumQuantModes
{
const float delay = 13.0f;
const float iot = 13.0f;
const float dur = 14.0f;
}

#endif //PARAMETERSENUM_H
