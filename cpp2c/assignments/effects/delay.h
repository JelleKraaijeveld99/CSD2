#ifndef _DELAY_H_
#define _DELAY_H_

#pragma once

#include "effect.h"
#include "circ_buff.h"
#include "interpolation.h"

class Delay : public Effect {

public:
    //construcor and destructor
    Delay();
    ~Delay();

    //functions
    void prepareToPlay(double sampleRate) override;
    float output(float input) override;
    void setDelayTime(int MsDelay);
    void msDelayToSamples(int MsDelay);

    int currentDelayMs;
    int currentDelaySamples;
    int sampleRateDelay;

    CircBuffer *buffer; //empty pointer of the type CircBuffer
};


#endif