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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (Plugin* const ownerFilter)
    : AudioProcessorEditor(ownerFilter),
      groupComponent3 (0),
      groupComponent2 (0),
      groupComponent20 (0),
      groupComponent18 (0),
      groupComponent5 (0),
      groupComponent15 (0),
      groupComponent9 (0),
      groupComponent (0),
      mix_slider (0),
      label (0),
      ingain_slider (0),
      label2 (0),
      amp_slider (0),
      label3 (0),
      ampv_slider (0),
      label4 (0),
      pan_slider (0),
      label5 (0),
      panv_slider (0),
      label6 (0),
      delay_slider (0),
      label7 (0),
      delayv_slider (0),
      feedback_slider (0),
      label9 (0),
      gliss_slider (0),
      label11 (0),
      glissv_slider (0),
      trans_slider (0),
      label13 (0),
      transv_slider (0),
      iot_slider (0),
      label15 (0),
      iotv_slider (0),
      dur_slider (0),
      label17 (0),
      durv_slider (0),
      ffreq_slider (0),
      label19 (0),
      ffreqv_slider (0),
      fq_slider (0),
      label21 (0),
      fqv_slider (0),
      grains_slider (0),
      label23 (0),
      param_display (0),
      filtertype_combobox (0),
      initButton (0),
      saveButton (0),
      savetoButton (0),
      decPresetButton (0),
      incPresetButton (0),
      program_combobox (0),
      label25 (0),
      envshape_slider (0),
      envskew_slider (0),
      label26 (0),
      label27 (0),
      label28 (0),
      freeze_toggle_button (0),
      scale_combobox (0),
      scalekey_slider (0),
      label24 (0),
      groupComponent17 (0),
      label29 (0),
      matrix_src_combobox_1 (0),
      matrix_dest_combobox_1 (0),
      matrix_mod_slider_1 (0),
      label30 (0),
      label31 (0),
      matrix_src_combobox_2 (0),
      matrix_dest_combobox_2 (0),
      matrix_mod_slider_2 (0),
      label34 (0),
      label35 (0),
      matrix_src_combobox_3 (0),
      matrix_dest_combobox_3 (0),
      matrix_mod_slider_3 (0),
      label36 (0),
      label37 (0),
      matrix_mode_1_button (0),
      matrix_mode_2_button (0),
      matrix_mode_3_button (0),
      scalekey_display (0),
      trans_toggle_button (0),
      envtype_combobox (0),
      dur_quant_combobox (0),
      iot_quant_combobox (0),
      delay_quant_combobox (0),
      label8 (0),
      label16 (0),
      label18 (0),
      label12 (0),
      label14 (0),
      label20 (0),
      label22 (0),
      label32 (0),
      gliss_toggle_button (0),
      optionsButton (0)
{
    addAndMakeVisible (groupComponent3 = new GroupComponent (String::empty,
                                                             String::empty));
    groupComponent3->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent3->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent2 = new GroupComponent (String::empty,
                                                             String::empty));
    groupComponent2->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent2->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent20 = new GroupComponent (String::empty,
                                                              String::empty));
    groupComponent20->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent20->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent18 = new GroupComponent (String::empty,
                                                              String::empty));
    groupComponent18->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent18->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent5 = new GroupComponent (String::empty,
                                                             String::empty));
    groupComponent5->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent5->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent15 = new GroupComponent (String::empty,
                                                              String::empty));
    groupComponent15->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent15->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent9 = new GroupComponent (String::empty,
                                                             String::empty));
    groupComponent9->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent9->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent = new GroupComponent (String::empty,
                                                            String::empty));
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (mix_slider = new Slider (String::empty));
    mix_slider->setRange (0, 1, 0.001);
    mix_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    mix_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    mix_slider->setColour (Slider::thumbColourId, Colours::white);
    mix_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    mix_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    mix_slider->addListener (this);

    addAndMakeVisible (label = new Label (String::empty,
                                          L"Mix"));
    label->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (ingain_slider = new Slider (String::empty));
    ingain_slider->setRange (0, 1, 0.001);
    ingain_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    ingain_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ingain_slider->setColour (Slider::thumbColourId, Colours::white);
    ingain_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    ingain_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    ingain_slider->addListener (this);

    addAndMakeVisible (label2 = new Label (String::empty,
                                           L"InGain"));
    label2->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (amp_slider = new Slider (String::empty));
    amp_slider->setRange (0, 1, 0.001);
    amp_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    amp_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    amp_slider->setColour (Slider::thumbColourId, Colours::white);
    amp_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    amp_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    amp_slider->addListener (this);

    addAndMakeVisible (label3 = new Label (String::empty,
                                           L"Amp"));
    label3->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::white);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (ampv_slider = new Slider (String::empty));
    ampv_slider->setRange (0, 1, 0.001);
    ampv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    ampv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ampv_slider->setColour (Slider::thumbColourId, Colours::white);
    ampv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    ampv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    ampv_slider->addListener (this);

    addAndMakeVisible (label4 = new Label (String::empty,
                                           L"+"));
    label4->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colours::white);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (pan_slider = new Slider (String::empty));
    pan_slider->setRange (0, 1, 0.001);
    pan_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    pan_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pan_slider->setColour (Slider::thumbColourId, Colours::white);
    pan_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    pan_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    pan_slider->addListener (this);

    addAndMakeVisible (label5 = new Label (String::empty,
                                           L"Pan"));
    label5->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colours::white);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (panv_slider = new Slider (String::empty));
    panv_slider->setRange (0, 1, 0.001);
    panv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    panv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    panv_slider->setColour (Slider::thumbColourId, Colours::white);
    panv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    panv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    panv_slider->addListener (this);

    addAndMakeVisible (label6 = new Label (String::empty,
                                           L"+-"));
    label6->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colours::white);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (delay_slider = new Slider (String::empty));
    delay_slider->setRange (0, 1, 0.0005);
    delay_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    delay_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    delay_slider->setColour (Slider::thumbColourId, Colours::white);
    delay_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    delay_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    delay_slider->addListener (this);

    addAndMakeVisible (label7 = new Label (String::empty,
                                           L"Delay"));
    label7->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colours::white);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (delayv_slider = new Slider (String::empty));
    delayv_slider->setRange (0, 1, 0.0005);
    delayv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    delayv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    delayv_slider->setColour (Slider::thumbColourId, Colours::white);
    delayv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    delayv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    delayv_slider->addListener (this);

    addAndMakeVisible (feedback_slider = new Slider (String::empty));
    feedback_slider->setRange (0, 1, 0.001);
    feedback_slider->setSliderStyle (Slider::LinearHorizontal);
    feedback_slider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    feedback_slider->setColour (Slider::thumbColourId, Colours::white);
    feedback_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    feedback_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    feedback_slider->addListener (this);

    addAndMakeVisible (label9 = new Label (String::empty,
                                           L"Feedback"));
    label9->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label9->setJustificationType (Justification::centred);
    label9->setEditable (false, false, false);
    label9->setColour (Label::textColourId, Colours::white);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (gliss_slider = new Slider (String::empty));
    gliss_slider->setRange (0, 1, 0.001);
    gliss_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    gliss_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    gliss_slider->setColour (Slider::thumbColourId, Colours::white);
    gliss_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    gliss_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    gliss_slider->addListener (this);

    addAndMakeVisible (label11 = new Label (String::empty,
                                            L"Gliss"));
    label11->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label11->setJustificationType (Justification::centred);
    label11->setEditable (false, false, false);
    label11->setColour (Label::textColourId, Colours::white);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (glissv_slider = new Slider (String::empty));
    glissv_slider->setRange (0, 1, 0.001);
    glissv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    glissv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    glissv_slider->setColour (Slider::thumbColourId, Colours::white);
    glissv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    glissv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    glissv_slider->addListener (this);

    addAndMakeVisible (trans_slider = new Slider (String::empty));
    trans_slider->setRange (0, 1, 0.001);
    trans_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    trans_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    trans_slider->setColour (Slider::thumbColourId, Colours::white);
    trans_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    trans_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    trans_slider->addListener (this);

    addAndMakeVisible (label13 = new Label (String::empty,
                                            L"Trans"));
    label13->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label13->setJustificationType (Justification::centred);
    label13->setEditable (false, false, false);
    label13->setColour (Label::textColourId, Colours::white);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (transv_slider = new Slider (String::empty));
    transv_slider->setRange (0, 1, 0.001);
    transv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    transv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    transv_slider->setColour (Slider::thumbColourId, Colours::white);
    transv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    transv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    transv_slider->addListener (this);

    addAndMakeVisible (iot_slider = new Slider (String::empty));
    iot_slider->setRange (0, 1, 0.001);
    iot_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    iot_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    iot_slider->setColour (Slider::thumbColourId, Colours::white);
    iot_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    iot_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    iot_slider->addListener (this);

    addAndMakeVisible (label15 = new Label (String::empty,
                                            L"IOT"));
    label15->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label15->setJustificationType (Justification::centred);
    label15->setEditable (false, false, false);
    label15->setColour (Label::textColourId, Colours::white);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (iotv_slider = new Slider (String::empty));
    iotv_slider->setRange (0, 1, 0.001);
    iotv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    iotv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    iotv_slider->setColour (Slider::thumbColourId, Colours::white);
    iotv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    iotv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    iotv_slider->addListener (this);

    addAndMakeVisible (dur_slider = new Slider (String::empty));
    dur_slider->setRange (0, 1, 0.001);
    dur_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    dur_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    dur_slider->setColour (Slider::thumbColourId, Colours::white);
    dur_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    dur_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    dur_slider->addListener (this);

    addAndMakeVisible (label17 = new Label (String::empty,
                                            L"Dur"));
    label17->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label17->setJustificationType (Justification::centred);
    label17->setEditable (false, false, false);
    label17->setColour (Label::textColourId, Colours::white);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (durv_slider = new Slider (String::empty));
    durv_slider->setRange (0, 1, 0.001);
    durv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    durv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    durv_slider->setColour (Slider::thumbColourId, Colours::white);
    durv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    durv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    durv_slider->addListener (this);

    addAndMakeVisible (ffreq_slider = new Slider (String::empty));
    ffreq_slider->setRange (0, 1, 0.001);
    ffreq_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    ffreq_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ffreq_slider->setColour (Slider::thumbColourId, Colours::white);
    ffreq_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    ffreq_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    ffreq_slider->addListener (this);

    addAndMakeVisible (label19 = new Label (String::empty,
                                            L"FFreq"));
    label19->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label19->setJustificationType (Justification::centred);
    label19->setEditable (false, false, false);
    label19->setColour (Label::textColourId, Colours::white);
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (ffreqv_slider = new Slider (String::empty));
    ffreqv_slider->setRange (0, 1, 0.001);
    ffreqv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    ffreqv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ffreqv_slider->setColour (Slider::thumbColourId, Colours::white);
    ffreqv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    ffreqv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    ffreqv_slider->addListener (this);

    addAndMakeVisible (fq_slider = new Slider (String::empty));
    fq_slider->setRange (0, 1, 0.001);
    fq_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    fq_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    fq_slider->setColour (Slider::thumbColourId, Colours::white);
    fq_slider->setColour (Slider::trackColourId, Colour (0x7fffffff));
    fq_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    fq_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    fq_slider->addListener (this);

    addAndMakeVisible (label21 = new Label (String::empty,
                                            L"FQ"));
    label21->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label21->setJustificationType (Justification::centred);
    label21->setEditable (false, false, false);
    label21->setColour (Label::textColourId, Colours::white);
    label21->setColour (TextEditor::textColourId, Colours::black);
    label21->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (fqv_slider = new Slider (String::empty));
    fqv_slider->setRange (0, 1, 0.001);
    fqv_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    fqv_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    fqv_slider->setColour (Slider::thumbColourId, Colours::white);
    fqv_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    fqv_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    fqv_slider->addListener (this);

    addAndMakeVisible (grains_slider = new Slider (String::empty));
    grains_slider->setRange (0, 20, 1);
    grains_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    grains_slider->setTextBoxStyle (Slider::TextBoxRight, true, 32, 20);
    grains_slider->setColour (Slider::thumbColourId, Colours::white);
    grains_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    grains_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    grains_slider->setColour (Slider::textBoxTextColourId, Colours::white);
    grains_slider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff060827));
    grains_slider->addListener (this);

    addAndMakeVisible (label23 = new Label (String::empty,
                                            L"Grains"));
    label23->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label23->setJustificationType (Justification::centred);
    label23->setEditable (false, false, false);
    label23->setColour (Label::textColourId, Colours::white);
    label23->setColour (TextEditor::textColourId, Colours::black);
    label23->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (param_display = new TextEditor (String::empty));
    param_display->setMultiLine (false);
    param_display->setReturnKeyStartsNewLine (false);
    param_display->setReadOnly (true);
    param_display->setScrollbarsShown (false);
    param_display->setCaretVisible (false);
    param_display->setPopupMenuEnabled (false);
    param_display->setColour (TextEditor::textColourId, Colours::black);
    param_display->setText (String::empty);

    addAndMakeVisible (filtertype_combobox = new ComboBox (String::empty));
    filtertype_combobox->setEditableText (false);
    filtertype_combobox->setJustificationType (Justification::centred);
    filtertype_combobox->setTextWhenNothingSelected (String::empty);
    filtertype_combobox->setTextWhenNoChoicesAvailable (L"(no choices)");
    filtertype_combobox->addItem (L"off", 1);
    filtertype_combobox->addItem (L"band", 2);
    filtertype_combobox->addItem (L"low", 3);
    filtertype_combobox->addItem (L"high", 4);
    filtertype_combobox->addItem (L"notch", 5);
    filtertype_combobox->addItem (L"comb", 6);
    filtertype_combobox->addItem (L"random", 7);
    filtertype_combobox->addSeparator();
    filtertype_combobox->addListener (this);

    addAndMakeVisible (initButton = new TextButton (String::empty));
    initButton->setButtonText (L"Init");
    initButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    initButton->addListener (this);
    initButton->setColour (TextButton::buttonColourId, Colour (0xffdddddd));

    addAndMakeVisible (saveButton = new TextButton (String::empty));
    saveButton->setButtonText (L"Save");
    saveButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    saveButton->addListener (this);
    saveButton->setColour (TextButton::buttonColourId, Colour (0xffdddddd));

    addAndMakeVisible (savetoButton = new TextButton (String::empty));
    savetoButton->setButtonText (L"Save To");
    savetoButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    savetoButton->addListener (this);
    savetoButton->setColour (TextButton::buttonColourId, Colour (0xffdddddd));

    addAndMakeVisible (decPresetButton = new TextButton (String::empty));
    decPresetButton->setButtonText (L"-");
    decPresetButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    decPresetButton->addListener (this);
    decPresetButton->setColour (TextButton::buttonColourId, Colour (0xffdddddd));

    addAndMakeVisible (incPresetButton = new TextButton (String::empty));
    incPresetButton->setButtonText (L"+");
    incPresetButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    incPresetButton->addListener (this);
    incPresetButton->setColour (TextButton::buttonColourId, Colour (0xffdddddd));

    addAndMakeVisible (program_combobox = new ComboBox (String::empty));
    program_combobox->setEditableText (true);
    program_combobox->setJustificationType (Justification::centredLeft);
    program_combobox->setTextWhenNothingSelected (String::empty);
    program_combobox->setTextWhenNoChoicesAvailable (L"(no choices)");
    program_combobox->addListener (this);

    addAndMakeVisible (label25 = new Label (String::empty,
                                            L"Argotlunar v2.0.6"));
    label25->setFont (Font (16.0000f, Font::plain));
    label25->setJustificationType (Justification::centredLeft);
    label25->setEditable (false, false, false);
    label25->setColour (Label::textColourId, Colours::white);
    label25->setColour (TextEditor::textColourId, Colours::black);
    label25->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (envshape_slider = new Slider (String::empty));
    envshape_slider->setRange (0, 1, 0.001);
    envshape_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    envshape_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    envshape_slider->setColour (Slider::thumbColourId, Colours::white);
    envshape_slider->setColour (Slider::trackColourId, Colour (0x7fffffff));
    envshape_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    envshape_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    envshape_slider->addListener (this);

    addAndMakeVisible (envskew_slider = new Slider (String::empty));
    envskew_slider->setRange (0, 1, 0.001);
    envskew_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    envskew_slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    envskew_slider->setColour (Slider::thumbColourId, Colours::white);
    envskew_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    envskew_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    envskew_slider->addListener (this);

    addAndMakeVisible (label26 = new Label (String::empty,
                                            L"Sustain"));
    label26->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label26->setJustificationType (Justification::centred);
    label26->setEditable (false, false, false);
    label26->setColour (Label::textColourId, Colours::white);
    label26->setColour (TextEditor::textColourId, Colours::black);
    label26->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label27 = new Label (String::empty,
                                            L"Skew"));
    label27->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label27->setJustificationType (Justification::centred);
    label27->setEditable (false, false, false);
    label27->setColour (Label::textColourId, Colours::white);
    label27->setColour (TextEditor::textColourId, Colours::black);
    label27->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label28 = new Label (String::empty,
                                            L"Freeze"));
    label28->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label28->setJustificationType (Justification::centred);
    label28->setEditable (false, false, false);
    label28->setColour (Label::textColourId, Colours::white);
    label28->setColour (TextEditor::textColourId, Colours::black);
    label28->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (freeze_toggle_button = new ToggleButton (String::empty));
    freeze_toggle_button->addListener (this);
    freeze_toggle_button->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (scale_combobox = new ComboBox (String::empty));
    scale_combobox->setEditableText (false);
    scale_combobox->setJustificationType (Justification::centredLeft);
    scale_combobox->setTextWhenNothingSelected (String::empty);
    scale_combobox->setTextWhenNoChoicesAvailable (L"(no choices)");
    scale_combobox->addListener (this);

    addAndMakeVisible (scalekey_slider = new Slider (String::empty));
    scalekey_slider->setRange (0, 11, 1);
    scalekey_slider->setSliderStyle (Slider::RotaryVerticalDrag);
    scalekey_slider->setTextBoxStyle (Slider::NoTextBox, true, 40, 15);
    scalekey_slider->setColour (Slider::thumbColourId, Colours::white);
    scalekey_slider->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    scalekey_slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    scalekey_slider->setColour (Slider::textBoxTextColourId, Colours::white);
    scalekey_slider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff060827));
    scalekey_slider->addListener (this);

    addAndMakeVisible (label24 = new Label (String::empty,
                                            L"Key"));
    label24->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label24->setJustificationType (Justification::centred);
    label24->setEditable (false, false, false);
    label24->setColour (Label::textColourId, Colours::white);
    label24->setColour (TextEditor::textColourId, Colours::black);
    label24->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (groupComponent17 = new GroupComponent (String::empty,
                                                              String::empty));
    groupComponent17->setColour (GroupComponent::outlineColourId, Colour (0x66c1c1c1));
    groupComponent17->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (label29 = new Label (String::empty,
                                            L"Correlation Matrix"));
    label29->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label29->setJustificationType (Justification::centred);
    label29->setEditable (false, false, false);
    label29->setColour (Label::textColourId, Colours::white);
    label29->setColour (TextEditor::textColourId, Colours::black);
    label29->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (matrix_src_combobox_1 = new ComboBox (String::empty));
    matrix_src_combobox_1->setEditableText (false);
    matrix_src_combobox_1->setJustificationType (Justification::centredLeft);
    matrix_src_combobox_1->setTextWhenNothingSelected (String::empty);
    matrix_src_combobox_1->setTextWhenNoChoicesAvailable (L"(no choices)");
    matrix_src_combobox_1->addItem (L"Off", 1);
    matrix_src_combobox_1->addItem (L"Amp", 2);
    matrix_src_combobox_1->addItem (L"Pan L/R", 3);
    matrix_src_combobox_1->addItem (L"Pan Width", 4);
    matrix_src_combobox_1->addItem (L"Delay", 5);
    matrix_src_combobox_1->addItem (L"IOT", 6);
    matrix_src_combobox_1->addItem (L"Dur", 7);
    matrix_src_combobox_1->addItem (L"Trans", 8);
    matrix_src_combobox_1->addItem (L"Gliss", 9);
    matrix_src_combobox_1->addItem (L"FFreq", 10);
    matrix_src_combobox_1->addItem (L"FQ", 11);
    matrix_src_combobox_1->addListener (this);

    addAndMakeVisible (matrix_dest_combobox_1 = new ComboBox (String::empty));
    matrix_dest_combobox_1->setEditableText (false);
    matrix_dest_combobox_1->setJustificationType (Justification::centredLeft);
    matrix_dest_combobox_1->setTextWhenNothingSelected (String::empty);
    matrix_dest_combobox_1->setTextWhenNoChoicesAvailable (L"(no choices)");
    matrix_dest_combobox_1->addItem (L"Off", 1);
    matrix_dest_combobox_1->addItem (L"Amp", 2);
    matrix_dest_combobox_1->addItem (L"Pan L/R", 3);
    matrix_dest_combobox_1->addItem (L"Delay", 4);
    matrix_dest_combobox_1->addItem (L"IOT", 5);
    matrix_dest_combobox_1->addItem (L"Dur", 6);
    matrix_dest_combobox_1->addItem (L"Trans", 7);
    matrix_dest_combobox_1->addItem (L"Gliss", 8);
    matrix_dest_combobox_1->addItem (L"FFreq", 9);
    matrix_dest_combobox_1->addItem (L"FQ", 10);
    matrix_dest_combobox_1->addItem (L"Sustain", 11);
    matrix_dest_combobox_1->addItem (L"Skew", 12);
    matrix_dest_combobox_1->addSeparator();
    matrix_dest_combobox_1->addListener (this);

    addAndMakeVisible (matrix_mod_slider_1 = new Slider (String::empty));
    matrix_mod_slider_1->setRange (-100, 100, 1);
    matrix_mod_slider_1->setSliderStyle (Slider::LinearHorizontal);
    matrix_mod_slider_1->setTextBoxStyle (Slider::NoTextBox, true, 40, 15);
    matrix_mod_slider_1->setColour (Slider::thumbColourId, Colours::white);
    matrix_mod_slider_1->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    matrix_mod_slider_1->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    matrix_mod_slider_1->setColour (Slider::textBoxTextColourId, Colours::white);
    matrix_mod_slider_1->setColour (Slider::textBoxBackgroundColourId, Colour (0xff060827));
    matrix_mod_slider_1->addListener (this);

    addAndMakeVisible (label30 = new Label (String::empty,
                                            L"Src"));
    label30->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label30->setJustificationType (Justification::centred);
    label30->setEditable (false, false, false);
    label30->setColour (Label::textColourId, Colours::white);
    label30->setColour (TextEditor::textColourId, Colours::black);
    label30->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label31 = new Label (String::empty,
                                            L"Dest"));
    label31->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label31->setJustificationType (Justification::centred);
    label31->setEditable (false, false, false);
    label31->setColour (Label::textColourId, Colours::white);
    label31->setColour (TextEditor::textColourId, Colours::black);
    label31->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (matrix_src_combobox_2 = new ComboBox (String::empty));
    matrix_src_combobox_2->setEditableText (false);
    matrix_src_combobox_2->setJustificationType (Justification::centredLeft);
    matrix_src_combobox_2->setTextWhenNothingSelected (String::empty);
    matrix_src_combobox_2->setTextWhenNoChoicesAvailable (L"(no choices)");
    matrix_src_combobox_2->addItem (L"Off", 1);
    matrix_src_combobox_2->addItem (L"Amp", 2);
    matrix_src_combobox_2->addItem (L"Pan L/R", 3);
    matrix_src_combobox_2->addItem (L"Pan Width", 4);
    matrix_src_combobox_2->addItem (L"Delay", 5);
    matrix_src_combobox_2->addItem (L"IOT", 6);
    matrix_src_combobox_2->addItem (L"Dur", 7);
    matrix_src_combobox_2->addItem (L"Trans", 8);
    matrix_src_combobox_2->addItem (L"Gliss", 9);
    matrix_src_combobox_2->addItem (L"FFreq", 10);
    matrix_src_combobox_2->addItem (L"FQ", 11);
    matrix_src_combobox_2->addListener (this);

    addAndMakeVisible (matrix_dest_combobox_2 = new ComboBox (String::empty));
    matrix_dest_combobox_2->setEditableText (false);
    matrix_dest_combobox_2->setJustificationType (Justification::centredLeft);
    matrix_dest_combobox_2->setTextWhenNothingSelected (String::empty);
    matrix_dest_combobox_2->setTextWhenNoChoicesAvailable (L"(no choices)");
    matrix_dest_combobox_2->addItem (L"Off", 1);
    matrix_dest_combobox_2->addItem (L"Amp", 2);
    matrix_dest_combobox_2->addItem (L"Pan L/R", 3);
    matrix_dest_combobox_2->addItem (L"Delay", 4);
    matrix_dest_combobox_2->addItem (L"IOT", 5);
    matrix_dest_combobox_2->addItem (L"Dur", 6);
    matrix_dest_combobox_2->addItem (L"Trans", 7);
    matrix_dest_combobox_2->addItem (L"Gliss", 8);
    matrix_dest_combobox_2->addItem (L"FFreq", 9);
    matrix_dest_combobox_2->addItem (L"FQ", 10);
    matrix_dest_combobox_2->addItem (L"Sustain", 11);
    matrix_dest_combobox_2->addItem (L"Skew", 12);
    matrix_dest_combobox_2->addSeparator();
    matrix_dest_combobox_2->addListener (this);

    addAndMakeVisible (matrix_mod_slider_2 = new Slider (String::empty));
    matrix_mod_slider_2->setRange (-100, 100, 1);
    matrix_mod_slider_2->setSliderStyle (Slider::LinearHorizontal);
    matrix_mod_slider_2->setTextBoxStyle (Slider::NoTextBox, true, 40, 15);
    matrix_mod_slider_2->setColour (Slider::thumbColourId, Colours::white);
    matrix_mod_slider_2->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    matrix_mod_slider_2->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    matrix_mod_slider_2->setColour (Slider::textBoxTextColourId, Colours::white);
    matrix_mod_slider_2->setColour (Slider::textBoxBackgroundColourId, Colour (0xff060827));
    matrix_mod_slider_2->addListener (this);

    addAndMakeVisible (label34 = new Label (String::empty,
                                            L"Src"));
    label34->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label34->setJustificationType (Justification::centred);
    label34->setEditable (false, false, false);
    label34->setColour (Label::textColourId, Colours::white);
    label34->setColour (TextEditor::textColourId, Colours::black);
    label34->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label35 = new Label (String::empty,
                                            L"Dest"));
    label35->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label35->setJustificationType (Justification::centred);
    label35->setEditable (false, false, false);
    label35->setColour (Label::textColourId, Colours::white);
    label35->setColour (TextEditor::textColourId, Colours::black);
    label35->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (matrix_src_combobox_3 = new ComboBox (String::empty));
    matrix_src_combobox_3->setEditableText (false);
    matrix_src_combobox_3->setJustificationType (Justification::centredLeft);
    matrix_src_combobox_3->setTextWhenNothingSelected (String::empty);
    matrix_src_combobox_3->setTextWhenNoChoicesAvailable (L"(no choices)");
    matrix_src_combobox_3->addItem (L"Off", 1);
    matrix_src_combobox_3->addItem (L"Amp", 2);
    matrix_src_combobox_3->addItem (L"Pan L/R", 3);
    matrix_src_combobox_3->addItem (L"Pan Width", 4);
    matrix_src_combobox_3->addItem (L"Delay", 5);
    matrix_src_combobox_3->addItem (L"IOT", 6);
    matrix_src_combobox_3->addItem (L"Dur", 7);
    matrix_src_combobox_3->addItem (L"Trans", 8);
    matrix_src_combobox_3->addItem (L"Gliss", 9);
    matrix_src_combobox_3->addItem (L"FFreq", 10);
    matrix_src_combobox_3->addItem (L"FQ", 11);
    matrix_src_combobox_3->addListener (this);

    addAndMakeVisible (matrix_dest_combobox_3 = new ComboBox (String::empty));
    matrix_dest_combobox_3->setEditableText (false);
    matrix_dest_combobox_3->setJustificationType (Justification::centredLeft);
    matrix_dest_combobox_3->setTextWhenNothingSelected (String::empty);
    matrix_dest_combobox_3->setTextWhenNoChoicesAvailable (L"(no choices)");
    matrix_dest_combobox_3->addItem (L"Off", 1);
    matrix_dest_combobox_3->addItem (L"Amp", 2);
    matrix_dest_combobox_3->addItem (L"Pan L/R", 3);
    matrix_dest_combobox_3->addItem (L"Delay", 4);
    matrix_dest_combobox_3->addItem (L"IOT", 5);
    matrix_dest_combobox_3->addItem (L"Dur", 6);
    matrix_dest_combobox_3->addItem (L"Trans", 7);
    matrix_dest_combobox_3->addItem (L"Gliss", 8);
    matrix_dest_combobox_3->addItem (L"FFreq", 9);
    matrix_dest_combobox_3->addItem (L"FQ", 10);
    matrix_dest_combobox_3->addItem (L"Sustain", 11);
    matrix_dest_combobox_3->addItem (L"Skew", 12);
    matrix_dest_combobox_3->addSeparator();
    matrix_dest_combobox_3->addListener (this);

    addAndMakeVisible (matrix_mod_slider_3 = new Slider (String::empty));
    matrix_mod_slider_3->setRange (-100, 100, 1);
    matrix_mod_slider_3->setSliderStyle (Slider::LinearHorizontal);
    matrix_mod_slider_3->setTextBoxStyle (Slider::NoTextBox, true, 40, 15);
    matrix_mod_slider_3->setColour (Slider::thumbColourId, Colours::white);
    matrix_mod_slider_3->setColour (Slider::rotarySliderFillColourId, Colour (0xfbffffff));
    matrix_mod_slider_3->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3c3c54));
    matrix_mod_slider_3->setColour (Slider::textBoxTextColourId, Colours::white);
    matrix_mod_slider_3->setColour (Slider::textBoxBackgroundColourId, Colour (0xff060827));
    matrix_mod_slider_3->addListener (this);

    addAndMakeVisible (label36 = new Label (String::empty,
                                            L"Src"));
    label36->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label36->setJustificationType (Justification::centred);
    label36->setEditable (false, false, false);
    label36->setColour (Label::textColourId, Colours::white);
    label36->setColour (TextEditor::textColourId, Colours::black);
    label36->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label37 = new Label (String::empty,
                                            L"Dest"));
    label37->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label37->setJustificationType (Justification::centred);
    label37->setEditable (false, false, false);
    label37->setColour (Label::textColourId, Colours::white);
    label37->setColour (TextEditor::textColourId, Colours::black);
    label37->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (matrix_mode_1_button = new ToggleButton (String::empty));
    matrix_mode_1_button->addListener (this);
    matrix_mode_1_button->setToggleState (true, false);
    matrix_mode_1_button->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (matrix_mode_2_button = new ToggleButton (String::empty));
    matrix_mode_2_button->addListener (this);
    matrix_mode_2_button->setToggleState (true, false);
    matrix_mode_2_button->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (matrix_mode_3_button = new ToggleButton (String::empty));
    matrix_mode_3_button->addListener (this);
    matrix_mode_3_button->setToggleState (true, false);
    matrix_mode_3_button->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (scalekey_display = new TextEditor (String::empty));
    scalekey_display->setMultiLine (false);
    scalekey_display->setReturnKeyStartsNewLine (false);
    scalekey_display->setReadOnly (true);
    scalekey_display->setScrollbarsShown (false);
    scalekey_display->setCaretVisible (false);
    scalekey_display->setPopupMenuEnabled (false);
    scalekey_display->setColour (TextEditor::textColourId, Colours::white);
    scalekey_display->setColour (TextEditor::backgroundColourId, Colour (0xff060827));
    scalekey_display->setColour (TextEditor::outlineColourId, Colour (0xff3c3c54));
    scalekey_display->setText (String::empty);

    addAndMakeVisible (trans_toggle_button = new ToggleButton (String::empty));
    trans_toggle_button->addListener (this);
    trans_toggle_button->setToggleState (true, false);
    trans_toggle_button->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (envtype_combobox = new ComboBox (String::empty));
    envtype_combobox->setEditableText (false);
    envtype_combobox->setJustificationType (Justification::centredLeft);
    envtype_combobox->setTextWhenNothingSelected (String::empty);
    envtype_combobox->setTextWhenNoChoicesAvailable (L"(no choices)");
    envtype_combobox->addItem (L"RCB", 1);
    envtype_combobox->addItem (L"parabola", 2);
    envtype_combobox->addItem (L"triangle", 3);
    envtype_combobox->addListener (this);

    addAndMakeVisible (dur_quant_combobox = new ComboBox (String::empty));
    dur_quant_combobox->setEditableText (false);
    dur_quant_combobox->setJustificationType (Justification::centredLeft);
    dur_quant_combobox->setTextWhenNothingSelected (String::empty);
    dur_quant_combobox->setTextWhenNoChoicesAvailable (L"(no choices)");
    dur_quant_combobox->addItem (L"ms", 1);
    dur_quant_combobox->addItem (L"128", 2);
    dur_quant_combobox->addItem (L"128T", 3);
    dur_quant_combobox->addItem (L"64", 4);
    dur_quant_combobox->addItem (L"64T", 5);
    dur_quant_combobox->addItem (L"32", 6);
    dur_quant_combobox->addItem (L"32T", 7);
    dur_quant_combobox->addItem (L"16", 8);
    dur_quant_combobox->addItem (L"16T", 9);
    dur_quant_combobox->addItem (L"8", 10);
    dur_quant_combobox->addItem (L"8T", 11);
    dur_quant_combobox->addItem (L"4", 12);
    dur_quant_combobox->addItem (L"4T", 13);
    dur_quant_combobox->addItem (L"long", 14);
    dur_quant_combobox->addListener (this);

    addAndMakeVisible (iot_quant_combobox = new ComboBox (String::empty));
    iot_quant_combobox->setEditableText (false);
    iot_quant_combobox->setJustificationType (Justification::centredLeft);
    iot_quant_combobox->setTextWhenNothingSelected (String::empty);
    iot_quant_combobox->setTextWhenNoChoicesAvailable (L"(no choices)");
    iot_quant_combobox->addItem (L"ms", 1);
    iot_quant_combobox->addItem (L"128", 2);
    iot_quant_combobox->addItem (L"128T", 3);
    iot_quant_combobox->addItem (L"64", 4);
    iot_quant_combobox->addItem (L"64T", 5);
    iot_quant_combobox->addItem (L"32", 6);
    iot_quant_combobox->addItem (L"32T", 7);
    iot_quant_combobox->addItem (L"16", 8);
    iot_quant_combobox->addItem (L"16T", 9);
    iot_quant_combobox->addItem (L"8", 10);
    iot_quant_combobox->addItem (L"8T", 11);
    iot_quant_combobox->addItem (L"4", 12);
    iot_quant_combobox->addItem (L"4T", 13);
    iot_quant_combobox->addListener (this);

    addAndMakeVisible (delay_quant_combobox = new ComboBox (String::empty));
    delay_quant_combobox->setEditableText (false);
    delay_quant_combobox->setJustificationType (Justification::centredLeft);
    delay_quant_combobox->setTextWhenNothingSelected (String::empty);
    delay_quant_combobox->setTextWhenNoChoicesAvailable (L"(no choices)");
    delay_quant_combobox->addItem (L"ms", 1);
    delay_quant_combobox->addItem (L"128", 2);
    delay_quant_combobox->addItem (L"128T", 3);
    delay_quant_combobox->addItem (L"64", 4);
    delay_quant_combobox->addItem (L"64T", 5);
    delay_quant_combobox->addItem (L"32", 6);
    delay_quant_combobox->addItem (L"32T", 7);
    delay_quant_combobox->addItem (L"16", 8);
    delay_quant_combobox->addItem (L"16T", 9);
    delay_quant_combobox->addItem (L"8", 10);
    delay_quant_combobox->addItem (L"8T", 11);
    delay_quant_combobox->addItem (L"4", 12);
    delay_quant_combobox->addItem (L"4T", 13);
    delay_quant_combobox->addListener (this);

    addAndMakeVisible (label8 = new Label (String::empty,
                                           L"+"));
    label8->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label8->setJustificationType (Justification::centred);
    label8->setEditable (false, false, false);
    label8->setColour (Label::textColourId, Colours::white);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label16 = new Label (String::empty,
                                            L"+"));
    label16->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label16->setJustificationType (Justification::centred);
    label16->setEditable (false, false, false);
    label16->setColour (Label::textColourId, Colours::white);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label18 = new Label (String::empty,
                                            L"+"));
    label18->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label18->setJustificationType (Justification::centred);
    label18->setEditable (false, false, false);
    label18->setColour (Label::textColourId, Colours::white);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label12 = new Label (String::empty,
                                            L"+-"));
    label12->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label12->setJustificationType (Justification::centred);
    label12->setEditable (false, false, false);
    label12->setColour (Label::textColourId, Colours::white);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label14 = new Label (String::empty,
                                            L"+-"));
    label14->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label14->setJustificationType (Justification::centred);
    label14->setEditable (false, false, false);
    label14->setColour (Label::textColourId, Colours::white);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label20 = new Label (String::empty,
                                            L"+"));
    label20->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label20->setJustificationType (Justification::centred);
    label20->setEditable (false, false, false);
    label20->setColour (Label::textColourId, Colours::white);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label22 = new Label (String::empty,
                                            L"+"));
    label22->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label22->setJustificationType (Justification::centred);
    label22->setEditable (false, false, false);
    label22->setColour (Label::textColourId, Colours::white);
    label22->setColour (TextEditor::textColourId, Colours::black);
    label22->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label32 = new Label (String::empty,
                                            L"Scale"));
    label32->setFont (Font (Font::getDefaultSansSerifFontName(), 14.0000f, Font::plain));
    label32->setJustificationType (Justification::centred);
    label32->setEditable (false, false, false);
    label32->setColour (Label::textColourId, Colours::white);
    label32->setColour (TextEditor::textColourId, Colours::black);
    label32->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (gliss_toggle_button = new ToggleButton (String::empty));
    gliss_toggle_button->addListener (this);
    gliss_toggle_button->setToggleState (true, false);
    gliss_toggle_button->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (optionsButton = new TextButton (String::empty));
    optionsButton->setButtonText (L"Options");
    optionsButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    optionsButton->addListener (this);
    optionsButton->setColour (TextButton::buttonColourId, Colour (0xffdddddd));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (780, 225);


    //[Constructor] You can add your own custom stuff here..
    Plugin* const plugin = getPlugin();
    num_programs = plugin->kNumPrograms;
    programNames = new String[num_programs];
    for(int i = 0; i < num_programs; i++) {
        programNames[i] = "-";
        program_combobox->addItem(programNames[i], i + 1);
    }
    updateParametersFromPlugin();
    updateProgramNamesFromPlugin();
    addMouseListener(this, true);
    startTimer (50);
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent3);
    deleteAndZero (groupComponent2);
    deleteAndZero (groupComponent20);
    deleteAndZero (groupComponent18);
    deleteAndZero (groupComponent5);
    deleteAndZero (groupComponent15);
    deleteAndZero (groupComponent9);
    deleteAndZero (groupComponent);
    deleteAndZero (mix_slider);
    deleteAndZero (label);
    deleteAndZero (ingain_slider);
    deleteAndZero (label2);
    deleteAndZero (amp_slider);
    deleteAndZero (label3);
    deleteAndZero (ampv_slider);
    deleteAndZero (label4);
    deleteAndZero (pan_slider);
    deleteAndZero (label5);
    deleteAndZero (panv_slider);
    deleteAndZero (label6);
    deleteAndZero (delay_slider);
    deleteAndZero (label7);
    deleteAndZero (delayv_slider);
    deleteAndZero (feedback_slider);
    deleteAndZero (label9);
    deleteAndZero (gliss_slider);
    deleteAndZero (label11);
    deleteAndZero (glissv_slider);
    deleteAndZero (trans_slider);
    deleteAndZero (label13);
    deleteAndZero (transv_slider);
    deleteAndZero (iot_slider);
    deleteAndZero (label15);
    deleteAndZero (iotv_slider);
    deleteAndZero (dur_slider);
    deleteAndZero (label17);
    deleteAndZero (durv_slider);
    deleteAndZero (ffreq_slider);
    deleteAndZero (label19);
    deleteAndZero (ffreqv_slider);
    deleteAndZero (fq_slider);
    deleteAndZero (label21);
    deleteAndZero (fqv_slider);
    deleteAndZero (grains_slider);
    deleteAndZero (label23);
    deleteAndZero (param_display);
    deleteAndZero (filtertype_combobox);
    deleteAndZero (initButton);
    deleteAndZero (saveButton);
    deleteAndZero (savetoButton);
    deleteAndZero (decPresetButton);
    deleteAndZero (incPresetButton);
    deleteAndZero (program_combobox);
    deleteAndZero (label25);
    deleteAndZero (envshape_slider);
    deleteAndZero (envskew_slider);
    deleteAndZero (label26);
    deleteAndZero (label27);
    deleteAndZero (label28);
    deleteAndZero (freeze_toggle_button);
    deleteAndZero (scale_combobox);
    deleteAndZero (scalekey_slider);
    deleteAndZero (label24);
    deleteAndZero (groupComponent17);
    deleteAndZero (label29);
    deleteAndZero (matrix_src_combobox_1);
    deleteAndZero (matrix_dest_combobox_1);
    deleteAndZero (matrix_mod_slider_1);
    deleteAndZero (label30);
    deleteAndZero (label31);
    deleteAndZero (matrix_src_combobox_2);
    deleteAndZero (matrix_dest_combobox_2);
    deleteAndZero (matrix_mod_slider_2);
    deleteAndZero (label34);
    deleteAndZero (label35);
    deleteAndZero (matrix_src_combobox_3);
    deleteAndZero (matrix_dest_combobox_3);
    deleteAndZero (matrix_mod_slider_3);
    deleteAndZero (label36);
    deleteAndZero (label37);
    deleteAndZero (matrix_mode_1_button);
    deleteAndZero (matrix_mode_2_button);
    deleteAndZero (matrix_mode_3_button);
    deleteAndZero (scalekey_display);
    deleteAndZero (trans_toggle_button);
    deleteAndZero (envtype_combobox);
    deleteAndZero (dur_quant_combobox);
    deleteAndZero (iot_quant_combobox);
    deleteAndZero (delay_quant_combobox);
    deleteAndZero (label8);
    deleteAndZero (label16);
    deleteAndZero (label18);
    deleteAndZero (label12);
    deleteAndZero (label14);
    deleteAndZero (label20);
    deleteAndZero (label22);
    deleteAndZero (label32);
    deleteAndZero (gliss_toggle_button);
    deleteAndZero (optionsButton);


    //[Destructor]. You can add your own custom destruction code here..
    deleteAllChildren();
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff05122b));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    groupComponent3->setBounds (0, 108, 176, 44);
    groupComponent2->setBounds (0, -4, 64, 120);
    groupComponent20->setBounds (572, -4, 80, 156);
    groupComponent18->setBounds (456, -4, 116, 156);
    groupComponent5->setBounds (340, -4, 116, 156);
    groupComponent15->setBounds (1, 146, 651, 46);
    groupComponent9->setBounds (176, -4, 164, 156);
    groupComponent->setBounds (64, -4, 112, 120);
    mix_slider->setBounds (14, 12, 32, 32);
    label->setBounds (4, 40, 52, 16);
    ingain_slider->setBounds (14, 58, 32, 32);
    label2->setBounds (4, 86, 52, 16);
    amp_slider->setBounds (76, 12, 32, 32);
    label3->setBounds (68, 44, 48, 16);
    ampv_slider->setBounds (76, 60, 32, 32);
    label4->setBounds (68, 92, 48, 16);
    pan_slider->setBounds (128, 12, 32, 32);
    label5->setBounds (120, 44, 48, 16);
    panv_slider->setBounds (128, 60, 32, 32);
    label6->setBounds (120, 92, 48, 16);
    delay_slider->setBounds (188, 12, 32, 32);
    label7->setBounds (180, 44, 48, 16);
    delayv_slider->setBounds (188, 60, 32, 32);
    feedback_slider->setBounds (68, 118, 104, 30);
    label9->setBounds (4, 124, 58, 16);
    gliss_slider->setBounds (408, 12, 32, 32);
    label11->setBounds (400, 44, 48, 16);
    glissv_slider->setBounds (408, 60, 32, 32);
    trans_slider->setBounds (356, 12, 32, 32);
    label13->setBounds (348, 44, 48, 16);
    transv_slider->setBounds (356, 60, 32, 32);
    iot_slider->setBounds (244, 12, 32, 32);
    label15->setBounds (236, 44, 48, 16);
    iotv_slider->setBounds (244, 60, 32, 32);
    dur_slider->setBounds (296, 12, 32, 32);
    label17->setBounds (288, 44, 48, 16);
    durv_slider->setBounds (296, 60, 32, 32);
    ffreq_slider->setBounds (472, 12, 32, 32);
    label19->setBounds (464, 44, 48, 16);
    ffreqv_slider->setBounds (472, 60, 32, 32);
    fq_slider->setBounds (524, 12, 32, 32);
    label21->setBounds (516, 44, 48, 16);
    fqv_slider->setBounds (524, 60, 32, 32);
    grains_slider->setBounds (44, 158, 64, 28);
    label23->setBounds (5, 162, 45, 20);
    param_display->setBounds (178, 162, 218, 18);
    filtertype_combobox->setBounds (465, 120, 98, 18);
    initButton->setBounds (8, 199, 42, 20);
    saveButton->setBounds (50, 199, 42, 20);
    savetoButton->setBounds (92, 199, 42, 20);
    decPresetButton->setBounds (142, 199, 24, 20);
    incPresetButton->setBounds (166, 199, 24, 20);
    program_combobox->setBounds (190, 199, 209, 20);
    label25->setBounds (532, 199, 118, 20);
    envshape_slider->setBounds (595, 12, 32, 32);
    envskew_slider->setBounds (595, 60, 32, 32);
    label26->setBounds (584, 44, 56, 16);
    label27->setBounds (584, 92, 56, 16);
    label28->setBounds (106, 162, 48, 20);
    freeze_toggle_button->setBounds (152, 162, 24, 20);
    scale_combobox->setBounds (440, 162, 108, 18);
    scalekey_slider->setBounds (574, 158, 40, 30);
    label24->setBounds (546, 162, 34, 20);
    groupComponent17->setBounds (652, -4, 128, 231);
    label29->setBounds (656, 9, 118, 20);
    matrix_src_combobox_1->setBounds (696, 33, 74, 16);
    matrix_dest_combobox_1->setBounds (696, 53, 74, 16);
    matrix_mod_slider_1->setBounds (656, 73, 100, 20);
    label30->setBounds (658, 31, 36, 16);
    label31->setBounds (658, 51, 36, 16);
    matrix_src_combobox_2->setBounds (696, 97, 74, 16);
    matrix_dest_combobox_2->setBounds (696, 117, 74, 16);
    matrix_mod_slider_2->setBounds (654, 138, 100, 20);
    label34->setBounds (658, 95, 36, 16);
    label35->setBounds (658, 115, 36, 16);
    matrix_src_combobox_3->setBounds (696, 161, 74, 16);
    matrix_dest_combobox_3->setBounds (696, 181, 74, 16);
    matrix_mod_slider_3->setBounds (655, 201, 100, 20);
    label36->setBounds (658, 161, 36, 16);
    label37->setBounds (658, 181, 36, 16);
    matrix_mode_1_button->setBounds (754, 72, 20, 20);
    matrix_mode_2_button->setBounds (754, 136, 20, 20);
    matrix_mode_3_button->setBounds (753, 201, 20, 20);
    scalekey_display->setBounds (612, 162, 31, 20);
    trans_toggle_button->setBounds (360, 120, 24, 20);
    envtype_combobox->setBounds (577, 120, 69, 18);
    dur_quant_combobox->setBounds (286, 120, 48, 18);
    iot_quant_combobox->setBounds (234, 120, 48, 18);
    delay_quant_combobox->setBounds (184, 120, 48, 18);
    label8->setBounds (180, 92, 48, 16);
    label16->setBounds (236, 92, 48, 16);
    label18->setBounds (288, 92, 48, 16);
    label12->setBounds (348, 92, 48, 16);
    label14->setBounds (401, 92, 48, 16);
    label20->setBounds (463, 92, 48, 16);
    label22->setBounds (516, 92, 48, 16);
    label32->setBounds (400, 162, 40, 20);
    gliss_toggle_button->setBounds (412, 120, 24, 20);
    optionsButton->setBounds (407, 199, 48, 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    float value = (float)sliderThatWasMoved->getValue();
    int index = -1;
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == mix_slider)
    {
        //[UserSliderCode_mix_slider] -- add your slider handling code here..
        index = kMix;
        //[/UserSliderCode_mix_slider]
    }
    else if (sliderThatWasMoved == ingain_slider)
    {
        //[UserSliderCode_ingain_slider] -- add your slider handling code here..
        index = kIngain;
        //[/UserSliderCode_ingain_slider]
    }
    else if (sliderThatWasMoved == amp_slider)
    {
        //[UserSliderCode_amp_slider] -- add your slider handling code here..
        index = kAmp;
        //[/UserSliderCode_amp_slider]
    }
    else if (sliderThatWasMoved == ampv_slider)
    {
        //[UserSliderCode_ampv_slider] -- add your slider handling code here..
        index = kAmpv;
        //[/UserSliderCode_ampv_slider]
    }
    else if (sliderThatWasMoved == pan_slider)
    {
        //[UserSliderCode_pan_slider] -- add your slider handling code here..
        index = kPan;
        //[/UserSliderCode_pan_slider]
    }
    else if (sliderThatWasMoved == panv_slider)
    {
        //[UserSliderCode_panv_slider] -- add your slider handling code here..
        index = kPanv;
        //[/UserSliderCode_panv_slider]
    }
    else if (sliderThatWasMoved == delay_slider)
    {
        //[UserSliderCode_delay_slider] -- add your slider handling code here..
        index = kDelay;
        //[/UserSliderCode_delay_slider]
    }
    else if (sliderThatWasMoved == delayv_slider)
    {
        //[UserSliderCode_delayv_slider] -- add your slider handling code here..
        index = kDelayv;
        //[/UserSliderCode_delayv_slider]
    }
    else if (sliderThatWasMoved == feedback_slider)
    {
        //[UserSliderCode_feedback_slider] -- add your slider handling code here..
        index = kFeedback;
        //[/UserSliderCode_feedback_slider]
    }
    else if (sliderThatWasMoved == gliss_slider)
    {
        //[UserSliderCode_gliss_slider] -- add your slider handling code here..
        index = kGliss;
        //[/UserSliderCode_gliss_slider]
    }
    else if (sliderThatWasMoved == glissv_slider)
    {
        //[UserSliderCode_glissv_slider] -- add your slider handling code here..
        index = kGlissv;
        //[/UserSliderCode_glissv_slider]
    }
    else if (sliderThatWasMoved == trans_slider)
    {
        //[UserSliderCode_trans_slider] -- add your slider handling code here..
        index = kTrans;
        //[/UserSliderCode_trans_slider]
    }
    else if (sliderThatWasMoved == transv_slider)
    {
        //[UserSliderCode_transv_slider] -- add your slider handling code here..
        index = kTransv;
        //[/UserSliderCode_transv_slider]
    }
    else if (sliderThatWasMoved == iot_slider)
    {
        //[UserSliderCode_iot_slider] -- add your slider handling code here..
        index = kIot;
        //[/UserSliderCode_iot_slider]
    }
    else if (sliderThatWasMoved == iotv_slider)
    {
        //[UserSliderCode_iotv_slider] -- add your slider handling code here..
        index = kIotv;
        //[/UserSliderCode_iotv_slider]
    }
    else if (sliderThatWasMoved == dur_slider)
    {
        //[UserSliderCode_dur_slider] -- add your slider handling code here..
        index = kDur;
        //[/UserSliderCode_dur_slider]
    }
    else if (sliderThatWasMoved == durv_slider)
    {
        //[UserSliderCode_durv_slider] -- add your slider handling code here..
        index = kDurv;
        //[/UserSliderCode_durv_slider]
    }
    else if (sliderThatWasMoved == ffreq_slider)
    {
        //[UserSliderCode_ffreq_slider] -- add your slider handling code here..
        index = kFfreq;
        //[/UserSliderCode_ffreq_slider]
    }
    else if (sliderThatWasMoved == ffreqv_slider)
    {
        //[UserSliderCode_ffreqv_slider] -- add your slider handling code here..
        index = kFfreqv;
        //[/UserSliderCode_ffreqv_slider]
    }
    else if (sliderThatWasMoved == fq_slider)
    {
        //[UserSliderCode_fq_slider] -- add your slider handling code here..
        index = kFq;
        //[/UserSliderCode_fq_slider]
    }
    else if (sliderThatWasMoved == fqv_slider)
    {
        //[UserSliderCode_fqv_slider] -- add your slider handling code here..
        index = kFqv;
        //[/UserSliderCode_fqv_slider]
    }
    else if (sliderThatWasMoved == grains_slider)
    {
        //[UserSliderCode_grains_slider] -- add your slider handling code here..
        index = kGrains;
        value = value / getPlugin()->granulator->kMaxGrains;
        //[/UserSliderCode_grains_slider]
    }
    else if (sliderThatWasMoved == envshape_slider)
    {
        //[UserSliderCode_envshape_slider] -- add your slider handling code here..
        index = kEnvSustain;
        //[/UserSliderCode_envshape_slider]
    }
    else if (sliderThatWasMoved == envskew_slider)
    {
        //[UserSliderCode_envskew_slider] -- add your slider handling code here..
        index = kEnvSkew;
        //[/UserSliderCode_envskew_slider]
    }
    else if (sliderThatWasMoved == scalekey_slider)
    {
        //[UserSliderCode_scalekey_slider] -- add your slider handling code here..
        index = kScaleKey;
        value = value / 12.0f;
        //[/UserSliderCode_scalekey_slider]
    }
    else if (sliderThatWasMoved == matrix_mod_slider_1)
    {
        //[UserSliderCode_matrix_mod_slider_1] -- add your slider handling code here..
        index = kMatrixMod1;
        value = value / 200.0f + 0.5f;
        //[/UserSliderCode_matrix_mod_slider_1]
    }
    else if (sliderThatWasMoved == matrix_mod_slider_2)
    {
        //[UserSliderCode_matrix_mod_slider_2] -- add your slider handling code here..
        index = kMatrixMod2;
        value = value / 200.0f + 0.5f;
        //[/UserSliderCode_matrix_mod_slider_2]
    }
    else if (sliderThatWasMoved == matrix_mod_slider_3)
    {
        //[UserSliderCode_matrix_mod_slider_3] -- add your slider handling code here..
        index = kMatrixMod3;
        value = value / 200.0f + 0.5f;
        //[/UserSliderCode_matrix_mod_slider_3]
    }

    //[UsersliderValueChanged_Post]
    if (index >= 0) {
        getPlugin()->setParameterNotifyingHost(index, value);
    }
    if (index == kScaleKey) {
        scalekey_display->setText(getPlugin()->getParameterText(index));
    } else {
        param_display->setText(getPlugin()->getParameterText(index));
    }
    //[/UsersliderValueChanged_Post]
}

void PluginEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    Plugin* const plugin = getPlugin();
    //plugin->getCallbackLock().enter();

    int id = comboBoxThatHasChanged->getSelectedId();
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == filtertype_combobox)
    {
        //[UserComboBoxCode_filtertype_combobox] -- add your combo box handling code here..
        bool filterToggleState;
        filterToggleState = (id > 1)? true : false;

        ffreq_slider->setEnabled(filterToggleState);
        ffreqv_slider->setEnabled(filterToggleState);
        fq_slider->setEnabled(filterToggleState);
        fqv_slider->setEnabled(filterToggleState);
        plugin->setParameterNotifyingHost(kFtype, (id - 1) / 6.0f);
        //[/UserComboBoxCode_filtertype_combobox]
    }
    else if (comboBoxThatHasChanged == program_combobox)
    {
        //[UserComboBoxCode_program_combobox] -- add your combo box handling code here..
        if (program_combobox->getSelectedItemIndex() == -1) {
            String name = program_combobox->getText();
            if (name.contains(": ")) {
                name = name.fromFirstOccurrenceOf(": ", false, true);
            }
            name = name.trim();
            plugin->changeProgramName(currentProgram, name);
        } else {
            changeProgram(id - 1);
        }
        //updateProgramNamesFromFilter();
        //[/UserComboBoxCode_program_combobox]
    }
    else if (comboBoxThatHasChanged == scale_combobox)
    {
        //[UserComboBoxCode_scale_combobox] -- add your combo box handling code here..
        plugin->parameters->setScale(id - 1);
        //[/UserComboBoxCode_scale_combobox]
    }
    else if (comboBoxThatHasChanged == matrix_src_combobox_1)
    {
        //[UserComboBoxCode_matrix_src_combobox_1] -- add your combo box handling code here..
        plugin->setMatrixSource(0, id);
        //[/UserComboBoxCode_matrix_src_combobox_1]
    }
    else if (comboBoxThatHasChanged == matrix_dest_combobox_1)
    {
        //[UserComboBoxCode_matrix_dest_combobox_1] -- add your combo box handling code here..
        plugin->setMatrixDest(0, id);
        //[/UserComboBoxCode_matrix_dest_combobox_1]
    }
    else if (comboBoxThatHasChanged == matrix_src_combobox_2)
    {
        //[UserComboBoxCode_matrix_src_combobox_2] -- add your combo box handling code here..
        plugin->setMatrixSource(1, id);
        //[/UserComboBoxCode_matrix_src_combobox_2]
    }
    else if (comboBoxThatHasChanged == matrix_dest_combobox_2)
    {
        //[UserComboBoxCode_matrix_dest_combobox_2] -- add your combo box handling code here..
        plugin->setMatrixDest(1, id);
        //[/UserComboBoxCode_matrix_dest_combobox_2]
    }
    else if (comboBoxThatHasChanged == matrix_src_combobox_3)
    {
        //[UserComboBoxCode_matrix_src_combobox_3] -- add your combo box handling code here..
        plugin->setMatrixSource(2, id);
        //[/UserComboBoxCode_matrix_src_combobox_3]
    }
    else if (comboBoxThatHasChanged == matrix_dest_combobox_3)
    {
        //[UserComboBoxCode_matrix_dest_combobox_3] -- add your combo box handling code here..
        plugin->setMatrixDest(2, id);
        //[/UserComboBoxCode_matrix_dest_combobox_3]
    }
    else if (comboBoxThatHasChanged == envtype_combobox)
    {
        //[UserComboBoxCode_envtype_combobox] -- add your combo box handling code here..
        float envTypeValue = (id - 1) / 2.0f;
        plugin->setParameterNotifyingHost(kEnvType, envTypeValue);
        updateEnvSliders(id);
        //[/UserComboBoxCode_envtype_combobox]
    }
    else if (comboBoxThatHasChanged == dur_quant_combobox)
    {
        //[UserComboBoxCode_dur_quant_combobox] -- add your combo box handling code here..
        plugin->setParameterNotifyingHost(kDurQuant, id / NumQuantModes::dur);
        //[/UserComboBoxCode_dur_quant_combobox]
    }
    else if (comboBoxThatHasChanged == iot_quant_combobox)
    {
        //[UserComboBoxCode_iot_quant_combobox] -- add your combo box handling code here..
        plugin->setParameterNotifyingHost(kIotQuant, id / NumQuantModes::iot);
        //[/UserComboBoxCode_iot_quant_combobox]
    }
    else if (comboBoxThatHasChanged == delay_quant_combobox)
    {
        //[UserComboBoxCode_delay_quant_combobox] -- add your combo box handling code here..
        plugin->setParameterNotifyingHost(kDelayQuant, id / NumQuantModes::delay);
        //[/UserComboBoxCode_delay_quant_combobox]
    }

    //[UsercomboBoxChanged_Post]
    //plugin->getCallbackLock().exit();
    //[/UsercomboBoxChanged_Post]
}

void PluginEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    Plugin* const plugin = getPlugin();
    bool state;
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == initButton)
    {
        //[UserButtonCode_initButton] -- add your button handler code here..
        plugin->initCurrentProgram();
        updateParametersFromPlugin();
        //updateProgramNamesFromPlugin();
        //[/UserButtonCode_initButton]
    }
    else if (buttonThatWasClicked == saveButton)
    {
        //[UserButtonCode_saveButton] -- add your button handler code here..
        plugin->saveProgramTo(currentProgram);
        //updateProgramNamesFromPlugin();
        //[/UserButtonCode_saveButton]
    }
    else if (buttonThatWasClicked == savetoButton)
    {
        //[UserButtonCode_savetoButton] -- add your button handler code here..
        PopupMenu m;
        for(int i = 0; i < num_programs; i++) {
            m.addItem(i+1, String(i+1));
        }
        int result = m.showAt(savetoButton);
        if (result != 0) {
            plugin->saveProgramTo(result - 1);
            plugin->setCurrentProgram(result - 1);
        }
        //[/UserButtonCode_savetoButton]
    }
    else if (buttonThatWasClicked == decPresetButton)
    {
        //[UserButtonCode_decPresetButton] -- add your button handler code here..
        if (currentProgram > 0) {
            changeProgram(currentProgram - 1);
        }
        //[/UserButtonCode_decPresetButton]
    }
    else if (buttonThatWasClicked == incPresetButton)
    {
        //[UserButtonCode_incPresetButton] -- add your button handler code here..
        if (currentProgram < (num_programs - 1)) {
            changeProgram(currentProgram + 1);
        }
        //[/UserButtonCode_incPresetButton]
    }
    else if (buttonThatWasClicked == freeze_toggle_button)
    {
        //[UserButtonCode_freeze_toggle_button] -- add your button handler code here..
        plugin->setParameterNotifyingHost (kFreezeToggle, (float)freeze_toggle_button->getToggleState());
        //[/UserButtonCode_freeze_toggle_button]
    }
    else if (buttonThatWasClicked == matrix_mode_1_button)
    {
        //[UserButtonCode_matrix_mode_1_button] -- add your button handler code here..
		state = (int)matrix_mode_1_button->getToggleState();
		plugin->parameters->setMatrixMode(0, state);
        param_display->setText(state ? "Direct" : "Scaled");
        //[/UserButtonCode_matrix_mode_1_button]
    }
    else if (buttonThatWasClicked == matrix_mode_2_button)
    {
        //[UserButtonCode_matrix_mode_2_button] -- add your button handler code here..
		state = (int)matrix_mode_2_button->getToggleState();
        plugin->parameters->setMatrixMode(1, state);
        param_display->setText(state ? "Direct" : "Scaled");
        //[/UserButtonCode_matrix_mode_2_button]
    }
    else if (buttonThatWasClicked == matrix_mode_3_button)
    {
        //[UserButtonCode_matrix_mode_3_button] -- add your button handler code here..
		state = (int)matrix_mode_3_button->getToggleState();
        plugin->parameters->setMatrixMode(2, state);
        param_display->setText(state ? "Direct" : "Scaled");
        //[/UserButtonCode_matrix_mode_3_button]
    }
    else if (buttonThatWasClicked == trans_toggle_button)
    {
        //[UserButtonCode_trans_toggle_button] -- add your button handler code here..
        plugin->setParameterNotifyingHost (kTransToggle, (float)trans_toggle_button->getToggleState());
        //[/UserButtonCode_trans_toggle_button]
    }
    else if (buttonThatWasClicked == gliss_toggle_button)
    {
        //[UserButtonCode_gliss_toggle_button] -- add your button handler code here..
		plugin->setParameterNotifyingHost (kGlissToggle, (float)gliss_toggle_button->getToggleState());
        //[/UserButtonCode_gliss_toggle_button]
    }
    else if (buttonThatWasClicked == optionsButton)
    {
        //[UserButtonCode_optionsButton] -- add your button handler code here..
        PopupMenu m;
        m.addItem(1, "Save XML Program");
        m.addItem(2, "Load XML Program");
        m.addItem(3, "Save XML Bank");
        m.addItem(4, "Load XML Bank");
        if (plugin->isProgchangeEnabled())
            m.addItem(5, "Disable program# parameter");
        else
            m.addItem(5, "Enable program# parameter");
        int result = m.showAt(optionsButton);
        switch(result) {
        case 0: return;
        case 1: saveProgramFile(plugin); return;
        case 2: loadProgramFile(plugin); return;
        case 3: saveBankFile(plugin); return;
        case 4: loadBankFile(plugin); return;
        case 5: plugin->toggleProgchangeEnabled(); return;
        }
        //[/UserButtonCode_optionsButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void PluginEditor::loadBankFile(Plugin* const plugin)
{
    FileChooser myChooser("Load bank...", File::getSpecialLocation (File::userHomeDirectory), "*.bank");
    if (myChooser.browseForFileToOpen()) {
        File file (myChooser.getResult());
        plugin->loadBankXml(&file);
    }
}

void PluginEditor::loadProgramFile(Plugin* const plugin)
{
    FileChooser myChooser("Load program...", File::getSpecialLocation (File::userHomeDirectory), "*.program");
    if (myChooser.browseForFileToOpen()) {
        File file (myChooser.getResult());
        plugin->loadCurrentProgramXml(&file);
    }
}

void PluginEditor::saveBankFile(Plugin* const plugin)
{
    FileChooser myChooser("Save bank...", File::getSpecialLocation (File::userHomeDirectory), "*.bank");
    if (myChooser.browseForFileToSave(true)) {
        File file (myChooser.getResult());
        if (file.getFileExtension() != ".bank") {
	   File f = file.withFileExtension(".bank");
           plugin->saveBankXml(&f);
        }
        else {
            plugin->saveBankXml(&file);
        }        
    }
}

void PluginEditor::saveProgramFile(Plugin* const plugin)
{
    FileChooser myChooser("Save program...", File::getSpecialLocation (File::userHomeDirectory), "*.program");
    if (myChooser.browseForFileToSave(true)) {
        File file (myChooser.getResult());
        if (file.getFileExtension() != ".program") {
	    File f = file.withFileExtension(".program");
            plugin->saveCurrentProgramXml(&f);
        }
        else {
            plugin->saveCurrentProgramXml(&file);
        }    
    }
}


//==============================================================================
// This timer periodically checks whether any of the filter's parameters have changed...
void PluginEditor::timerCallback()
{
    Plugin* const plugin = getPlugin();
    if (plugin->getProgramChangedState()) {
        updateProgramNamesFromPlugin();
        plugin->getParametersChangedState();
        updateParametersFromPlugin();
        return;
    }
    if (plugin->getParametersChangedState()) {
        updateParametersFromPlugin();
    }
}

void PluginEditor::changeProgram(int program)
{
    if (program != currentProgram) {
        //getPlugin()->setParameterNotifyingHost (kProgram, (float)(program)/ (num_programs - 1));
        getPlugin()->setCurrentProgram(program);
        //updateParametersFromPlugin();
    }
}

void PluginEditor::updateParametersFromPlugin()
{
    Plugin* const plugin = getPlugin();
    //plugin->getCallbackLock().enter();

    bool state;
    currentProgram = plugin->getCurrentProgram();

    program_combobox->setSelectedId(currentProgram + 1);
    mix_slider->setValue(plugin->getParameter(kMix), dontSendNotification);
    ingain_slider->setValue(plugin->getParameter(kIngain), dontSendNotification);
    amp_slider->setValue(plugin->getParameter(kAmp), dontSendNotification);
    ampv_slider->setValue(plugin->getParameter(kAmpv), dontSendNotification);
    pan_slider->setValue(plugin->getParameter(kPan), dontSendNotification);
    panv_slider->setValue(plugin->getParameter(kPanv), dontSendNotification);
    delay_slider->setValue(plugin->getParameter(kDelay), dontSendNotification);
    delayv_slider->setValue(plugin->getParameter(kDelayv), dontSendNotification);
    feedback_slider->setValue(plugin->getParameter(kFeedback), dontSendNotification);
    gliss_slider->setValue(plugin->getParameter(kGliss), dontSendNotification);
    glissv_slider->setValue(plugin->getParameter(kGlissv), dontSendNotification);
    trans_slider->setValue(plugin->getParameter(kTrans), dontSendNotification);
    transv_slider->setValue(plugin->getParameter(kTransv), dontSendNotification);
    iot_slider->setValue(plugin->getParameter(kIot), dontSendNotification);
    iotv_slider->setValue(plugin->getParameter(kIotv), dontSendNotification);
    dur_slider->setValue(plugin->getParameter(kDur), dontSendNotification);
    durv_slider->setValue(plugin->getParameter(kDurv), dontSendNotification);
    ffreq_slider->setValue(plugin->getParameter(kFfreq), dontSendNotification);
    ffreqv_slider->setValue(plugin->getParameter(kFfreqv), dontSendNotification);
    fq_slider->setValue(plugin->getParameter(kFq), dontSendNotification);
    fqv_slider->setValue(plugin->getParameter(kFqv), dontSendNotification);
    grains_slider->setValue(plugin->getParameter(kGrains) * plugin->granulator->kMaxGrains, dontSendNotification);
    envshape_slider->setValue(plugin->getParameter(kEnvSustain), dontSendNotification);
    envskew_slider->setValue(plugin->getParameter(kEnvSkew), dontSendNotification);
    scalekey_slider->setValue(plugin->getParameter(kScaleKey) * 12, dontSendNotification);
    scalekey_display->setText(plugin->getParameterText(kScaleKey));

    // Scale
    if (scale_combobox->getNumItems() == 0) {
        std::vector<String> names = plugin->getScaleNames();
        scale_combobox->addItem("unquantized", 1);
        for(int i = 0; i < (int)names.size(); i++)
            scale_combobox->addItem(names.at(i), (i + 2));
    }
    int id = plugin->parameters->getScale();
    scale_combobox->setSelectedId(id + 1);

    // Glissando
    state = (plugin->getParameter(kGlissToggle) == 0.0f) ? false : true;
    updateGlissSliders(state);

    // Filter
    float f = plugin->getParameter(kFtype) * 6.0f + 1.0f;
    id = static_cast<int>(f + (f > 0.0 ? + 0.5 : -0.5));
    filtertype_combobox->setSelectedId(id, true);
    state = false;
    if (filtertype_combobox->getSelectedId() > 1)
        state = true;
    ffreq_slider->setEnabled(state);
    ffreqv_slider->setEnabled(state);
    fq_slider->setEnabled(state);
    fqv_slider->setEnabled(state);

    // Envelope
    float envT = plugin->getParameter(kEnvType) * 2.0f + 1.0f;
    id = static_cast<int>(envT + (envT > 0.0 ? + 0.5 : -0.5));
    envtype_combobox->setSelectedId(id);
    updateEnvSliders(id);

    // mod matrix
    matrix_mod_slider_1->setValue(
        (plugin->getParameter(kMatrixMod1) - 0.5f) * 200.0f, dontSendNotification);
    matrix_mod_slider_2->setValue(
        (plugin->getParameter(kMatrixMod2) - 0.5f) * 200.0f, dontSendNotification);
    matrix_mod_slider_3->setValue(
        (plugin->getParameter(kMatrixMod3) - 0.5f) * 200.0f, dontSendNotification);
    matrix_src_combobox_1->setSelectedId(plugin->parameters->getMatrixSource(0));
    matrix_src_combobox_2->setSelectedId(plugin->parameters->getMatrixSource(1));
    matrix_src_combobox_3->setSelectedId(plugin->parameters->getMatrixSource(2));
    matrix_dest_combobox_1->setSelectedId(plugin->parameters->getMatrixDest(0));
    matrix_dest_combobox_2->setSelectedId(plugin->parameters->getMatrixDest(1));
    matrix_dest_combobox_3->setSelectedId(plugin->parameters->getMatrixDest(2));

    state = (plugin->parameters->getMatrixMode(0) == 0) ? false : true;
    matrix_mode_1_button->setToggleState(state, false);
    state = (plugin->parameters->getMatrixMode(1) == 0) ? false : true;
    matrix_mode_2_button->setToggleState(state, false);
    state = (plugin->parameters->getMatrixMode(2) == 0) ? false : true;
    matrix_mode_3_button->setToggleState(state, false);

    // trans toggle
    state = (plugin->getParameter(kTransToggle) == 0.0f)? false : true;
    trans_toggle_button->setToggleState(state, false);
    updateTransSliders(state);

    // gliss toggle
    state = (plugin->getParameter(kGlissToggle) == 0.0f)? false : true;
    gliss_toggle_button->setToggleState(state, false);
    updateGlissSliders(state);

    // freeze toggle
    state = (plugin->getParameter(kFreezeToggle) == 0.0f)? false : true;
    freeze_toggle_button->setToggleState(state, false);

    // time quantization
    id = MathFunc::roundFtoI(plugin->getParameter(kDelayQuant) * NumQuantModes::delay);
    if(id == 0) id++;
    delay_quant_combobox->setSelectedId(id);
    id = MathFunc::roundFtoI(plugin->getParameter(kIotQuant) * NumQuantModes::iot);
    if(id == 0) id++;
    iot_quant_combobox->setSelectedId(id);
    id = MathFunc::roundFtoI(plugin->getParameter(kDurQuant) * NumQuantModes::dur);
    if(id == 0) id++;
    dur_quant_combobox->setSelectedId(id);

    //plugin->getCallbackLock().exit();
}

void PluginEditor::updateGlissSliders(bool state)
{
    gliss_slider->setEnabled(state);
    glissv_slider->setEnabled(state);
}

void PluginEditor::updateTransSliders(bool state)
{
    trans_slider->setEnabled(state);
    transv_slider->setEnabled(state);
}

void PluginEditor::updateEnvSliders(int id)
{
    if (id == 1) {
        // RCB
        envshape_slider->setEnabled(true);
        envskew_slider->setEnabled(true);
    } else if (id == 2) {
        // Parabola
        envshape_slider->setEnabled(false);
        envskew_slider->setEnabled(false);
    } else if (id == 3) {
        // Triangle
        envshape_slider->setEnabled(false);
        envskew_slider->setEnabled(true);
    }
}

void PluginEditor::updateScaleComponents(bool state)
{
    scale_combobox->setEnabled(state);
    scalekey_slider->setEnabled(state);

    if (state) {
        scalekey_display->setText(getPlugin()->getParameterText(kScaleKey));
    } else {
        scalekey_display->setText("");
    }
}

void PluginEditor::updateProgramNamesFromPlugin()
{
    Plugin* const plugin = getPlugin();
    int currentProgram = plugin->getCurrentProgram();
    bool editorSaved = plugin->getSavedState();

    String text = "";
    for(int i = 0; i < num_programs; i++) {
        programNames[i] = plugin->getProgramName(i);
        if (i == currentProgram && editorSaved == false) {
            text = String("*") + String(i+1) + String(": ") + String(" ") + String(programNames[i]);
        } else {
            text = String(i+1) + String(": ") + String(programNames[i]);
        }
        program_combobox->changeItemText(i + 1, text);
    }
    if ((currentProgram + 1) != program_combobox->getSelectedId()) {
        program_combobox->setSelectedId(currentProgram + 1);
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public AudioProcessorEditor, public Timer" constructorParams="Plugin* const ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="4"
                 snapActive="1" snapShown="0" overlayOpacity="0.330000013" fixedSize="0"
                 initialWidth="780" initialHeight="225">
  <BACKGROUND backgroundColour="ff05122b"/>
  <GROUPCOMPONENT name="" id="1383c7b6e3b382d5" memberName="groupComponent3" virtualName=""
                  explicitFocusOrder="0" pos="0 108 176 44" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <GROUPCOMPONENT name="" id="ff477dcc1ed3af5e" memberName="groupComponent2" virtualName=""
                  explicitFocusOrder="0" pos="0 -4 64 120" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <GROUPCOMPONENT name="" id="780c68964bb8c046" memberName="groupComponent20" virtualName=""
                  explicitFocusOrder="0" pos="572 -4 80 156" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <GROUPCOMPONENT name="" id="edde7f9eed9a606b" memberName="groupComponent18" virtualName=""
                  explicitFocusOrder="0" pos="456 -4 116 156" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <GROUPCOMPONENT name="" id="b7bd6894fc0d5cac" memberName="groupComponent5" virtualName=""
                  explicitFocusOrder="0" pos="340 -4 116 156" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <GROUPCOMPONENT name="" id="c8b4808a33d45112" memberName="groupComponent15" virtualName=""
                  explicitFocusOrder="0" pos="1 146 651 46" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <GROUPCOMPONENT name="" id="8a7dd85f951e28ae" memberName="groupComponent9" virtualName=""
                  explicitFocusOrder="0" pos="176 -4 164 156" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <GROUPCOMPONENT name="" id="652e0847c8971a36" memberName="groupComponent" virtualName=""
                  explicitFocusOrder="0" pos="64 -4 112 120" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <SLIDER name="" id="95528b37572de21f" memberName="mix_slider" virtualName=""
          explicitFocusOrder="0" pos="14 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="d8eaeeeead8b672d" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="4 40 52 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Mix" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default sans-serif font" fontsize="14"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="1c0717d5dd93a6a7" memberName="ingain_slider" virtualName=""
          explicitFocusOrder="0" pos="14 58 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="264c1a559ea0956" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="4 86 52 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="InGain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default sans-serif font" fontsize="14"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="a5f7e012762c51e5" memberName="amp_slider" virtualName=""
          explicitFocusOrder="0" pos="76 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="d9b003b7d63548f8" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="68 44 48 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Amp" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default sans-serif font" fontsize="14"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="fe00b56929bb258e" memberName="ampv_slider" virtualName=""
          explicitFocusOrder="0" pos="76 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="afcce8317ad69c5f" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="68 92 48 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="+" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default sans-serif font" fontsize="14"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="d9d8049f09afd541" memberName="pan_slider" virtualName=""
          explicitFocusOrder="0" pos="128 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="fa19287959eb1948" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="120 44 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Pan" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="ac09aa78e0fb2a92" memberName="panv_slider" virtualName=""
          explicitFocusOrder="0" pos="128 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="452d93d790453cde" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="120 92 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="+-" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="bc6558243c91f2b1" memberName="delay_slider" virtualName=""
          explicitFocusOrder="0" pos="188 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.0005" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="200148d075b68998" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="180 44 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Delay" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="563b18dd571b88d" memberName="delayv_slider" virtualName=""
          explicitFocusOrder="0" pos="188 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.0005" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="32bf4bc14ce7fa7c" memberName="feedback_slider" virtualName=""
          explicitFocusOrder="0" pos="68 118 104 30" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="5789411731ad12d6" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="4 124 58 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default sans-serif font" fontsize="14"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="c5bba8f29d58d78a" memberName="gliss_slider" virtualName=""
          explicitFocusOrder="0" pos="408 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="aa503c3ebb3fd973" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="400 44 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Gliss" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="2fc8a6797aadf134" memberName="glissv_slider" virtualName=""
          explicitFocusOrder="0" pos="408 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="be9501e51ceddab5" memberName="trans_slider" virtualName=""
          explicitFocusOrder="0" pos="356 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="1333f16b4129bb8a" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="348 44 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Trans" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="ef96ccab9f21f60c" memberName="transv_slider" virtualName=""
          explicitFocusOrder="0" pos="356 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="1729cab1f0595ef1" memberName="iot_slider" virtualName=""
          explicitFocusOrder="0" pos="244 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="7b96d5be3e8b9ae5" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="236 44 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="IOT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="1c59a020855ae618" memberName="iotv_slider" virtualName=""
          explicitFocusOrder="0" pos="244 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="3bbc79d7b70edc91" memberName="dur_slider" virtualName=""
          explicitFocusOrder="0" pos="296 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="3a13ee1452421a82" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="288 44 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Dur" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="8c19909c6f9b344c" memberName="durv_slider" virtualName=""
          explicitFocusOrder="0" pos="296 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="613bfb827d64e933" memberName="ffreq_slider" virtualName=""
          explicitFocusOrder="0" pos="472 12 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="9b5c3cbefa03d9bc" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="464 44 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="FFreq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="1cbaffece0fc5da0" memberName="ffreqv_slider" virtualName=""
          explicitFocusOrder="0" pos="472 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="44cfe1f834e6a527" memberName="fq_slider" virtualName=""
          explicitFocusOrder="0" pos="524 12 32 32" thumbcol="ffffffff"
          trackcol="7fffffff" rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54"
          min="0" max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="a150aca5612f1e6a" memberName="label21" virtualName=""
         explicitFocusOrder="0" pos="516 44 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="FQ" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="" id="7eec4cf3647035fb" memberName="fqv_slider" virtualName=""
          explicitFocusOrder="0" pos="524 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="572f840702f69af9" memberName="grains_slider" virtualName=""
          explicitFocusOrder="0" pos="44 158 64 28" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" textboxtext="ffffffff"
          textboxbkgd="ff060827" min="0" max="20" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxRight" textBoxEditable="0" textBoxWidth="32"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="e7c1e4651c4e182b" memberName="label23" virtualName=""
         explicitFocusOrder="0" pos="5 162 45 20" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Grains" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default sans-serif font" fontsize="14"
         bold="0" italic="0" justification="36"/>
  <TEXTEDITOR name="" id="c4a4583339e34ae" memberName="param_display" virtualName=""
              explicitFocusOrder="0" pos="178 162 218 18" textcol="ff000000"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="1"
              scrollbars="0" caret="0" popupmenu="0"/>
  <COMBOBOX name="" id="11bf6b7db308c8f7" memberName="filtertype_combobox"
            virtualName="" explicitFocusOrder="0" pos="465 120 98 18" editable="0"
            layout="36" items="off&#10;band&#10;low&#10;high&#10;notch&#10;comb&#10;random&#10;"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="" id="d6d7d2b2f698d013" memberName="initButton" virtualName=""
              explicitFocusOrder="0" pos="8 199 42 20" bgColOff="ffdddddd"
              buttonText="Init" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="5e33e2e22aa3407a" memberName="saveButton" virtualName=""
              explicitFocusOrder="0" pos="50 199 42 20" bgColOff="ffdddddd"
              buttonText="Save" connectedEdges="15" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="ab276ca6001ba75b" memberName="savetoButton" virtualName=""
              explicitFocusOrder="0" pos="92 199 42 20" bgColOff="ffdddddd"
              buttonText="Save To" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="22e30bf7dd9d0470" memberName="decPresetButton" virtualName=""
              explicitFocusOrder="0" pos="142 199 24 20" bgColOff="ffdddddd"
              buttonText="-" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="" id="c945640c7a70cde3" memberName="incPresetButton" virtualName=""
              explicitFocusOrder="0" pos="166 199 24 20" bgColOff="ffdddddd"
              buttonText="+" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="" id="ac962c8e97ecc2a0" memberName="program_combobox" virtualName=""
            explicitFocusOrder="0" pos="190 199 209 20" editable="1" layout="33"
            items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="" id="780e32317de9f68c" memberName="label25" virtualName=""
         explicitFocusOrder="0" pos="532 199 118 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Argotlunar v2.0.6"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="16" bold="0" italic="0" justification="33"/>
  <SLIDER name="" id="8ef2ebcb8867e07" memberName="envshape_slider" virtualName=""
          explicitFocusOrder="0" pos="595 12 32 32" thumbcol="ffffffff"
          trackcol="7fffffff" rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54"
          min="0" max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="" id="5e036513674e016f" memberName="envskew_slider" virtualName=""
          explicitFocusOrder="0" pos="595 60 32 32" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" min="0"
          max="1" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="d6fb2301cf93e521" memberName="label26" virtualName=""
         explicitFocusOrder="0" pos="584 44 56 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Sustain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="a2b534d531b20643" memberName="label27" virtualName=""
         explicitFocusOrder="0" pos="584 92 56 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Skew" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="2e49de53ba454796" memberName="label28" virtualName=""
         explicitFocusOrder="0" pos="106 162 48 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Freeze" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="" id="2743925fd6ee5087" memberName="freeze_toggle_button"
                virtualName="" explicitFocusOrder="0" pos="152 162 24 20" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <COMBOBOX name="" id="e2a99ca0771bb233" memberName="scale_combobox" virtualName=""
            explicitFocusOrder="0" pos="440 162 108 18" editable="0" layout="33"
            items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="" id="a4d67095cd30eb67" memberName="scalekey_slider" virtualName=""
          explicitFocusOrder="0" pos="574 158 40 30" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" textboxtext="ffffffff"
          textboxbkgd="ff060827" min="0" max="11" int="1" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="40"
          textBoxHeight="15" skewFactor="1"/>
  <LABEL name="" id="5cbd82ea0147fa00" memberName="label24" virtualName=""
         explicitFocusOrder="0" pos="546 162 34 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Key" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="" id="751a599e1ca6cc62" memberName="groupComponent17" virtualName=""
                  explicitFocusOrder="0" pos="652 -4 128 231" outlinecol="66c1c1c1"
                  textcol="ffffffff" title=""/>
  <LABEL name="" id="942f03f0a577dc76" memberName="label29" virtualName=""
         explicitFocusOrder="0" pos="656 9 118 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Correlation Matrix"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default sans-serif font" fontsize="14" bold="0" italic="0"
         justification="36"/>
  <COMBOBOX name="" id="3ccd9b7781375f86" memberName="matrix_src_combobox_1"
            virtualName="" explicitFocusOrder="0" pos="696 33 74 16" editable="0"
            layout="33" items="Off&#10;Amp&#10;Pan L/R&#10;Pan Width&#10;Delay&#10;IOT&#10;Dur&#10;Trans&#10;Gliss&#10;FFreq&#10;FQ"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="" id="22ca444c80f96109" memberName="matrix_dest_combobox_1"
            virtualName="" explicitFocusOrder="0" pos="696 53 74 16" editable="0"
            layout="33" items="Off&#10;Amp&#10;Pan L/R&#10;Delay&#10;IOT&#10;Dur&#10;Trans&#10;Gliss&#10;FFreq&#10;FQ&#10;Sustain&#10;Skew&#10;"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="" id="57db4788723b1a3b" memberName="matrix_mod_slider_1"
          virtualName="" explicitFocusOrder="0" pos="656 73 100 20" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" textboxtext="ffffffff"
          textboxbkgd="ff060827" min="-100" max="100" int="1" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="40"
          textBoxHeight="15" skewFactor="1"/>
  <LABEL name="" id="60e8bce65f6784eb" memberName="label30" virtualName=""
         explicitFocusOrder="0" pos="658 31 36 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Src" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="947aaaa7d391c793" memberName="label31" virtualName=""
         explicitFocusOrder="0" pos="658 51 36 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Dest" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="" id="b46fcb7e41db2587" memberName="matrix_src_combobox_2"
            virtualName="" explicitFocusOrder="0" pos="696 97 74 16" editable="0"
            layout="33" items="Off&#10;Amp&#10;Pan L/R&#10;Pan Width&#10;Delay&#10;IOT&#10;Dur&#10;Trans&#10;Gliss&#10;FFreq&#10;FQ"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="" id="b4c5ab1c8c5e6cfc" memberName="matrix_dest_combobox_2"
            virtualName="" explicitFocusOrder="0" pos="696 117 74 16" editable="0"
            layout="33" items="Off&#10;Amp&#10;Pan L/R&#10;Delay&#10;IOT&#10;Dur&#10;Trans&#10;Gliss&#10;FFreq&#10;FQ&#10;Sustain&#10;Skew&#10;"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="" id="2f02cd776ed789c9" memberName="matrix_mod_slider_2"
          virtualName="" explicitFocusOrder="0" pos="654 138 100 20" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" textboxtext="ffffffff"
          textboxbkgd="ff060827" min="-100" max="100" int="1" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="40"
          textBoxHeight="15" skewFactor="1"/>
  <LABEL name="" id="e939c840a4e2bfd0" memberName="label34" virtualName=""
         explicitFocusOrder="0" pos="658 95 36 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Src" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="d20e7997c05d7ae4" memberName="label35" virtualName=""
         explicitFocusOrder="0" pos="658 115 36 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Dest" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="" id="2e961c6369f4556c" memberName="matrix_src_combobox_3"
            virtualName="" explicitFocusOrder="0" pos="696 161 74 16" editable="0"
            layout="33" items="Off&#10;Amp&#10;Pan L/R&#10;Pan Width&#10;Delay&#10;IOT&#10;Dur&#10;Trans&#10;Gliss&#10;FFreq&#10;FQ"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="" id="9b9492c387606174" memberName="matrix_dest_combobox_3"
            virtualName="" explicitFocusOrder="0" pos="696 181 74 16" editable="0"
            layout="33" items="Off&#10;Amp&#10;Pan L/R&#10;Delay&#10;IOT&#10;Dur&#10;Trans&#10;Gliss&#10;FFreq&#10;FQ&#10;Sustain&#10;Skew&#10;"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="" id="69b18d26b6874392" memberName="matrix_mod_slider_3"
          virtualName="" explicitFocusOrder="0" pos="655 201 100 20" thumbcol="ffffffff"
          rotarysliderfill="fbffffff" rotaryslideroutline="ff3c3c54" textboxtext="ffffffff"
          textboxbkgd="ff060827" min="-100" max="100" int="1" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="40"
          textBoxHeight="15" skewFactor="1"/>
  <LABEL name="" id="8da610c595fd987b" memberName="label36" virtualName=""
         explicitFocusOrder="0" pos="658 161 36 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Src" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="bbd9e85cb7b671b7" memberName="label37" virtualName=""
         explicitFocusOrder="0" pos="658 181 36 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Dest" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="" id="ebc700df29bbbed7" memberName="matrix_mode_1_button"
                virtualName="" explicitFocusOrder="0" pos="754 72 20 20" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="" id="ea8cea353adc7a91" memberName="matrix_mode_2_button"
                virtualName="" explicitFocusOrder="0" pos="754 136 20 20" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="" id="45253df97b33e93" memberName="matrix_mode_3_button"
                virtualName="" explicitFocusOrder="0" pos="753 201 20 20" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TEXTEDITOR name="" id="6ec59bc6b51554fa" memberName="scalekey_display" virtualName=""
              explicitFocusOrder="0" pos="612 162 31 20" textcol="ffffffff"
              bkgcol="ff060827" outlinecol="ff3c3c54" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="1" scrollbars="0" caret="0" popupmenu="0"/>
  <TOGGLEBUTTON name="" id="206c3d6b3bf9ef70" memberName="trans_toggle_button"
                virtualName="" explicitFocusOrder="0" pos="360 120 24 20" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <COMBOBOX name="" id="95e88251b6b9e6ca" memberName="envtype_combobox" virtualName=""
            explicitFocusOrder="0" pos="577 120 69 18" editable="0" layout="33"
            items="RCB&#10;parabola&#10;triangle" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="" id="cedddd6737c5e966" memberName="dur_quant_combobox"
            virtualName="" explicitFocusOrder="0" pos="286 120 48 18" editable="0"
            layout="33" items="ms&#10;128&#10;128T&#10;64&#10;64T&#10;32&#10;32T&#10;16&#10;16T&#10;8&#10;8T&#10;4&#10;4T&#10;long"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="" id="4bd9711f815741a" memberName="iot_quant_combobox"
            virtualName="" explicitFocusOrder="0" pos="234 120 48 18" editable="0"
            layout="33" items="ms&#10;128&#10;128T&#10;64&#10;64T&#10;32&#10;32T&#10;16&#10;16T&#10;8&#10;8T&#10;4&#10;4T"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="" id="3b6f045a4dc835b9" memberName="delay_quant_combobox"
            virtualName="" explicitFocusOrder="0" pos="184 120 48 18" editable="0"
            layout="33" items="ms&#10;128&#10;128T&#10;64&#10;64T&#10;32&#10;32T&#10;16&#10;16T&#10;8&#10;8T&#10;4&#10;4T"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="" id="5e8e12e51363dfa0" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="180 92 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="+" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="87f2c63810217f6e" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="236 92 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="+" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="fb89f5bf999729da" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="288 92 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="+" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="f55ec0238a0339fd" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="348 92 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="+-" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="d714372562e62a36" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="401 92 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="+-" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="fc69ca88856c09fd" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="463 92 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="+" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="c3eddf237aeed093" memberName="label22" virtualName=""
         explicitFocusOrder="0" pos="516 92 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="+" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="" id="4e10540f2ba9b25a" memberName="label32" virtualName=""
         explicitFocusOrder="0" pos="400 162 40 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Scale" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="14" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="" id="69f020d8ac12ab42" memberName="gliss_toggle_button"
                virtualName="" explicitFocusOrder="0" pos="412 120 24 20" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TEXTBUTTON name="" id="59269a86104d026" memberName="optionsButton" virtualName=""
              explicitFocusOrder="0" pos="407 199 48 20" bgColOff="ffdddddd"
              buttonText="Options" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
