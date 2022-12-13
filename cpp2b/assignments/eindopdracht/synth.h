#ifndef _H_SYN_
#define _H_SYN_
#include <iostream>
#include <cmath>
#include "sine.h"

#pragma once

class Synthesizer
{
    public:
    Synthesizer(int midiNote); //constructor
    ~Synthesizer(); //deconstructor

    void tickSynth(); //tick the oscillators together
    virtual float getSampleSynth() = 0; //get the samples from all the oscillators
    float midiToFreq(int midiNote); //calculate the frequency according to the midinote

    protected:

    Oscillator* myOscillators[3]; //empty pointer array for storing the oscillators in
    
    float frequency;
    float midiNote;
};

#endif