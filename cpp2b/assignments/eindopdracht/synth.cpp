#include "synth.h"
#include "math.h"
// #include "fm_synth.h"

Synthesizer::Synthesizer(int midiNote)
{
}

Synthesizer::~Synthesizer() //deconstructor
{
}


void Synthesizer::tickSynth() //summed op the ticks of
{
    myOscillators[0] -> tick();
    myOscillators[1] -> tick();
    myOscillators[2] -> tick(); 
}

float Synthesizer::midiToFreq(int midiNote, int interval) //extra functionality with adding interval
{
    float a = 440; //frequency of A (coomon value is 440Hz)
    float freq = (a / 32) * pow(2, ((midiNote + interval - 9) / 12.0));
    // std::cout << freq << std::endl;
    return freq;
}


void Synthesizer::setModulationDepth(float depth){

}

void Synthesizer::setModulationFreq(float freq){

}

void Synthesizer::setOscillator(Waveform type, int osc)
{
  // std::cout << "\n• Synth::setWaveform" << std::endl;

  // std::cout << "\n - using " << waveformTypeToString(type) << " as waveform"
  //   << std::endl;
  switch (type) {
  case Waveform::Sine1:
    // set sine
    // std::cout << "\n--- selecting sine";
    myOscillators[osc] = new Sine(0,1.0f,44100);
    break;
  case Waveform::Saw1:
    // set saw
    // std::cout << "\n--- selecting saw";
    myOscillators[osc] = new Saw(0,1.0f,44100);
    break;
  case Waveform::Square1:
    // set square
    // std::cout << "\n--- selecting square";
    myOscillators[osc] = new Square(0,1.0f,44100);
    break;
  default:
    break;
  }
}

std::string Synthesizer::waveformTypeToString(Waveform type)
{
  switch(type) {
    case Waveform::Sine1:
      return "sine";
    case Waveform::Saw1:
      return "saw";
    case Waveform::Square1:
      return "square";
    default:
      return "Invalid waveform";
  }
}
