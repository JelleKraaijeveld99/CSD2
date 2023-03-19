#include "stereoChorus.h"

//constructor
stereoChorus::stereoChorus(){

}

//destructor
stereoChorus::~stereoChorus() {
    // delete monoChorusArrP;
}

void stereoChorus::multiChPrepareToPlay(double sampleRate, uint inChannels, uint outChannels){
    outputChannels = outChannels;
    inputChannels = inChannels;
    monoChorusArrP = new MonoChorus[outputChannels];

    for(uint i = 0; i < outChannels; i++){
        monoChorusArrP[i].prepareToPlay(sampleRate);
    }

    //setting the channels with the variables depth, rate and minimum delay
    setChannel(0,1,15,17,0.8);
    setChannel(1,1,15,10,0.8);
}

float stereoChorus::multiChOutput(float input, uint channel){
    // std::cout << "multiChOutput " << channel << std::endl;

    float output = monoChorusArrP[channel].output(input);
    
    return output;
}

void stereoChorus::setChannel(int channel, float depth, int rate, int minimumDelay, float wet){
    // std::cout << "setChannel " << channel << std::endl;
    //monoChorusArrP + 0 = first MonoChorus in the array
   monoChorusArrP[channel].setMinDelay(minimumDelay);
   monoChorusArrP[channel].setRate(rate);
   monoChorusArrP[channel].setModDepth(depth);
   monoChorusArrP[channel].setDryWet(wet);
}


