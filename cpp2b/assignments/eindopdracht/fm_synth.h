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

void tickSynth(); //function for ticking all the oscs in this synth
void FmSynthCalc(); //function for giving the oscilators in the fm_synth.h file a certain frequency based on the midi note

//setters and getters
float getSampleSynth(); //function for calculating and returning the sample of the modulated signal
void setMidiNote(float midiNote); //function for setting the midinote of the synth
void setModulationDepth(float depth); //function for setting the modulation depth
void setModulationFreq(float freq); //function for setting the modulator frequency

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