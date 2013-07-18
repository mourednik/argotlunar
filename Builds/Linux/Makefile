# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

ifndef CONFIG
  CONFIG=Release
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I /usr/include -I /usr/include/freetype2 -I ../../../vstsdk2.4 -I ../../JuceLibraryCode
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -fPIC -O3
  CXXFLAGS += $(CFLAGS) -fpermissive
  LDFLAGS += $(TARGET_ARCH) -L$(BINDIR) -L$(LIBDIR) -shared -fvisibility=hidden -L/usr/X11R6/lib/ -lX11 -lXext -lXinerama -lasound -ldl -lfreetype -lpthread -lrt -s
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I /usr/include -I /usr/include/freetype2 -I ../../../vstsdk2.4 -I ../../JuceLibraryCode
  TARGET := argotlunar.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
endif

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

OBJECTS := \
  $(OBJDIR)/CombFilter_da9362e2.o \
  $(OBJDIR)/DelayLine_7d9415f8.o \
  $(OBJDIR)/Envelope_2c60e259.o \
  $(OBJDIR)/Filter_cccb6f01.o \
  $(OBJDIR)/Grain_4c99d65c.o \
  $(OBJDIR)/GrainParametersGenerator_fceb2317.o \
  $(OBJDIR)/Granulator_fca4d7ce.o \
  $(OBJDIR)/Parameters_fb275273.o \
  $(OBJDIR)/PitchQuantizer_a05a690a.o \
  $(OBJDIR)/Plugin_124bbd3c.o \
  $(OBJDIR)/PluginEditor_94d4fb09.o \
  $(OBJDIR)/Program_40928ce5.o \
  $(OBJDIR)/ProgramBank_1938e141.o \
  $(OBJDIR)/TimeQuantizer_da399a75.o \
  $(OBJDIR)/juce_audio_basics_2442e4ea.o \
  $(OBJDIR)/juce_audio_devices_a4c8a728.o \
  $(OBJDIR)/juce_audio_formats_d349f0c8.o \
  $(OBJDIR)/juce_audio_processors_44a134a2.o \
  $(OBJDIR)/juce_core_aff681cc.o \
  $(OBJDIR)/juce_data_structures_bdd6d488.o \
  $(OBJDIR)/juce_events_79b2840.o \
  $(OBJDIR)/juce_graphics_c8f1e7a4.o \
  $(OBJDIR)/juce_gui_basics_a630dd20.o \
  $(OBJDIR)/juce_gui_extra_7767d6a8.o \
  $(OBJDIR)/juce_PluginUtilities_e2e19a34.o \
  $(OBJDIR)/juce_VST_Wrapper_bb62e93d.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking Argotlunar
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning Argotlunar
	-@rm -f $(OUTDIR)/$(TARGET)
	-@rm -rf $(OBJDIR)/*
	-@rm -rf $(OBJDIR)

strip:
	@echo Stripping Argotlunar
	-@strip --strip-unneeded $(OUTDIR)/$(TARGET)

$(OBJDIR)/CombFilter_da9362e2.o: ../../Source/CombFilter.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CombFilter.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/DelayLine_7d9415f8.o: ../../Source/DelayLine.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling DelayLine.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Envelope_2c60e259.o: ../../Source/Envelope.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Envelope.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Filter_cccb6f01.o: ../../Source/Filter.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Filter.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Grain_4c99d65c.o: ../../Source/Grain.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Grain.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/GrainParametersGenerator_fceb2317.o: ../../Source/GrainParametersGenerator.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling GrainParametersGenerator.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Granulator_fca4d7ce.o: ../../Source/Granulator.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Granulator.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Parameters_fb275273.o: ../../Source/Parameters.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Parameters.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PitchQuantizer_a05a690a.o: ../../Source/PitchQuantizer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PitchQuantizer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Plugin_124bbd3c.o: ../../Source/Plugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Plugin.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginEditor_94d4fb09.o: ../../Source/PluginEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Program_40928ce5.o: ../../Source/Program.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Program.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ProgramBank_1938e141.o: ../../Source/ProgramBank.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ProgramBank.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/TimeQuantizer_da399a75.o: ../../Source/TimeQuantizer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling TimeQuantizer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_2442e4ea.o: ../../JuceLibraryCode/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_a4c8a728.o: ../../JuceLibraryCode/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_d349f0c8.o: ../../JuceLibraryCode/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_44a134a2.o: ../../JuceLibraryCode/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_aff681cc.o: ../../JuceLibraryCode/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_bdd6d488.o: ../../JuceLibraryCode/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_79b2840.o: ../../JuceLibraryCode/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_c8f1e7a4.o: ../../JuceLibraryCode/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_a630dd20.o: ../../JuceLibraryCode/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_7767d6a8.o: ../../JuceLibraryCode/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_PluginUtilities_e2e19a34.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/utility/juce_PluginUtilities.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_PluginUtilities.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST_Wrapper_bb62e93d.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
