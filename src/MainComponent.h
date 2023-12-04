/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "Global.h"
#include "Trombone.h"
#include "LowPass.h"

#include <memory>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill);
    void releaseResources();

private:

    // Your private member variables go here...
    std::unique_ptr<Trombone> trombone;
    double fs;
    long t = 0;
    bool done = false;
    std::vector<std::vector<double>> geometry;
    double pressureVal, lipFreqVal, LVal;
    int controlHeight, controlY;
    
    bool record = true;
    double mouseLocX = 0;
    double mouseLocY = 0;
    bool mouseEllipseVisible = false;
    
    std::unique_ptr<LowPass> lowPass;
    
    Slider pressureSlider;
    Rectangle<int> sliderBounds { 0, 0, 100, 40 };
    Rectangle<int> bottomBar;
    bool init = true;
    double pressureValSave = 0;
};