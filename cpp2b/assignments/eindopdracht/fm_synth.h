#ifndef _H_FMS_
#define _H_FMS_

#include <iostream>
#include <cmath>
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "synth.h"

#pragma once

class FmSynth : public Synthesizer
{

public:
FmSynth(int midiNote);//constructor
~FmSynth();//deconstructor 

enum Waveform{
    Sine1 = 0,
    Square1 = 1,
    Saw1 = 2
};

void tickSynth(); //function for ticking all the oscs in this synth
void FmSynthCalc(); //function for giving the oscilators in the fm_synth.h file a certain frequency based on the midi note

//setters and getters
float getSampleSynth(); //function for calculating and returning the sample of the modulated signal
void setMidiNote(float midiNote); //function for setting the midinote of the synth
void setOscillator(Waveform type, int osc); //function for setting the oscillators

// static method because this method does not depend on objects
static std::string waveformTypeToString(Waveform type);

protected:

//variables for the synth
float carrierFreq; //frequency for the carrier
float modulatorFreq; //frequency for the modulator 
float modulatedFreq; //frequency that is modulated
float modulationDepth; //depth of the modulation

//variables for the user
float userModulationDepth; 
float userModulatorFreq;
};

#endif