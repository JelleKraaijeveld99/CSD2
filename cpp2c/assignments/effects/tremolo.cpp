#include "tremolo.h"


Tremolo::Tremolo() : Effect() {

}

Tremolo::~Tremolo(){

}

// void Tremolo::setDryWet(float wetSig){
//     Effect::setDryWet(wetSig);
// }

void Tremolo::prepareToPlay(double sampleRate){
    osc.prepareToPlay (sampleRate);
}

float Tremolo::output(float input){
    auto modSignal = osc.output();
    modSignal *= amp;
    modSignal += 1.0f - amp;
    return ((input * modSignal) * wet) + (input * dry);
}

void Tremolo::setAmplitude(float amplitude){
    amp = amplitude;
}

void Tremolo::setRate(float rate){
     osc.setDelta (rate);
}