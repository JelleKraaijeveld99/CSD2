//
// Created by Dean on 27/10/2022.
//
#ifndef _EFF_H_
#define _EFF_H_
#pragma once

class Effect {
    
public:
  //constructor and destructor
  Effect();
  ~Effect();

  //setters and getters
  void setInputChannels(int amount);
  void setOutputChannels(int amount);
  void setDryWet(float wetSig);

  //functions 
  // void changeDryWet(float wet);
  virtual void prepareToPlay (double sampleRate) = 0;
  virtual float output (float input) = 0;

protected:
  float wet { 0 };
  float dry { 0 }; 
};

#endif