#include "fm_synth.h"
#include "math.h"

FmSynth::FmSynth(int midiNote) : Synthesizer(midiNote) //constructor
{
    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency
    modulator1Freq = frequency * 2.5;
    modulator2Freq = frequency * 4.5;

    myOscillators[0] = new Sine(carrierFreq,1.0f,44100); //carrier
    myOscillators[1] = new Sine(modulator1Freq,0.5f,44100); //modulator
    myOscillators[2] = new Sine(modulator2Freq,0.3f,44100); //modulator
    
    FmSynthCalc();

}

FmSynth::~FmSynth() //deconstructor 
{

}

void FmSynth::FmSynthCalc() //function for giving the oscilators in the fm_synth.h file a certain frequency 
{
    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency
    modulator1Freq = midiToFreq(midiNote,7);
    modulator2Freq = midiToFreq(midiNote,12);
    
    myOscillators[0] -> setFrequency(carrierFreq);
    myOscillators[1] -> setFrequency(modulator1Freq);
    myOscillators[2] -> setFrequency(modulator2Freq);
}

float FmSynth::getSampleSynth()
{
  float sample = myOscillators[0] -> getSample();
  return sample;
}

void FmSynth::tickSynth()
{   //carrier carrier*modulator1.getsample*modulator2.getsample
    float modulatedFreq = myOscillators[0] -> getFrequency() * myOscillators[1] -> getSample() * myOscillators[2] -> getSample();
    myOscillators[0] -> setFrequency(modulatedFreq);

    myOscillators[0] -> tick(); //car
    myOscillators[1] -> tick(); //smod1
    myOscillators[2] -> tick(); //mod2
}

void FmSynth::setMidiNote(float midiNote){ //setting the midi note of the synth and giving all the oscillators the right frequency scaled to the midi note
     this -> midiNote = midiNote;
     FmSynthCalc();
}