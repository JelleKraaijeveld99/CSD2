#include "saw.h"
#include "math.h"
#include "oscillator.h"

Saw::Saw(float frequency, float samplerate) : Oscillator(frequency, samplerate) //constructor
{
  std::cout << "Saw - constructor\n";
}



Saw::~Saw() { //deconstructor 
  std::cout << "Saw - destructor\n"; 
}

void Saw::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  sample = (2*amplitude*phase)-amplitude;
}
