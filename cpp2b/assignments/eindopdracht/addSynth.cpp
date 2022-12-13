#include "addSynth.h"
#include "math.h"

AddSynth::AddSynth(int midiNote) : Synthesizer(midiNote) //constructor
{
    myOscillators[0] = new Square(carrierFreq,1.0f,44100); //carrier
    myOscillators[1] = new Square(modulator1Freq,0.5f,44100); //modulator
    myOscillators[2] = new Square(modulator2Freq,0.3f,44100); //modulator
    
    frequency = midiToFreq(midiNote); // calculate the midi note to a frequency
    
    AddSynthCalc();

}

AddSynth::~AddSynth() //deconstructor 
{

}

void AddSynth::AddSynthCalc() //function for giving the oscilators in the fm_synth.h file a certain frequency 
{
    carrierFreq = frequency;
    modulator1Freq = frequency * 2.5;
    modulator2Freq = frequency * 7;
    
    myOscillators[0] -> setFrequency(carrierFreq);
    myOscillators[1] -> setFrequency(modulator1Freq);
    myOscillators[2] -> setFrequency(modulator2Freq);
}

float AddSynth::getSampleSynth()
{
    float addOscillators = myOscillators[0] -> getSample() + myOscillators[1] -> getSample() + myOscillators[2] -> getSample();
    return addOscillators;  
}