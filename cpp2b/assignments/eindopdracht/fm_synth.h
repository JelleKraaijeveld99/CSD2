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
float getSampleSynth(); //function for calculating and returning the sample of the modulated signal
void setMidiNote(float midiNote); //function for setting the midinote of the synth

protected:

float carrierFreq; //frequency for the carrier
float modulatorFreq; //frequency for the modulator 1
float modulator2Freq; //frequency for the modulator 2
float modulatedFreq;
};

#endif