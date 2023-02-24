#include "chorus.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

Chorus::Chorus() : Effect(){

}

Chorus::~Chorus(){
    delete buffer;
}

void Chorus::prepareToPlay(double sampleRate){
    minDelay = 1;
    modDepth = 20;
    maxDelay = minDelay + modDepth;
    osc = new Sine(3,0.4,sampleRate); //use sine as LFO
    buffer = new CircBuffer(msToSamples(maxDelay, sampleRate)); //make buffer as big as the maximum delay time
}

float Chorus::output(float input){

}

void Chorus::setMaxDelay(int ms){
    maxDelay = ms;
    minDelay = maxDelay - modDepth;
}

void Chorus::setMinDelay(int ms){
    minDelay = ms;
    maxDelay = minDelay + modDepth;
}

void Chorus::setModDepth(int ms){
    modDepth = ms;
    maxDelay = minDelay + modDepth;
}



