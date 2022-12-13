#ifndef _SAW_H_
#define _SAW_H_ 
#include <iostream>
#include <cmath>

#include "oscillator.h"

#pragma once


class Saw : public Oscillator
{
public:
  //Constructor and destructor
  Saw(float frequency, float amplitude, float samplerate = 44100);
  ~Saw(); 

  // go to next sample
  void calculate();

}; //

#endif
