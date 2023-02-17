#include "delay.h"
#include <iostream>

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
    buffer -> input(input+(outputBuffer*feedbackAmount));
    outputBuffer = buffer -> output();
    buffer -> incrementHeads();
    return (outputBuffer*wet) + (input*wet);
}

void Delay::setDelayTime(int MsDelay){
    currentDelayMs = MsDelay;
    msDelayToSamples(MsDelay);
}

void Delay::msDelayToSamples(int MsDelay){
    currentDelaySamples = linearMap(MsDelay,0,sampleRateDelay);
}

void Delay::setFeedback(float feedback){
    if(feedback>0 && feedback<0.99){
        feedbackAmount = feedback;
        std::cout<< "FEEDBACK IS OKAY: " << feedbackAmount << std::endl;
    } else {
        feedbackAmount = 0;
        std::cout<< "PLEASE GIVE VALUE BETWEEN 0 AND 0.99! THE FEEDBACK IS NOW SET TO: " << feedbackAmount << std::endl; 
    }   
}

