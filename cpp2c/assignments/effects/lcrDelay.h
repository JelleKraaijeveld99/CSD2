#ifndef _LCRDEL_H_
#define _LCRDEL_H_

#pragma once

#include "delay.h"
#include <iostream>

class LcrDelay {
    
public:
//concstructor and destructor
    LcrDelay();
    ~LcrDelay();

//functions
    void lcrDelayPrepareToPlay (double sampleRate);
    float lcrDelayOutput (float input, uint ch);

//setters and getters
    void setDelayLine(int ch, int delaytime, float feedback, float drywet);

protected:
//pointer for all the delays in the LCR delay
    Delay *DelayArrP;
//variables for the delaylines, 0 = L, 1 = R, 2 = C

    int delayTimesLCR[3]= {2000, 3000, 1000};
    float feedbackLCR[3]= {0.0, 0.0, 0.5};
    float drywetLCR[3]= {0.5,0.5,0.9};
};

#endif