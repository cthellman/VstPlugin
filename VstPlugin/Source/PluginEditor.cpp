/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VstPluginAudioProcessorEditor::VstPluginAudioProcessorEditor (VstPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mGainSlider.setRange(0.00f, 1.00f, 0.01f);
    mGainSlider.setValue(0.50f);
    mGainSlider.addListener(this);
    addAndMakeVisible(mGainSlider);

    setSize (200, 300);
}

VstPluginAudioProcessorEditor::~VstPluginAudioProcessorEditor()
{

}

//==============================================================================
void VstPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
}

void VstPluginAudioProcessorEditor::resized()
{
    mGainSlider.setBounds(getWidth()/2-50, getHeight()/2-75, 100, 150);
}

void VstPluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    
    if (slider == &mGainSlider)
        audioProcessor.mGain = mGainSlider.getValue();

}
