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
    buffer -> setDistance(currentDelaySamples); //set the distance of the delay in samples
}

float Delay::output(float input){
    buffer -> input(input+(outputBuffer*feedbackAmount)); //input the input to the buffer + output from the sample before * feedback amount to implement feedback
    outputBuffer = buffer -> output();//safe the output of the buffer to add it to the next input 
    buffer -> incrementHeads();
    return (outputBuffer*wet) + (input*wet); //implement wet and dry
}

void Delay::setDelayTime(int MsDelay){
    currentDelayMs = MsDelay; //set the delay time in ms
    msDelayToSamples(MsDelay); //calculate the amount of delay in samples according to the delay in ms
}

void Delay::msDelayToSamples(int MsDelay){
    currentDelaySamples = linearMap(MsDelay,0,sampleRateDelay);//calculate the delay in samples using interpolation
}

void Delay::setFeedback(float feedback){
    if(feedback>0 && feedback<0.99){ //check if feedback is the right amount
        feedbackAmount = feedback;
        std::cout<< "FEEDBACK IS OKAY: " << feedbackAmount << std::endl;
    } else { //feedback is not okay, due to safety it is set to 0, can use some upgrades when GUI is implemented. 
        feedbackAmount = 0; 
        std::cout<< "PLEASE GIVE VALUE BETWEEN 0 AND 0.99! THE FEEDBACK IS NOW SET TO: " << feedbackAmount << std::endl; 
    }   
}

