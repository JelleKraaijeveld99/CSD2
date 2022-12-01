#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "oscillator.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override { //give the samplerate to the JACK module 
    samplerate = (float) rate; //set the samplerate of the sine and the samplerate that is send to JACK module the sae
    sine.setSamplerate(samplerate); //set the samplerate of the sine
    std::cout << "\nsamplerate: " << samplerate << "\n"; //print the samplerate 
  }

  void process(AudioBuffer buffer) override { //send the audiodata to JACK -- sample for sample with sine.getSample and sine.tick to go to the next sample 
    for (int i = 0; i < buffer.numFrames; ++i) {
      // write sample to buffer at channel 0, amp = 0.25
      buffer.outputChannels[0][i] = sine.getSample(); 
      sine.tick(); //go to the next sample 
    }
  }
  private:
  float samplerate = 44100; //set the samplerate 
  Sine sine = Sine(440, samplerate); //make the sine here 
};

int main(int argc,char **argv)
{
  auto callback = CustomCallback {};
  auto jackModule = JackModule { callback };

  jackModule.init (0, 1);

  bool running = true;
  while (running) {
      switch (std::cin.get()) {
          case 'q':
              running = false;
      }
  }

  //end the program
  return 0;
} // main()