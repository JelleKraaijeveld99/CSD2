//
// Created by Dean on 27/10/2022.
//
#ifndef _TREM_H_
#define _TREM_H_

#pragma once

#include "effect.h"
#include "sine.h"

class Tremolo : public Effect {

public:
 //constructor and destructor
    Tremolo();
    ~Tremolo();

    //functions
    void prepareToPlay(double sampleRate) override;
    float output(float input) override;
    // void setDryWet(float wetSig); 

    //setters and getters
    void setAmplitude (float amplitude);
    void setRate (float rate);

protected:
    Sine osc;
    float amp { 1.0f };
};

#endif
