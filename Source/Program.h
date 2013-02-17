#ifndef PROGRAM_H
#define PROGRAM_H

#include "../JuceLibraryCode/JuceHeader.h"
#include "Debug.h"
#include "ParametersEnum.h"
//#include "MidiMapper.h"

class Program
{
public:
    Program();
    ~Program();
    void initParameters();
    String name;
    float parameters[NUM_PARAMS - 1];
    int scale;
    ModSource matrix_source[3];
    ModDest matrix_dest[3];
    ModMode matrix_mode[3];       
private:    
};

#endif //PROGRAMBANK_H
