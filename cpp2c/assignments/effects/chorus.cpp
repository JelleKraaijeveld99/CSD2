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
    modDepth = 1; //initialise the modulation depth (amp of the LFO)
    modRate = 30; //initialise the modulation rate (freq of the LFO)
    maxDelay = minDelay + modRate; //the maximum delaytime 
    calculateDelayCenter(); //function calculating the center of the delay that is going to be modulated 
    osc = new Sine(modRate,modDepth,sampleRate); //use sine as LFO
    buffer = new CircBuffer(msToSamples(maxDelay, sampleRate)); //make buffer as big as the maximum delay time
}

float Chorus::output(float input){
    float newDelayDist = calculateDelayLine();
    buffer -> setDistance(newDelayDist);
    buffer -> input(input);
} 

void Chorus::setMaxDelay(int ms){
    maxDelay = ms;
    minDelay = maxDelay - modRate;
    calculateDelayCenter();
}

void Chorus::setMinDelay(int ms){
    minDelay = ms;
    maxDelay = minDelay + modRate;
    calculateDelayCenter();
}

void Chorus::setModDepth(float depth){
    modDepth = depth;
    // osc -> setAmplitude(modDepth);
}

void Chorus::calculateDelayCenter(){
    delayCenterMs = ((maxDelay-minDelay)/2)+minDelay;
    // delayCenterSamples = msToSamples(delayCenterMs, sampleRate);
}

float Chorus::calculateDelayLine(){
    // -1 tot 1
    float value = osc->tick();
    // 0 tot 1
    value = value / 2 + 1;
    // 0 tot modDepth
    value *= modDepth;
    // (minDelay) tot (modDepth + minDelay)
    value += minDelay;
    
    return value;
}

void Chorus::setRate(float freq){
    modRate = freq; 
    osc -> setFrequency(freq);
}



