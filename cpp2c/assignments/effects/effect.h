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

  //functions for mono signals
  virtual void prepareToPlay (double sampleRate) = 0;
  virtual float output (float input) = 0;

  //functions for multi-channel signals
  virtual void multiChPrepareToPlay (double sampleRate, uint inChannels, uint outChannels) = 0;
  virtual float multiChOutput (float input, uint channel = 0) = 0;

  float msToSamples(float ms, int sampleRate);

protected:
  float wet { 0 };
  float dry { 0 }; 
  int sampleRate { 0 }; 
  uint inputChannels { 0 };
  uint outputChannels { 0 };

};

#endif