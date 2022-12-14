#include "callback.h"
#include "oscillator.h"
#include "sine.h"
#include "synth.h"
#include "fm_synth.h"



void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process(AudioBuffer buffer) {
    ADDsynth.setMidiNote(73);
  for (int i = 0; i < buffer.numFrames; ++i) {
    // write sample to buffer at channel 0, amp = 0.25
    buffer.outputChannels[0][i] = ADDsynth.getSampleSynth();
    ADDsynth.tickSynth();

  }
}
