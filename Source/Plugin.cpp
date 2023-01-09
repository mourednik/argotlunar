#include "Plugin.h"
#include "PluginEditor.h"

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Plugin();
}

Plugin::Plugin()
{
    parameters = new Parameters(this, kInternalBlocksize);
    granulator = new Granulator(parameters, kInternalBlocksize);
    program_bank = new ProgramBank(kNumPrograms, parameters);
    editor_parameter_update_pending = false;
    editor_program_update_pending = false;
    current_program = 0;
    saved_state = true;
    block_sample_pos = 0;
    progchange_param_enabled = true;
}

Plugin::~Plugin()
{
    delete parameters;
    delete granulator;
    delete program_bank;
}

/*
void Plugin::createAppSettingsDir()
{
    File appDataDir = File::getSpecialLocation(File::userApplicationDataDirectory);
    File* argotlunarDir = new File(appDataDir.getFullPathName() + "/.argotlunar");
    argotlunarDir->createDirectory();
}

File* Plugin::getMidiMapFile()
{
    File appDataDir = File::getSpecialLocation(File::userApplicationDataDirectory);
    return new File(appDataDir.getFullPathName() + "/.argotlunar/midimap.xml");
}
*/

bool Plugin::acceptsMidi() const
{
    return false;
}

bool Plugin::isInputChannelStereoPair(int index) const
{
    return true;
}

bool Plugin::isOutputChannelStereoPair(int index) const
{
    return true;
}

bool Plugin::producesMidi() const
{
    return false;
}

bool Plugin::hasEditor() const
{
    return true;
}

const String Plugin::getName() const
{
    return "Argotlunar2";
}

const String Plugin::getInputChannelName(const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String Plugin::getOutputChannelName(const int channelIndex) const
{
    return (channelIndex == 0) ? "L" : "R";
}

double Plugin::getTailLengthSeconds() const
{
  return 0.0;
}

AudioProcessorEditor* Plugin::createEditor()
{
    return new PluginEditor(this);
}

void Plugin::prepareToPlay (double samplerate, int samples_per_block)
{
    granulator->prepareToPlay(static_cast<float>(samplerate));
}

void Plugin::releaseResources()
{
    granulator->releaseResources();
}

void Plugin::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    if (getNumInputChannels() != 2 && getNumOutputChannels() != 2) {
        return;
    }
    float* chan1 = buffer.getWritePointer(0);
    float* chan2 = buffer.getWritePointer(1);
    int sampleframes = buffer.getNumSamples();
    int blocks = sampleframes / kInternalBlocksize;

    if (getPlayHead() != 0 && getPlayHead()->getCurrentPosition(pos)) {
    if ((&pos)->bpm == 0.0f) {
            parameters->setQuantizationDisabled();
            parameters->setParameter(kDelayQuant, 0.0f, false);
            parameters->setParameter(kIotQuant, 0.0f, false);
            parameters->setParameter(kDurQuant, 0.0f, false);
        }
        else
            parameters->time_quantizer->setPositionInfo(&pos);
    } else {
        parameters->setQuantizationDisabled();
    }

    block_sample_pos = 0;
    for (int i = 0; i < blocks; i++) {
        granulator->processInternalBlock(chan1, chan2, kInternalBlocksize);
        chan1 += kInternalBlocksize;
        chan2 += kInternalBlocksize;
        parameters->time_quantizer->incrementPositionInfo();
    }
    int samples_remaining = sampleframes % kInternalBlocksize;
    if (samples_remaining) {
        granulator->processInternalBlock(chan1, chan2, samples_remaining);
    }
}

int Plugin::getNumParameters()
{
    return static_cast<int>(NUM_PARAMS);
}

float Plugin::getParameter (int index)
{
    if (index == kProgram) {
        return static_cast<float>(current_program / (kNumPrograms - 1));
    } else {
        return parameters->param[index];
    }
}

const String Plugin::getParameterName (int index)
{
    return parameters->getParameterName(index);
}

const String Plugin::getParameterText (int index)
{
    if (index == kProgram) {
        return String(current_program + 1);
    } else return parameters->getParameterText(index);
}

std::vector<String> Plugin::getScaleNames()
{
    return granulator->grain_param_generator->pitch_quantizer->getNames();
}

bool Plugin::isMetaParameter(int parameterIndex) const
{
    if (parameterIndex == kProgram) {
        return true;
    }
    else
        return false;
}

bool Plugin::silenceInProducesSilenceOut(void) const
{
    return false;
}

void Plugin::setParameter(int index, float new_value)
{
    if (index != kNone) {
        if (index == kProgram) {
            if (progchange_param_enabled) {
                int selected_program = static_cast<int>(new_value * (kNumPrograms - 1));
                if (current_program != selected_program) {
                    setCurrentProgram(selected_program);
                }
            }
        } else {
            parameters->setParameter(index, new_value, false);
        }
        setParametersChangedState();
    }
}

void Plugin::toggleProgchangeEnabled()
{
    progchange_param_enabled = !progchange_param_enabled;
}

bool Plugin:: isProgchangeEnabled()
{
    return progchange_param_enabled;
}

void Plugin::setMatrixSource(int index, int param)
{
    parameters->setMatrixSource(index, param);
}

void Plugin::setMatrixDest(int index, int param)
{
    parameters->setMatrixDest(index, param);
}

void Plugin::setMatrixMode(int index, int param)
{
    parameters->setMatrixMode(index, param);
}

const String Plugin::getProgramName(int index)
{
    return program_bank->getProgramName(index);
}

void Plugin::changeProgramName(int index, const String& newName)
{
    program_bank->setProgramName(index, newName);
    editor_program_update_pending = true;
}

int Plugin::getCurrentProgram()
{
    return current_program;
}

bool Plugin::getSavedState()
{
    return saved_state;
}

void Plugin::setSavedState(bool state)
{
    if (saved_state == true && state == false) {
        editor_program_update_pending = true;
    }
    saved_state = state;
}

bool Plugin::getParametersChangedState()
{
    if (editor_parameter_update_pending) {
        editor_parameter_update_pending = false;
        return true;
    }
    else
        return false;
}

void Plugin::setParametersChangedState()
{
    editor_parameter_update_pending = true;
}

bool Plugin::getProgramChangedState()
{
    if (editor_program_update_pending) {
        editor_program_update_pending = false;
        return true;
    }
    else
        return false;
}

int Plugin::getNumPrograms()
{
    return kNumPrograms;
}

void Plugin::initCurrentProgram()
{
    program_bank->initProgram(current_program);
    program_bank->loadProgramState(current_program);
    setSavedState(true);
    editor_program_update_pending = true;
}

void Plugin::saveProgramTo(int index)
{
    String current_program_name = program_bank->getProgramName(current_program);
    program_bank->saveProgramState(index);
    program_bank->setProgramName(index, current_program_name);
    current_program = index;
    setSavedState(true);
    editor_program_update_pending = true;
}

void Plugin::setCurrentProgram(int index)
{
    program_bank->loadProgramState(index);
    current_program = index;
    setSavedState(true);
    editor_program_update_pending = true;
}

void Plugin::getCurrentProgramStateInformation(MemoryBlock& destData)
{
    //save current settings
    program_bank->saveProgramState(current_program);
    saveProgramTo(current_program);

    //output program to host
    XmlElement* program = program_bank->createProgramXml(current_program);
    copyXmlToBinary (*program, destData);
    delete program;
}

void Plugin::setCurrentProgramStateInformation(const void* data, int sizeInBytes)
{
    //load program from host
    if (const auto xml_state = getXmlFromBinary(data, sizeInBytes)) {
        program_bank->loadProgramFromXml(current_program, xml_state.get());
        setCurrentProgram(current_program);
        editor_program_update_pending = true;
    }
}

void Plugin::getStateInformation (MemoryBlock& destData)
{
    // save current program
    program_bank->saveProgramState(current_program);

    // output program_bank to host
    XmlElement* bankXml = program_bank->createBankXml();
    copyXmlToBinary(*bankXml, destData);
    editor_program_update_pending = true;
}

void Plugin::setStateInformation (const void* data, int sizeInBytes)
{
    //load bank from host
    if (const auto xml_state = getXmlFromBinary(data, sizeInBytes)) {
        program_bank->loadBankFromXml(xml_state.get());
        setCurrentProgram(current_program);
        editor_program_update_pending = true;
    }
}

void Plugin::loadBankXml(File* file)
{
    //load bank from file
    XmlDocument xml_document(*file);
    if (const auto xml_state = xml_document.getDocumentElement()) {
        program_bank->loadBankFromXml(xml_state.get());
        setCurrentProgram(current_program);
        editor_program_update_pending = true;
    }
}

void Plugin::saveBankXml(File* file)
{
    // save current program
    program_bank->saveProgramState(current_program);

    // output bank to file
    XmlElement* bankXml = program_bank->createBankXml();
    file->replaceWithText(bankXml->createDocument(String()));
    delete bankXml;
    editor_program_update_pending = true;
    setSavedState(true);
}

void Plugin::loadCurrentProgramXml(File* file)
{
    //load program from file
    XmlDocument xml_document(*file);
    if (const auto xml_state = xml_document.getDocumentElement()) {
        program_bank->loadProgramFromXml(current_program, xml_state.get());
        setCurrentProgram(current_program);
        editor_program_update_pending = true;
    }
}
void Plugin::saveCurrentProgramXml(File* file)
{
    //save current settings
    program_bank->saveProgramState(current_program);
    saveProgramTo(current_program);

    //output program to file
    XmlElement* program = program_bank->createProgramXml(current_program);
    file->replaceWithText(program->createDocument(String()));
    delete program;
}
