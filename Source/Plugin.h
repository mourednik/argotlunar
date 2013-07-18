#ifndef PLUGIN_H
#define PLUGIN_H

#include <vector>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"
#include "Granulator.h"
#include "Misc.h"
#include "ProgramBank.h"

class GrainParametersGenerator;
class Granulator;
class ProgramBank;
class PitchQuantizer;

class Plugin : public AudioProcessor, public ChangeBroadcaster
{
public:
    Plugin();
    ~Plugin();
    // Overrides
    AudioProcessorEditor* createEditor();
    void prepareToPlay (double samplerate, int samples_per_block);
    void releaseResources();
    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    float getParameter (int index);
    void setParameter(int index, float new_value);
    void setMatrixSource(int index, int param);
    void setMatrixDest(int index, int param);
    void setMatrixMode(int index, int param);
    const String getParameterName (int index);
    const String getParameterText (int index);
    int getCurrentProgram();
    int getNumPrograms();
    const String getProgramName(int index);
    void changeProgramName(int index, const String& newName);
    void getCurrentProgramStateInformation (MemoryBlock& destData);
    void setCurrentProgramStateInformation(const void* data, int sizeInBytes);
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
    void setCurrentProgram(int index);
    void setPlayHead(AudioPlayHead *const newPlayHead);
    int getNumParameters();
    bool acceptsMidi() const;
    const String getInputChannelName (int channelIndex) const;
    const String getName() const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;
    bool producesMidi() const;
    bool hasEditor() const;
    bool isMetaParameter(int parameterIndex) const;
    bool silenceInProducesSilenceOut(void) const;
    double getTailLengthSeconds() const;
    
    // New methods
    void loadBankXml(File* file);
    void saveBankXml(File* file);
    void loadCurrentProgramXml(File* file);
    void saveCurrentProgramXml(File* file);
    //void createAppSettingsDir();
    //File* getMidiMapFile();
    bool getSavedState();
    void setSavedState(bool state);
    bool getParametersChangedState();
    void setParametersChangedState();
    bool getProgramChangedState();
    void initCurrentProgram();
    void saveProgramTo(int index);
    std::vector<String> getScaleNames();
    void toggleProgchangeEnabled();
    bool isProgchangeEnabled();

    static const int kNumPrograms = 16;
    static const int kInternalBlocksize = 32;
    Parameters* parameters;
    Granulator* granulator;

private:
    int current_program;
    bool saved_state;
    bool editor_parameter_update_pending;
    bool editor_program_update_pending;
    AudioPlayHead::CurrentPositionInfo pos;
    unsigned int block_sample_pos;
    ProgramBank* program_bank;
    bool progchange_param_enabled;
};

#endif //PLUGIN_H
