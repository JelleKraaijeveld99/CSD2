//
// Created by Dean on 27/10/2022.
//
#ifndef _EFF_H_
#define _EFF_H_
#pragma once
#include "tremolo.h"
#include "sine.h"


class Effect {
    
    //constructor and destructor
public:
    Effect();
    ~Effect();

protected:
    //setters and getters
    void setInputChannels(int amount);
    void setOutputChannels(int amount);
    void setDryWet(float wet);

    //functions 
    void changeDryWet(float wet);
    virtual void prepareToPlay (double sampleRate) = 0;
    virtual float output (float input) = 0;

};

#endif