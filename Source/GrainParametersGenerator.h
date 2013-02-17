#ifndef GRAINPARAMETERSGENERATOR_H
#define GRAINPARAMETERSGENERATOR_H

#include <math.h>
#include "../JuceLibraryCode/JuceHeader.h"
#include "GrainParameters.h"
#include "Granulator.h"
#include "Misc.h"
#include "ParametersEnum.h"
#include "TimeQuantizer.h"

class DelayLine;
class Granulator;
class Parameters;
class TimeQuantizer;
class PitchQuantizer;

class GrainParametersGenerator
{
public:
    GrainParametersGenerator(Parameters* parameters, DelayLine* delay_line, Granulator* granulator,
                             const int internal_block_size);
    ~GrainParametersGenerator();
    const GrainParameters getNewGrainParameters();

    PitchQuantizer* pitch_quantizer;

private:
    bool modSourceEqualsDest(ModSource source, ModDest dest);
    float getModSourceValue(ModSource source, ModMode mode);
    float* getModDestPtr(ModDest dest);
    void copyExternalParametersToInstanceVariables();
    void generateRandomizedParameters();
    void applyModMatrix(int index);
    const GrainParameters generateFinalParameters();

    int internal_block_size;
    float mix, input_gain;
    float amp_min, amp_value;
    float pan_value;
    float feedback;
    float delay_min, delay_value;
    float iot_min, iot_value;
    float dur_min, dur_value;
    float trans_value;
    float gliss_value;
    float ffreq_min, ffreq_value;
    float fq_min, fq_value;
    float env_shape, env_skew;
    float grains;
    float trans_toggle, gliss_toggle, freeze_toggle;
    float matrixmod1, matrixmod2, matrixmod3;
    GrainParameters grain_parameters;
    Random* random;
    Parameters* parameters;
    TimeQuantizer* time_quantizer;
    DelayLine* delay_line;
    Granulator* granulator;
};

#endif //GRAINPARAMETERSGENERATOR_H
