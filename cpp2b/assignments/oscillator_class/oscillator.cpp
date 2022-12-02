#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator(float frequency, float samplerate) : frequency(frequency), //constructor
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "oscillator - constructor\n";
}



Oscillator::~Oscillator() { //deconstructor 
  std::cout << "oscillator - destructor\n"; 
}

void Oscillator::setSamplerate(float samplerate) {
  this->samplerate =samplerate;
}


float Oscillator::getSample() {
  return sample;
}


//getters and setters
void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}
