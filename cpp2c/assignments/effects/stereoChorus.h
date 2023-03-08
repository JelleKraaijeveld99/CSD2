#ifndef _SCHOR_H_
#define _SCHOR_H_
#include <iostream>
#include "monoChorus.h"

#pragma once

class stereoChorus : public monoChorus {

//constructor and destructor
    stereoChorus();
    ~stereoChorus();
//functions for multi channel processing
    void multiChPrepareToPlay (double sampleRate, uint inChannels, uint outChannels) override;
    float multiChOutput (float input, uint channel = 0) override;
//setters and getters
  
protected:
//empty pointer of type monoChorus
    monoChorus *monoChorus;

};

#endif