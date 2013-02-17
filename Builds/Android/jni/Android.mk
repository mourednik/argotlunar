# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := juce_jni
LOCAL_SRC_FILES := \
  ../../../Source/CombFilter.cpp\
  ../../../Source/DelayLine.cpp\
  ../../../Source/Envelope.cpp\
  ../../../Source/Filter.cpp\
  ../../../Source/Grain.cpp\
  ../../../Source/GrainParametersGenerator.cpp\
  ../../../Source/Granulator.cpp\
  ../../../Source/Parameters.cpp\
  ../../../Source/PitchQuantizer.cpp\
  ../../../Source/Plugin.cpp\
  ../../../Source/PluginEditor.cpp\
  ../../../Source/Program.cpp\
  ../../../Source/ProgramBank.cpp\
  ../../../Source/TimeQuantizer.cpp\
  ../../../JuceLibraryCode/modules/juce_audio_basics/juce_audio_basics.cpp\
  ../../../JuceLibraryCode/modules/juce_audio_devices/juce_audio_devices.cpp\
  ../../../JuceLibraryCode/modules/juce_audio_formats/juce_audio_formats.cpp\
  ../../../JuceLibraryCode/modules/juce_audio_processors/juce_audio_processors.cpp\
  ../../../JuceLibraryCode/modules/juce_core/juce_core.cpp\
  ../../../JuceLibraryCode/modules/juce_data_structures/juce_data_structures.cpp\
  ../../../JuceLibraryCode/modules/juce_events/juce_events.cpp\
  ../../../JuceLibraryCode/modules/juce_graphics/juce_graphics.cpp\
  ../../../JuceLibraryCode/modules/juce_gui_basics/juce_gui_basics.cpp\
  ../../../JuceLibraryCode/modules/juce_gui_extra/juce_gui_extra.cpp\
  ../../../JuceLibraryCode/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp\
  ../../../JuceLibraryCode/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp\

ifeq ($(CONFIG),Debug)
else
  LOCAL_CPPFLAGS += -fsigned-char -fexceptions -frtti -I "../../JuceLibraryCode" -O3 -D "JUCE_ANDROID=1" -D "JUCE_ANDROID_API_VERSION=8" -D "JUCE_ANDROID_ACTIVITY_CLASSNAME=com_michaelourednik_argotlunar_Argotlunar" -D JUCE_ANDROID_ACTIVITY_CLASSPATH=\"com/michaelourednik/argotlunar/Argotlunar\" -D "NDEBUG=1" -D "JUCER_ANDROID_7F0E4A25=1"
  LOCAL_LDLIBS := -llog -lGLESv2
endif

include $(BUILD_SHARED_LIBRARY)
