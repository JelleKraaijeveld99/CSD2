#include "fm_synth.h"
#include "math.h"

FmSynth::FmSynth(int midiNote) : Synthesizer(midiNote) //constructor
{   

    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency
    modulatorFreq = 667;
    modulationDepth = 238; 
    
    myOscillators[0] = new Sine(frequency,1.0f,44100); //carrier
    myOscillators[1] = new Sine(modulatorFreq,1.0f,44100); //modulator
    myOscillators[2] = new Sine(0,1.0f,44100); //resulted sound
}

FmSynth::~FmSynth() //deconstructor 
{

}

void FmSynth::FmSynthCalc() 
{
    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency

    myOscillators[0] -> setFrequency(frequency); //carrier
    myOscillators[1] -> setFrequency(modulatorFreq); //modulator
    myOscillators[2] -> setFrequency(modulatedFreq); //result
}

float FmSynth::getSampleSynth()
{  
    float carrierVar = myOscillators[0]->getFrequency(); // carrier frequency
    float modulatedFreq = carrierVar + (myOscillators[1] -> getSample()) * modulationDepth; //modulate the freq of the carrier with the modulator the multiplier is depth
    myOscillators[2] -> setFrequency(modulatedFreq); //use the modulated frequency to set the third oscillator (modulated) signal
    float modulatedsample = myOscillators[2] -> getSample(); //return the samples of the modulated frequency (+ the carrier) 
    return modulatedsample;
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

void FmSynth::setModulationDepth(float depth){ //setter for the modulation depth
  this -> modulationDepth = depth;
}

void FmSynth::setModulationFreq(float freq){ //setter for the modulation
  this -> modulatorFreq = freq;
}
