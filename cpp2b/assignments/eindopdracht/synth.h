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
    float getSampleSynth(); //get the samples from all the oscillators
    float midiToFreq(int midiNote); //calculate the frequency according to the midinote

    protected:
    //make oscillators
    Sine sine = Sine(100,1.0f,44100);
    // Sine sine1 = Sine(400,44100);


    float frequency;
    float midiNote;
};

#endif