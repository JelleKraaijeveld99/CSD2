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

    virtual float getSampleSynth() = 0; //getSample function that's empty, gets defined in fm and additive synth classes

    float midiToFreq(int midiNote, int interval); //calculate the frequency according to the midinote

    //setter
    virtual void setMidiNote(float midiNote) = 0; //function for setting the midiNote of a synth


    protected:

    Oscillator* myOscillators[3]; //empty pointer array for storing the oscillators in
    
    float frequency;
    float midiNote;
    float interval;
};

#endif