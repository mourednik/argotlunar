#include "Program.h"

Program::Program()
{
    initParameters();
}

Program::~Program()
{
}

void Program::initParameters()
{
    // internal parameters
    name = "Init";
    parameters[kGrains] = 0.5f;
    parameters[kMix] = 1.0f;
    parameters[kIngain] = 1.0f;
    parameters[kFeedback] = 0.0f;
    parameters[kAmp] = 0.5f;
    parameters[kAmpv] = 0.5f;
    parameters[kPan] = 0.5f;
    parameters[kPanv] = 0.5f;
    parameters[kDelay] = 0.0f;
    parameters[kDelayv] = 0.05f;
    parameters[kIot] = 0.25f;
    parameters[kIotv] = 0.1f;
    parameters[kDur] = 0.3f;
    parameters[kDurv] = 0.1f;
    parameters[kTrans] = 0.5f;
    parameters[kTransv] = 0.0f;
    parameters[kGliss] = 0.5f;
    parameters[kGlissv] = 0.0f;
    parameters[kFtype] = 0.0f;
    parameters[kFfreq] = 0.3f;
    parameters[kFfreqv] = 0.5f;
    parameters[kFq] = 0.0f;
    parameters[kFqv] = 0.5f;
    parameters[kEnvType] = 0.0f;
    parameters[kEnvSustain] = 0.0f;
    parameters[kEnvSkew] = 0.5f;
    parameters[kDelayQuant] = 1.0f/NumQuantModes::delay;
    parameters[kIotQuant] = 1.0f/NumQuantModes::iot;
    parameters[kDurQuant] = 1.0f/NumQuantModes::dur;
    parameters[kGlissToggle] = 0.0f;
    parameters[kTransToggle] = 1.0f;
    parameters[kFreezeToggle] = 0.0f;
    parameters[kScaleKey] = 0.0f;
    parameters[kMatrixMod1] = 0.5f;
    parameters[kMatrixMod2] = 0.5f;
    parameters[kMatrixMod3] = 0.5f;

    // external parameters
    scale = 1;
    for (int i = 0; i < 3; i++) {
        matrix_source[i] = MOD_SRC_OFF;
        matrix_dest[i] = MOD_DEST_OFF;
        matrix_mode[i] = MOD_MODE_SCALED;
    }
}
