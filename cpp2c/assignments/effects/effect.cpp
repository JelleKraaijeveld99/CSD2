#include "effect.h"

Effect::Effect(){

}

Effect::~Effect(){

}

void Effect::setDryWet(float wetSig){
    if(wetSig>1.0){
        wetSig = 1.0;
    }
    wet = wetSig;
    dry = 1 - wetSig;
}

void Effect::setInputChannels(int amount){

}

void Effect::setOutputChannels(int amount){

}

int Effect::msToSamples(int ms, int sampleRate){
    return(int)(((long) ms) * sampleRate/1000);
}




