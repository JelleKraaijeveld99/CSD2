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

void tickSynth();

void FmSynthCalc();

float getSampleSynth();

void setMidiNote(float midiNote);

protected:

float carrierFreq; //frequency for the carrier
float modulator1Freq; //frequency for the modulator 1
float modulator2Freq; //frequency for the modulator 2
};

#endif