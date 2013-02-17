#include "ProgramBank.h"

ProgramBank::ProgramBank(const int num_programs, Parameters* parameters)
{
    this->parameters = parameters;
    this->num_programs = num_programs;
    programs = new Program[num_programs];
    loadProgramState(0);
}

ProgramBank::~ProgramBank()
{
    delete[] programs;
}

void ProgramBank::saveProgramState(int index)
{
    // internal parameters
    for (int i = 0; i < (NUM_PARAMS - 1); i++) {
        programs[index].parameters[i] = parameters->param[i];        
    }

    // external parameters
    programs[index].scale = parameters->scale;
    for (int i = 0; i < 3; i++) {
        programs[index].matrix_source[i] = parameters->matrix_source[i];
        programs[index].matrix_dest[i] = parameters->matrix_dest[i];
        programs[index].matrix_mode[i] = parameters->matrix_mode[i];
    }
}

void ProgramBank::loadProgramState(int index)
{
    // internal parameters
    for (int i = 0; i < (NUM_PARAMS - 1); i++) {
        parameters->param[i] = programs[index].parameters[i];
    }
    
    // external parameters
    parameters->scale = programs[index].scale;
    for (int i = 0; i < 3; i++) {
        parameters->matrix_source[i] = programs[index].matrix_source[i];
        parameters->matrix_dest[i] = programs[index].matrix_dest[i];
        parameters->matrix_mode[i] = programs[index].matrix_mode[i];
    }
    parameters->initializeInternalParameters();    
}

XmlElement* ProgramBank::createBankXml()
{
    XmlElement* bank_xml = new XmlElement("ARGOTLUNAR2_BANK");
    for (int i = 0; i < num_programs; i++) {    
        bank_xml->addChildElement(createProgramXml(i));
    }
    return bank_xml;
}

void ProgramBank::loadBankFromXml(XmlElement* bank_xml)
{
    int i = 0;
    if (bank_xml->hasTagName("ARGOTLUNAR2_BANK")) {                
        forEachXmlChildElement(*bank_xml, parameters_xml)
            loadProgramFromXml(i++, parameters_xml);
    }
}

XmlElement* ProgramBank::createProgramXml(int index)
{
    XmlElement* program_xml = new XmlElement("ARGOTLUNAR2_PROGRAM");
    // external parameters
    program_xml->setAttribute("program_name", programs[index].name);
    program_xml->setAttribute("grains", programs[index].parameters[kGrains]);
    program_xml->setAttribute("mix", programs[index].parameters[kMix]);
    program_xml->setAttribute("input_gain", programs[index].parameters[kIngain]);
    program_xml->setAttribute("feedback", programs[index].parameters[kFeedback]);
    program_xml->setAttribute("amp", programs[index].parameters[kAmp]);
    program_xml->setAttribute("ampv", programs[index].parameters[kAmpv]);
    program_xml->setAttribute("pan", programs[index].parameters[kPan]);
    program_xml->setAttribute("panv", programs[index].parameters[kPanv]);
    program_xml->setAttribute("delay", programs[index].parameters[kDelay]);
    program_xml->setAttribute("delayv", programs[index].parameters[kDelayv]);
    program_xml->setAttribute("iot", programs[index].parameters[kIot]);
    program_xml->setAttribute("iotv", programs[index].parameters[kIotv]);
    program_xml->setAttribute("dur", programs[index].parameters[kDur]);
    program_xml->setAttribute("durv", programs[index].parameters[kDurv]);
    program_xml->setAttribute("trans", programs[index].parameters[kTrans]);
    program_xml->setAttribute("transv", programs[index].parameters[kTransv]);
    program_xml->setAttribute("gliss", programs[index].parameters[kGliss]);
    program_xml->setAttribute("glissv", programs[index].parameters[kGlissv]);
    program_xml->setAttribute("filter_type", programs[index].parameters[kFtype]);
    program_xml->setAttribute("ffreq", programs[index].parameters[kFfreq]);
    program_xml->setAttribute("ffreqv", programs[index].parameters[kFfreqv]);
    program_xml->setAttribute("fq", programs[index].parameters[kFq]);
    program_xml->setAttribute("fqv", programs[index].parameters[kFqv]);
    program_xml->setAttribute("env_type", programs[index].parameters[kEnvType]);
    program_xml->setAttribute("env_shape", programs[index].parameters[kEnvSustain]);
    program_xml->setAttribute("env_skew", programs[index].parameters[kEnvSkew]);
    program_xml->setAttribute("delay_quant", programs[index].parameters[kDelayQuant]);
    program_xml->setAttribute("dur_quant", programs[index].parameters[kDurQuant]);
    program_xml->setAttribute("iot_quant", programs[index].parameters[kIotQuant]);
    program_xml->setAttribute("trans_toggle", programs[index].parameters[kTransToggle]);
    program_xml->setAttribute("gliss_toggle", programs[index].parameters[kGlissToggle]);
    program_xml->setAttribute("freeze_toggle", programs[index].parameters[kFreezeToggle]);
    program_xml->setAttribute("scale_key", programs[index].parameters[kScaleKey]);
    program_xml->setAttribute("matrix_mod_1", programs[index].parameters[kMatrixMod1]);
    program_xml->setAttribute("matrix_mod_2", programs[index].parameters[kMatrixMod1]);
    program_xml->setAttribute("matrix_mod_3", programs[index].parameters[kMatrixMod3]);
    // internal parameters
    program_xml->setAttribute("scale", programs[index].scale);
    program_xml->setAttribute("matrix_src_1", programs[index].matrix_source[0]);
    program_xml->setAttribute("matrix_src_2", programs[index].matrix_source[1]);
    program_xml->setAttribute("matrix_src_3", programs[index].matrix_source[2]);
    program_xml->setAttribute("matrix_dest_1", programs[index].matrix_dest[0]);
    program_xml->setAttribute("matrix_dest_2", programs[index].matrix_dest[1]);
    program_xml->setAttribute("matrix_dest_3", programs[index].matrix_dest[2]);
    program_xml->setAttribute("matrix_mode_1", programs[index].matrix_mode[0]);
    program_xml->setAttribute("matrix_mode_2", programs[index].matrix_mode[1]);
    program_xml->setAttribute("matrix_mode_3", programs[index].matrix_mode[2]);
    return program_xml;
}

void ProgramBank::loadProgramFromXml(int index, XmlElement* parameters_xml)
{
    if (!parameters_xml->hasTagName("ARGOTLUNAR2_PROGRAM")) {
        return;        
    }    
    // external parameters
    programs[index].name = parameters_xml->getStringAttribute("program_name");
    programs[index].parameters[kGrains] = static_cast<float>(parameters_xml->getDoubleAttribute("grains"));
    programs[index].parameters[kMix] = static_cast<float>(parameters_xml->getDoubleAttribute("mix"));
    programs[index].parameters[kIngain] = static_cast<float>(parameters_xml->getDoubleAttribute("input_gain"));
    programs[index].parameters[kFeedback] = static_cast<float>(parameters_xml->getDoubleAttribute("feedback"));
    programs[index].parameters[kAmp] = static_cast<float>(parameters_xml->getDoubleAttribute("amp"));
    programs[index].parameters[kAmpv] = static_cast<float>(parameters_xml->getDoubleAttribute("ampv"));
    programs[index].parameters[kPan] = static_cast<float>(parameters_xml->getDoubleAttribute("pan"));
    programs[index].parameters[kPanv] = static_cast<float>(parameters_xml->getDoubleAttribute("panv"));
    programs[index].parameters[kDelay] = static_cast<float>(parameters_xml->getDoubleAttribute("delay"));
    programs[index].parameters[kDelayv] = static_cast<float>(parameters_xml->getDoubleAttribute("delayv"));
    programs[index].parameters[kIot] = static_cast<float>(parameters_xml->getDoubleAttribute("iot"));
    programs[index].parameters[kIotv] = static_cast<float>(parameters_xml->getDoubleAttribute("iotv"));
    programs[index].parameters[kDur] = static_cast<float>(parameters_xml->getDoubleAttribute("dur"));
    programs[index].parameters[kDurv] = static_cast<float>(parameters_xml->getDoubleAttribute("durv"));
    programs[index].parameters[kTrans] = static_cast<float>(parameters_xml->getDoubleAttribute("trans"));
    programs[index].parameters[kTransv] = static_cast<float>(parameters_xml->getDoubleAttribute("transv"));
    programs[index].parameters[kGliss] = static_cast<float>(parameters_xml->getDoubleAttribute("gliss"));
    programs[index].parameters[kGlissv] = static_cast<float>(parameters_xml->getDoubleAttribute("glissv"));
    programs[index].parameters[kFfreq] = static_cast<float>(parameters_xml->getDoubleAttribute("ffreq"));
    programs[index].parameters[kFfreqv] = static_cast<float>(parameters_xml->getDoubleAttribute("ffreqv"));
    programs[index].parameters[kFtype] = static_cast<float>(parameters_xml->getDoubleAttribute("filter_type"));
    programs[index].parameters[kFq] = static_cast<float>(parameters_xml->getDoubleAttribute("fq"));
    programs[index].parameters[kFqv] = static_cast<float>(parameters_xml->getDoubleAttribute("fqv"));
    programs[index].parameters[kEnvType] = static_cast<float>(parameters_xml->getDoubleAttribute("env_type"));
    programs[index].parameters[kEnvSustain] = static_cast<float>(parameters_xml->getDoubleAttribute("env_shape"));
    programs[index].parameters[kEnvSkew] = static_cast<float>(parameters_xml->getDoubleAttribute("env_skew"));
    programs[index].parameters[kDelayQuant] = static_cast<float>(parameters_xml->getDoubleAttribute("delay_quant"));
    programs[index].parameters[kDurQuant] = static_cast<float>(parameters_xml->getDoubleAttribute("dur_quant"));
    programs[index].parameters[kIotQuant] = static_cast<float>(parameters_xml->getDoubleAttribute("iot_quant"));
    programs[index].parameters[kTransToggle] = static_cast<float>(parameters_xml->getDoubleAttribute("trans_toggle"));
    programs[index].parameters[kGlissToggle] = static_cast<float>(parameters_xml->getDoubleAttribute("gliss_toggle"));
    programs[index].parameters[kFreezeToggle] = static_cast<float>(parameters_xml->getDoubleAttribute("freeze_toggle"));
    programs[index].parameters[kScaleKey] = static_cast<float>(parameters_xml->getDoubleAttribute("scale_key"));
    programs[index].parameters[kMatrixMod1] = static_cast<float>(parameters_xml->getDoubleAttribute("matrix_mod_1"));
    programs[index].parameters[kMatrixMod2] = static_cast<float>(parameters_xml->getDoubleAttribute("matrix_mod_2"));
    programs[index].parameters[kMatrixMod3] = static_cast<float>(parameters_xml->getDoubleAttribute("matrix_mod_3"));
    // internal parameters
    programs[index].scale = parameters_xml->getIntAttribute("scale");
    programs[index].matrix_source[0] = static_cast<ModSource>(parameters_xml->getIntAttribute("matrix_src_1"));
    programs[index].matrix_source[1] = static_cast<ModSource>(parameters_xml->getIntAttribute("matrix_src_2"));
    programs[index].matrix_source[2] = static_cast<ModSource>(parameters_xml->getIntAttribute("matrix_src_3"));
    programs[index].matrix_dest[0] = static_cast<ModDest>(parameters_xml->getIntAttribute("matrix_dest_1"));
    programs[index].matrix_dest[1] = static_cast<ModDest>(parameters_xml->getIntAttribute("matrix_dest_2"));
    programs[index].matrix_dest[2] = static_cast<ModDest>(parameters_xml->getIntAttribute("matrix_dest_3"));
    programs[index].matrix_mode[0] = static_cast<ModMode>(parameters_xml->getIntAttribute("matrix_mode_1"));
    programs[index].matrix_mode[1] = static_cast<ModMode>(parameters_xml->getIntAttribute("matrix_mode_2"));
    programs[index].matrix_mode[2] = static_cast<ModMode>(parameters_xml->getIntAttribute("matrix_mode_3"));
}


void ProgramBank::initProgram(int index)
{
    programs[index].initParameters();
}

const String ProgramBank::getProgramName(int index)
{
    return programs[index].name;
}

void ProgramBank::setProgramName(int index, const String new_name)
{
    programs[index].name = new_name;
}