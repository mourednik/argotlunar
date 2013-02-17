#ifndef GRAINPARAMETERS_H
#define GRAINPARAMETERS_H

struct GrainParameters {
    int iot;
    int duration;
    int bufstart;
    int filter_type;
    int env_type;
    float amp;
    float pan;
    float duration_ratio;
    float trans;
    float gliss;
    float ffreq;
    float fq;
    float env_shape;
    float env_skew;
};

#endif //GRAINPARAMETERS_H
