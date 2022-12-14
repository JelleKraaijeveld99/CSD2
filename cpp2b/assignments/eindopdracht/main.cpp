#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "audioToFile.h"
#include "oscillator.h"
#include "callback.h"
#include "synth.h"
#include "fm_synth.h"
#include "addSynth.h"
#include "jack_module.h"
#include "math.h"
#include "melody.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 0

void updatePitch(Melody* melody, Synthesizer* ADDsynth) { //function for updating the pitch of a synthesizer
  float pitch = melody->getPitch();
  std::cout << "next pitch: " << pitch << std::endl;
  ADDsynth->setMidiNote(pitch);
}

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  const double samplerate = jack.getSamplerate();

  //section for making the synth
  AddSynth ADDsynth(60);

  Melody melody;

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 5000; i++) {
    fileWriter.write(std::to_string(square.getSample()) + "\n");
    square.tick();
  }
  std::cout << "\nWROTE TO FILE = DONE." << std::endl;
#else

  float amplitude = 0.025;

  // keep track of the frameIndex, to play notes at a given frame interval
  int frameIndex = 0;
  const int frameInterval = 0.20 * samplerate;
  // start with the first pitch
  updatePitch(&melody, &ADDsynth);


  //assign a function to the JackModule::onProces
  jack.onProcess = [&ADDsynth, &amplitude, &melody, &frameIndex, frameInterval](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    // fill output buffer
    for(unsigned int i = 0; i < nframes; i++) {

      // check if we need to set the frequency to the next note
      if(frameIndex >= frameInterval) {
        // reset frameIndex
        frameIndex = 0;
        updatePitch(&melody, &ADDsynth);
      } else {
        // increment frameindex
        frameIndex++;
      }

      // write sample to output
      outBuf[i] = ADDsynth.getSampleSynth() * amplitude;

      // calculate next sample
      ADDsynth.tickSynth();

    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }
#endif
  //end the program
  return 0;

} // main()
