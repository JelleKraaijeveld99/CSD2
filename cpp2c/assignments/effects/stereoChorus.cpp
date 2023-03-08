#include "stereoChorus.h"

//constructor
stereoChorus::stereoChorus(){

}

//destructor
stereoChorus::~stereoChorus() {
    delete monoChorusArrP;
}

void stereoChorus::multiChPrepareToPlay(double sampleRate, uint inChannels, uint outChannels){
    outputChannels = outChannels;
    inputChannels = inChannels;
    monoChorusArrP = new MonoChorus[outputChannels];
    //setting the channels with the variables depth, rate and minimum delay
    setChannel(0,5,5,1,0.9);
    setChannel(1,10,10,1,0.9);
}

float stereoChorus::multiChOutput(float input, uint channel){
    float output = (monoChorusArrP + channel) -> output(input);
    
    return output;
}

void stereoChorus::setChannel(int channel, int depth, int rate, int minimumDelay, float wet){
    //monoChorusArrP + 0 = first MonoChorus in the array
   monoChorusArrP[channel].setMinDelay(minimumDelay);
//    monoChorusArrP[channel].setRate(rate);
   monoChorusArrP[channel].setModDepth(depth);
   monoChorusArrP[channel].setDryWet(wet);
}


