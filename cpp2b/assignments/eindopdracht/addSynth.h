#ifndef _H_ADDS_
#define _H_ADDS_

#include <iostream>
#include <cmath>
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "synth.h"

#pragma once

class AddSynth : public Synthesizer
{
public:
AddSynth(int midiNote);//constructor
~AddSynth();//deconstructor 

void AddSynthCalc(); //calculation of how the oscillators merge
void tickSynth(); //tick all the oscillators together
float getSampleSynth(); //get the sample of the additive synth

//setters
void setMidiNote(float midiNote);

protected:
//variables for the frequencies of the oscillators
float carrierFreq; //frequency for the carrier
float modulator1Freq; //frequency for the modulator 1
float modulator2Freq; //frequency for the modulator 2
};

#endif