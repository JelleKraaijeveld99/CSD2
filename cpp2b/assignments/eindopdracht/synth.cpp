#include "synth.h"
#include "math.h"

Synthesizer::Synthesizer(int midiNote)
{
    frequency = midiToFreq(midiNote); // calculate the midi note to a frequency
    sine.setFrequency(frequency); // set the frequency of the osc in the synth.h file
}

Synthesizer::~Synthesizer() //deconstructor
{
}

void Synthesizer::tickSynth()
{
    sine.tick();
    // sine1.tick();
}

float Synthesizer::getSampleSynth()
{      

    float multipleOscillators = sine.getSample();
    
    return multipleOscillators;  
}

float Synthesizer::midiToFreq(int midiNote)
{
    float a = 440; //frequency of A (coomon value is 440Hz)
    float freq = (a / 32) * pow(2, ((midiNote - 9) / 12.0));
    return freq;
}

