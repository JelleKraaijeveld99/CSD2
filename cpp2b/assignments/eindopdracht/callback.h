#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "oscillator.h"
#include "sine.h"
#include "synth.h"
#include "fm_synth.h"
#include "addSynth.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  // FmSynth FMsynth = FmSynth(52);//make synths 
  AddSynth ADDsynth = AddSynth(48);
};

#endif //CALLBACK_H
