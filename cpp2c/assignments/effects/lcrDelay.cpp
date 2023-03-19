#include "lcrDelay.h"

//constructor
LcrDelay::LcrDelay(){

}

//destructor
LcrDelay::~LcrDelay(){

}

void LcrDelay::lcrDelayPrepareToPlay(double samplerate){
    DelayArrP = new Delay[3];

    for(uint i = 0; i < 3; i++){
        DelayArrP[i].prepareToPlay(samplerate);
        //set all delaylines using the values in the array for each parameter
        setDelayLine(i,delayTimesLCR[i],feedbackLCR[i],drywetLCR[i]);
    };

}

float LcrDelay::lcrDelayOutput(float input, uint channel){

//variables for all the delaylines
    float lOutput;
    float cOutput;
    float rOutput;
//calculating all the values
    // lOutput = DelayArrp[];
}

void LcrDelay::setDelayLine(int ch, int delaytime, float feedback, float drywet){
    delayTimesLCR[ch] = delaytime;
    DelayArrP[ch].setDelayTime(delayTimesLCR[ch]);

    feedbackLCR[ch] = feedback;
    DelayArrP[ch].setFeedback(feedbackLCR[ch]);

    drywetLCR[ch] = drywet;
    DelayArrP[ch].setDryWet(drywetLCR[ch]);
}