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

void AddSynthCalc();

void tickSynth();

float getSampleSynth();

void setMidiNote(float midiNote);

void setOscillator(Waveform type, int osc); //function for setting the oscillators

// static method because this method does not depend on objects
static std::string waveformTypeToString(Waveform type);

protected:
//make oscillators

float carrierFreq; //frequency for the carrier
float modulator1Freq; //frequency for the modulator 1
float modulator2Freq; //frequency for the modulator 2
};

#endif