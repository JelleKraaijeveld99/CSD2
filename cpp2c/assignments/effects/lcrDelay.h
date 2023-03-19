#ifndef _LCRDEL_H_
#define _LCRDEL_H_

#pragma once

#include "delay.h"

class LcrDelay {
    
public:
//concstructor and destructor
    LcrDelay();
    ~LcrDelay();

//functions
    void lcrDelayPrepareToPlay (double sampleRate);
    float lcrDelayOutput (float input, uint channel);

//setters and getters
    void setDelayLine(int ch, int delaytime, float feedback, float drywet);

protected:
//pointer for all the delays in the LCR delay
    Delay *DelayArrP;
//variables for the delaylines
    int delayTimesLCR[3] {2000, 1000, 3000};
    float feedbackLCR[3] {0.0, 0.5, 0.0};
    float drywetLCR[3] {0.5, 1.0, 0.5};
};

#endif