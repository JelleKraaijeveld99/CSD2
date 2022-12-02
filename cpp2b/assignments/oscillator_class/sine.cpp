#include "sine.h"
#include "math.h"
#include "oscillator.h"

Sine::Sine(float frequency, float samplerate) : Oscillator(frequency, samplerate) //constructor
{
  std::cout << "Sine - constructor\n";
}



Sine::~Sine() { //deconstructor 
  std::cout << "Sine - destructor\n"; 
}

void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  sample = sin(pi * 2 * phase) * amplitude;
}
