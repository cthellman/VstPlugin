/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class VstPluginAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    VstPluginAudioProcessorEditor (VstPluginAudioProcessor&);
    ~VstPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;
    


private:
    
    juce::Slider mGainSlider;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VstPluginAudioProcessor& audioProcessor;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstPluginAudioProcessorEditor)
};
