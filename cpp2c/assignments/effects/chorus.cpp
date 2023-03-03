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
    Effect::sampleRate = sampleRate;
    minDelay = 1; //initialise the minimum delay in ms
    modDepth = 1; //initialise the modulation depth (amp of the LFO)
    modRate = 30; //initialise the modulation rate (freq of the LFO)
    maxDelay = minDelay + modRate; //the maximum delaytime 
    int maxDelaySamples = msToSamples(maxDelay, sampleRate);
    calculateDelayCenter(); //function calculating the center of the delay that is going to be modulated 
    std::cout << "this is the delaycenter ms: " << delayCenterMs << std::endl;
    std::cout << "this is the delaycenter samples: " << delayCenterSamples << std::endl;
    osc = new Sine(modRate,modDepth,Effect::sampleRate); //use sine as LFO
    buffer = new CircBuffer(maxDelaySamples+1); //make buffer as big as the maximum delay time
}

float Chorus::output(float input){
    float newDelayDistMs = (delayCenterMs * calculateDelayLine());
    // std::cout << "this is the newDelayDistMs: " << newDelayDistMs << std::endl;

    float newDelayDistSamples = msToSamples(newDelayDistMs,sampleRate);
    // std::cout << "this is the newDelayDistSamples: " << newDelayDistSamples << std::endl;

    // std::cout << "this is the modulatedDelaySamples " << modulatedDelaySamples << std::endl;

    buffer -> setDistance(newDelayDistSamples);
    buffer -> input(input);
    float outputBuffer = buffer -> interpolatedOutput();
    buffer -> incrementHeads();
    
    return (outputBuffer*wet)+(input*dry);
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
    delayCenterSamples = msToSamples(delayCenterMs, sampleRate);
}

float Chorus::calculateDelayLine(){
    // -1 tot 1
    float value = osc->tick();
    // // 0 tot 2
    value = value + 1;
    // 0 tot modDepth
    value *= modDepth;
    // (minDelay) tot (modDepth + minDelay)
    // value += minDelay;
    return value;
}

void Chorus::setRate(float freq){
    modRate = freq; 
    osc -> setFrequency(freq);
}



