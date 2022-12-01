#ifndef _OSC_H_
#define _OSC_H_
#include <iostream>
#include <cmath>

#pragma once

class Oscillator
{
public:
  //Constructor and destructor
  Oscillator();
  ~Oscillator();
  
  void setSamplerate(float samplerate);
  //return the current sample
  
  void setSample(float sample);
  float getSample();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

  void setPhase(float phase);
  float getPhase();

  void setAmplitude(float amplitude);
  float getAmplitude();

  float getPi();

  

  // go to next sample
  void tick();

private:

  float frequency; //the oscillator needs a frequency
  float amplitude; //the osc needs a amplitude 
  float phase; //
  // sample contains the current sample
  float sample;
  float samplerate;
  
  const float pi = acos (-1);  //atan(1) * 4; <-- vak van Pieter.
};


#endif
