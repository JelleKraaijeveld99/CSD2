#include "fm_synth.h"
#include "math.h"

FmSynth::FmSynth(int midiNote) : Synthesizer(midiNote) //constructor
{
    frequency = midiToFreq(midiNote); // calculate the midi note to a frequency
    FmSynthCalc();

}

FmSynth::~FmSynth() //deconstructor 
{

}

void FmSynth::FmSynthCalc() //function for giving the oscilators in the fm_synth.h file a certain frequency 
{
    carrierFreq = frequency;
    modulator1Freq = frequency * 2.5;
    modulator2Freq = frequency * 1.5;
 
    myOscillators[0] = new Square(carrierFreq,1.0f,44100); //carrier
    myOscillators[1] = new Saw(modulator1Freq,0.5f,44100); //modulator
    myOscillators[2] = new Sine(modulator2Freq,0.3f,44100); //modulator

}

float FmSynth::getSampleSynth()
{
    float multipleOscillators = (myOscillators[0] -> getSample() * myOscillators[1] -> getSample()) * myOscillators[2] -> getSample();
    return multipleOscillators;  
}