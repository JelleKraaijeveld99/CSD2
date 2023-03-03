#include "jack_module.h"
#include "circ_buff.h"
#include "waveshaper.h"
#include "chorus.h"
#include "tremolo.h"
#include "sine.h"
#include "delay.h"
#include <array>
#include <iostream>


class Callback : public AudioCallback {

public:

    void prepare (int sampleRate) override {
        for (Tremolo& tremolo : tremolos)
        {
            tremolo.prepareToPlay (static_cast<double> (sampleRate));
            tremolo.setDryWet(0.5);
            tremolo.setRate(200);
        }

        for (Delay& delay : delays){
            delay.setDelayTime(2000);
            delay.setFeedback(0.90);
            delay.prepareToPlay(static_cast<double> (sampleRate));
            delay.setDryWet(0.5);
            delay.resetDelayTime(2000);
        }

        for (WaveShaper& waveshaper : waveshapers){
            waveshaper.prepareToPlay(static_cast<double> (sampleRate));
            waveshaper.setDryWet(1.0);
        }

        for (Chorus& chor : chorus){
            chor.prepareToPlay(static_cast<double> (sampleRate));
            chor.setDryWet(1.0);
        }
    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer; // "link" the variables in  main.cpp to the variables in jack_moduole
        Sine osc(140,0.2,48000);
   
        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                // outputChannels[channel][sample] = waveshapers[channel].output (osc.tick());
                outputChannels[channel][sample] = chorus[channel].output (osc.tick());
                // outputChannels[channel][sample] = delays[channel].output (inputChannels[0][sample]);
                // outputChannels[channel][sample] = tremolos[channel].output (osc.tick());
            }
        }
    }

private:
    std::array<Tremolo,2> tremolos;
    std::array<Delay,2> delays;
    std::array<WaveShaper, 2> waveshapers;
    std::array<Chorus, 2> chorus;
};


int main() {

    auto callback = Callback {};
    auto jack = JackModule (callback);

    // start jack client with 2 inputs and 2 outputs
    jack.init (1, 2);

    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }

    return 0;
}
