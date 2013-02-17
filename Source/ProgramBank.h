#ifndef PROGRAMBANK_H
#define PROGRAMBANK_H

#include "../JuceLibraryCode/JuceHeader.h"
#include "Debug.h"
#include "Program.h"
#include "Parameters.h"

class Parameters;
class Program;

class ProgramBank
{
public:
    ProgramBank(const int num_programs, Parameters* parameters);
    ~ProgramBank();
    
    void initProgram(int index);
    void loadProgramState(int index);
    void saveProgramState(int index);
    
    XmlElement* createBankXml();    
    XmlElement* createProgramXml(int index);    
    
    void loadBankFromXml(XmlElement* bank_xml);
    void loadProgramFromXml(int index, XmlElement* parameters_xml);      
    
    const String getProgramName(int index);
    void setProgramName(int index, const String new_name);

private:
    int num_programs;
    Program* programs; //[NUMPROGRAMS];
    Parameters* parameters;
    //MidiMapper* midi_mapper;
    XmlElement* bank;
};

#endif //PROGRAMBANK_H
