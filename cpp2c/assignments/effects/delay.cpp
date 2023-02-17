#include "delay.h"

Delay::Delay(){

}

Delay::~Delay(){
    delete buffer;
}

void Delay::prepareToPlay(double sampleRate){
    sampleRateDelay = sampleRate;
    //calculate the delay in samples to make a buffer and distance with the correct size
    currentDelaySamples = linearMap(currentDelayMs,0,sampleRate);
    //make a buffer as big as the delaytime in samples
    buffer = new CircBuffer(currentDelaySamples+1); //declare a buffer object to the empty buffer pointer
    buffer -> setDistance(currentDelaySamples);
}

float Delay::output(float input){
    buffer -> input(input);
    float Output = buffer -> output();
    buffer -> incrementHeads();
    return Output;
}

void Delay::setDelayTime(int MsDelay){
    currentDelayMs = MsDelay;
    msDelayToSamples(MsDelay);
}

void Delay::msDelayToSamples(int MsDelay){
    currentDelaySamples = linearMap(MsDelay,0,sampleRateDelay);
}

