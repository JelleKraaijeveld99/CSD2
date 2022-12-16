#include "fm_synth.h"
#include "math.h"

FmSynth::FmSynth(int midiNote) : Synthesizer(midiNote) //constructor
{
    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency
    modulator1Freq = frequency * 2.5;
    // modulator2Freq = frequency * 4.5;

    myOscillators[0] = new Sine(frequency,1.0f,44100); //carrier
    myOscillators[1] = new Sine(modulator1Freq,0.5f,44100); //modulator
    myOscillators[2] = new Sine(0,0.3f,44100); //modulator
}

FmSynth::~FmSynth() //deconstructor 
{

}

void FmSynth::FmSynthCalc() //function for giving the oscilators in the fm_synth.h file a certain frequency 
{
    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency
    modulator1Freq = midiToFreq(midiNote,7);
    modulator2Freq = modulatedFreq;
    
    myOscillators[0] -> setFrequency(frequency); //carrier
    myOscillators[1] -> setFrequency(modulator1Freq); //modulator
    myOscillators[2] -> setFrequency(modulator2Freq); //result
}

float FmSynth::getSampleSynth()
{   

    float carrierVar = myOscillators[0]->getFrequency(); // carrier frequency
    float modulatedFreq = carrierVar * (myOscillators[1] -> getSample() + 1); //modulate the freq of the carrier with the modulator
    // std::cout << modulatedFreq << std::endl;
    myOscillators[2] -> setFrequency(modulatedFreq); //use the modulated frequency to set the third oscillator
    float carriersample = myOscillators[2] -> getSample() + myOscillators[0] -> getSample(); //return the samples of the modulated frequency + the carrier 
    std::cout << carriersample;
    return carriersample;
}

void FmSynth::tickSynth()
{   //carrier carrier*modulator1.getsample*modulator2.getsample

    myOscillators[0] -> tick(); //car
    myOscillators[1] -> tick(); //smod1
    myOscillators[2] -> tick(); //mod2
}

void FmSynth::setMidiNote(float midiNote){ //setting the midi note of the synth and giving all the oscillators the right frequency scaled to the midi note
     this -> midiNote = midiNote;
     FmSynthCalc();
}