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
    minDelay = 1; //initialise the minimum delay in ms
    modDepth = 20; //initialise the modulation depth (rate of the LFO)
    maxDelay = minDelay + modDepth; //the maximum delaytime 
    calculateDelayCenter(); //function calculating the center of the delay that is going to be modulated 
    osc = new Sine(modDepth,0.4,sampleRate); //use sine as LFO
    buffer = new CircBuffer(msToSamples(maxDelay, sampleRate)); //make buffer as big as the maximum delay time
}

float Chorus::output(float input){
    // buffer -> setDistance(delayCenter*osc->getSample());
    buffer -> input(input);

}

void Chorus::setMaxDelay(int ms){
    maxDelay = ms;
    minDelay = maxDelay - modDepth;
    calculateDelayCenter();
}

void Chorus::setMinDelay(int ms){
    minDelay = ms;
    maxDelay = minDelay + modDepth;
    calculateDelayCenter();
}

void Chorus::setModDepth(int ms){
    modDepth = ms;
    maxDelay = minDelay + modDepth;
    calculateDelayCenter();
}

void Chorus::calculateDelayCenter(){
    delayCenterMs = ((maxDelay-minDelay)/2)+minDelay;
    // delayCenterSamples = msToSamples(delayCenterMs, sampleRate);
}

void Chorus::calculateDelayLine(){
    
}



