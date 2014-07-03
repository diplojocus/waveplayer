/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);
	
	fileName = "/Users/joe/Downloads/Mistaken Doves Demo 2.wav";
	
	File audioFile(fileName);
	AudioFormatManager formatManager;
	formatManager.registerBasicFormats();
	ScopedPointer<AudioFormatReader> reader = formatManager.createReaderFor(audioFile);
	AudioSampleBuffer buffer = AudioSampleBuffer(reader->numChannels, reader->lengthInSamples);
	reader->read(&buffer, 0, reader->lengthInSamples, 0, true, true);
	
	peakLevel = String(buffer.getMagnitude(0, reader->lengthInSamples));
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    g.drawText (fileName + " peak:" + peakLevel, getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
