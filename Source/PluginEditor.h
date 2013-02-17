/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  19 Feb 2012 11:38:05am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_PLUGINEDITOR_PLUGINEDITOR_47FE96EF__
#define __JUCER_HEADER_PLUGINEDITOR_PLUGINEDITOR_47FE96EF__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Debug.h"
#include "Plugin.h"

enum ComponentType {
    kSlider,
    kComboBox,
    kButton,
    kNoComponent
};
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
  Argotlunar 2.0 GUI
                                                                    //[/Comments]
*/
class PluginEditor  : public AudioProcessorEditor,
                      public Timer,
                      public SliderListener,
                      public ComboBoxListener,
                      public ButtonListener
{
public:
    //==============================================================================
    PluginEditor (Plugin* const ownerFilter);
    ~PluginEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    String* programNames;
    void changeProgram(int program);
    void updateGlissSliders(bool state);
    void updateTransSliders(bool state);
    void updateEnvSliders(int id);
    void updateScaleComponents(bool state);
    void setColour(bool style);
    void loadBankFile(Plugin* const plugin);
    void loadProgramFile(Plugin* const plugin);
    void saveBankFile(Plugin* const plugin);
    void saveProgramFile(Plugin* const plugin);

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Plugin* getPlugin() const throw() {
        return static_cast <Plugin*> (getAudioProcessor());
    }
    void updateParametersFromPlugin();
    void updateProgramNamesFromPlugin();
    int currentProgram;
    int num_programs;
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent3;
    GroupComponent* groupComponent2;
    GroupComponent* groupComponent20;
    GroupComponent* groupComponent18;
    GroupComponent* groupComponent5;
    GroupComponent* groupComponent15;
    GroupComponent* groupComponent9;
    GroupComponent* groupComponent;
    Slider* mix_slider;
    Label* label;
    Slider* ingain_slider;
    Label* label2;
    Slider* amp_slider;
    Label* label3;
    Slider* ampv_slider;
    Label* label4;
    Slider* pan_slider;
    Label* label5;
    Slider* panv_slider;
    Label* label6;
    Slider* delay_slider;
    Label* label7;
    Slider* delayv_slider;
    Slider* feedback_slider;
    Label* label9;
    Slider* gliss_slider;
    Label* label11;
    Slider* glissv_slider;
    Slider* trans_slider;
    Label* label13;
    Slider* transv_slider;
    Slider* iot_slider;
    Label* label15;
    Slider* iotv_slider;
    Slider* dur_slider;
    Label* label17;
    Slider* durv_slider;
    Slider* ffreq_slider;
    Label* label19;
    Slider* ffreqv_slider;
    Slider* fq_slider;
    Label* label21;
    Slider* fqv_slider;
    Slider* grains_slider;
    Label* label23;
    TextEditor* param_display;
    ComboBox* filtertype_combobox;
    TextButton* initButton;
    TextButton* saveButton;
    TextButton* savetoButton;
    TextButton* decPresetButton;
    TextButton* incPresetButton;
    ComboBox* program_combobox;
    Label* label25;
    Slider* envshape_slider;
    Slider* envskew_slider;
    Label* label26;
    Label* label27;
    Label* label28;
    ToggleButton* freeze_toggle_button;
    ComboBox* scale_combobox;
    Slider* scalekey_slider;
    Label* label24;
    GroupComponent* groupComponent17;
    Label* label29;
    ComboBox* matrix_src_combobox_1;
    ComboBox* matrix_dest_combobox_1;
    Slider* matrix_mod_slider_1;
    Label* label30;
    Label* label31;
    ComboBox* matrix_src_combobox_2;
    ComboBox* matrix_dest_combobox_2;
    Slider* matrix_mod_slider_2;
    Label* label34;
    Label* label35;
    ComboBox* matrix_src_combobox_3;
    ComboBox* matrix_dest_combobox_3;
    Slider* matrix_mod_slider_3;
    Label* label36;
    Label* label37;
    ToggleButton* matrix_mode_1_button;
    ToggleButton* matrix_mode_2_button;
    ToggleButton* matrix_mode_3_button;
    TextEditor* scalekey_display;
    ToggleButton* trans_toggle_button;
    ComboBox* envtype_combobox;
    ComboBox* dur_quant_combobox;
    ComboBox* iot_quant_combobox;
    ComboBox* delay_quant_combobox;
    Label* label8;
    Label* label16;
    Label* label18;
    Label* label12;
    Label* label14;
    Label* label20;
    Label* label22;
    Label* label32;
    ToggleButton* gliss_toggle_button;
    TextButton* optionsButton;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    PluginEditor (const PluginEditor&);
    const PluginEditor& operator= (const PluginEditor&);
};


#endif   // __JUCER_HEADER_PLUGINEDITOR_PLUGINEDITOR_47FE96EF__
