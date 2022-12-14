#include "addSynth.h"
#include "math.h"



AddSynth::AddSynth(int midiNote) : Synthesizer(midiNote) //constructor
{
    frequency = midiToFreq(midiNote,0); // calculate the midi note to a frequency
    modulator1Freq = midiToFreq(midiNote,7);
    modulator2Freq = midiToFreq(midiNote,12);

    myOscillators[0] = new Sine(carrierFreq,1.0f,44100); //carrier
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
    
    myOscillators[0] -> setFrequency(carrierFreq);
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