#ifndef _H_SYN_
#define _H_SYN_
#include <iostream>
#include <cmath>
#include "sine.h"
#include "square.h"
#include "saw.h"

#pragma once

class Synthesizer
{
    public:

    enum Waveform{ //waveforms possible as oscillators
    Sine1 = 0,
    Square1 = 1,
    Saw1 = 2,
    Size = 3
    };

    Synthesizer(int midiNote); //constructor
    ~Synthesizer(); //deconstructor

    virtual void tickSynth() = 0; //tick the oscillators together

    virtual float getSampleSynth() = 0; //getSample function that's empty, gets defined in fm and additive synth classes

    float midiToFreq(int midiNote, int interval); //calculate the frequency according to the midinote

    //setters
    void setOscillator(Waveform type, int osc); //function for setting the oscillators of a synth, defined in the subclasses
    
    virtual void setMidiNote(float midiNote) = 0; //function for setting the midiNote of a synth
    virtual void setModulationDepth(float depth);
    virtual void setModulationFreq(float freq); 
    
    
    // static method because this method does not depend on objects
    static std::string waveformTypeToString(Waveform type);

    protected:

    Oscillator* myOscillators[3]; //empty pointer array for storing the oscillators in
    
    float frequency;
    float midiNote;
    float interval;
};

#endif