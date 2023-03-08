#ifndef _SCHOR_H_
#define _SCHOR_H_
#include <iostream>
#include <array>
#include <vector>
#include "MonoChorus.h"

#pragma once

class stereoChorus {

public:
//constructor and destructor
    stereoChorus();
    ~stereoChorus();
//functions for multi channel processing
    void multiChPrepareToPlay (double sampleRate, uint inChannels, uint outChannels);
    float multiChOutput (float input, uint channel);
    void setChannel(int channel, int depth, int rate, int minimumDelay, float wet);
//setters and getters
  
protected:
//empty pointer of type MonoChorus
    MonoChorus *monoChorusArrP;

//variables 
    uint inputChannels;
    uint outputChannels;
};

#endif