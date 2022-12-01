#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, float samplerate)
{
  Oscillator::setFrequency(frequency);
  Oscillator::setAmplitude(1.0);
  Oscillator::setSamplerate(samplerate);
  Oscillator::setPhase(0);
  Oscillator::setSample(0);

  std::cout << "Sine - constructor\n";
}



Sine::~Sine() { //deconstructor 
  std::cout << "Sine - destructor\n"; 
}

