#include "addSynth.h"
#include "math.h"



AddSynth::AddSynth(int midiNote) : Synthesizer(midiNote) //constructor
{
    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency
    modulator1Freq = midiToFreq(midiNote,7);
    modulator2Freq = midiToFreq(midiNote,12);

    myOscillators[0] = new Sine(frequency,1.0f,44100); //carrier
    myOscillators[1] = new Sine(modulator1Freq,0.7f,44100); //modulator
    myOscillators[2] = new Sine(modulator2Freq,0.5f,44100); //modulator
    
}

AddSynth::~AddSynth() //deconstructor 
{
}

void AddSynth::AddSynthCalc() //function for giving the oscilators in the fm_synth.h file a certain frequency 
{   
    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency
    modulator1Freq = midiToFreq(midiNote,7);
    modulator2Freq = midiToFreq(midiNote,12);
    
    myOscillators[0] -> setFrequency(frequency);
    myOscillators[1] -> setFrequency(modulator1Freq);
    myOscillators[2] -> setFrequency(modulator2Freq);
}

float AddSynth::getSampleSynth()
{
    float addOscillators = myOscillators[0] -> getSample() + myOscillators[1] -> getSample() + myOscillators[2] -> getSample();
    return addOscillators;  
}

void AddSynth::setMidiNote(float midiNote){ //setting the midi note of the synth and giving all the oscillators the right frequency scaled to the midi note
     this -> midiNote = midiNote;
     AddSynthCalc();
}

void AddSynth::tickSynth()
{
    myOscillators[0] -> tick(); //car
    myOscillators[1] -> tick(); //mod1
    myOscillators[2] -> tick(); //mod2
}

void AddSynth::setOscillator(Waveform type, int osc)
{
  std::cout << "\n• Synth::setWaveform" << std::endl;

  std::cout << "\n - using " << waveformTypeToString(type) << " as waveform"
    << std::endl;
  switch (type) {
  case Waveform::Sine1:
    // set sine
    std::cout << "\n--- selecting sine";
    myOscillators[osc] = new Sine(0,1.0f,44100);
    break;
  case Waveform::Saw1:
    // set saw
    std::cout << "\n--- selecting saw";
    myOscillators[osc] = new Saw(0,1.0f,44100);
    break;
  case Waveform::Square1:
    // set square
    std::cout << "\n--- selecting square";
    myOscillators[osc] = new Square(0,1.0f,44100);
    break;
  default:
    break;
  }
}

std::string AddSynth::waveformTypeToString(Waveform type)
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