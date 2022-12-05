#ifndef _SINE_H_
#define _SINE_H_ 
#include <iostream>
#include <cmath>

#include "oscillator.h"

#define deBug

#pragma once


class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine(float frequency, float samplerate = 44100);
  ~Sine();

  // go to next sample
  void tick();

}; //

#endif
