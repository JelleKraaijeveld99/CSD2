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
    return freq;
}

