#ifndef GRANULATOR_H
#define GRANULATOR_H

#include "Debug.h"
#include "DelayLine.h"
#include "Filter.h"
#include "GrainParametersGenerator.h"
#include "Grain.h"
#include "Parameters.h"
#include "PitchQuantizer.h"

class GrainParametersGenerator;
class Parameters;

class Granulator
{
public:
    Granulator(Parameters* params, const int internal_block_size);
    ~Granulator();
    void prepareToPlay(float samplerate);
    void processInternalBlock(float* chan1, float* chan2, int sampleframes);
    void releaseResources();
    const float getSampleRate();

    GrainParametersGenerator* grain_param_generator;
    static const int kMaxGrains = 20;
    static const int kBufferSeconds = 5;
    int internal_block_size;

private:
    void writeOutput(float* chan1, float* chan2, float* outbuf_left, float* outbuf_right, int sampleframes);
    void clearOutbufs(float* outbuf_left, float* outbuf_right, int sampleframes);
    void hardClip(float* input, int sampleframes);
    void processGrains(int sampleframes);
    void deleteGrains();
    void setActiveGrains();

    float samplerate;
    float *outbuf_left, *outbuf_right;
    float bpm;
    int active_grains, sampleframes;
    bool initialized;
    Grain* graincloud[kMaxGrains];
    Parameters* parameters;
    DelayLine* delay_line;
};

#endif //GRANULATOR_H
