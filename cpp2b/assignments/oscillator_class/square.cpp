#include "square.h"
#include "math.h"
#include "oscillator.h"

Square::Square(float frequency, float samplerate) : Oscillator(frequency, samplerate) //constructor
{
  std::cout << "Square - constructor\n";
}



Square::~Square() { //deconstructor 
  std::cout << "Square - destructor\n"; 
}

void Square::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  if(phase > 1.0f) {
    phase -= 1.0f;
  }


  sample = (2*amplitude*phase)-amplitude;
}

