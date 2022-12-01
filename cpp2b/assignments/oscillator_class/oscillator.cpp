#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator() : frequency(frequency), //constructor
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

void Oscillator::setSample(float sample) {
this->sample = sample;
}

float Oscillator::getSample() {
  return sample;
}

void Oscillator::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }
  sample = sin(pi * 2 * phase) * amplitude;

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

void Oscillator::setPhase(float phase){
    this->phase = phase;
}

float Oscillator::getPhase(){
    return phase;
}

void Oscillator::setAmplitude(float amplitude){
    this->amplitude = amplitude;
}

float Oscillator::getAmplitude(){
    return amplitude;
}

float Oscillator::getPi(){
    return pi;
}
