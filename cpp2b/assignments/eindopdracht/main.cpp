#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "melody.h"
#include "synth.h"
#include "addSynth.h"
#include "fm_synth.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 0


void updatePitch(Melody* melody, Synthesizer* fmsynth) {
  float pitch = melody->getPitch();
  std::cout << "next pitch: " << pitch << std::endl;
  fmsynth->setMidiNote(pitch);
}



int main()
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init("jelle_synth");
  const double samplerate = jack.getSamplerate();

//make the synth objects
  FmSynth fmsynth(60);
  AddSynth addsynth(60);

  //make a pointer for the synths
  Synthesizer *synthpointer = &fmsynth;

  Melody melody;

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 5000; i++) {
    fileWriter.write(std::to_string(fmsynth.getSampleSynth()) + "\n");
    fmsynth.tickSynth();
  }
  std::cout << "\nWROTE TO FILE = DONE." << std::endl;
#else

  float amplitude = 0.025;

  // keep track of the frameIndex, to play notes at a given frame interval
  int frameIndex = 0;
  const int frameInterval = 0.2 * samplerate;
  // start with the first pitch
  updatePitch(&melody, synthpointer);


  //assign a function to the JackModule::onProces
  jack.onProcess = [synthpointer, &amplitude, &melody, &frameIndex, frameInterval](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    // fill output buffer
    for(unsigned int i = 0; i < nframes; i++) {

      // check if we need to set the frequency to the next note
      if(frameIndex >= frameInterval) {
        // reset frameIndex
        frameIndex = 0;
        updatePitch(&melody, synthpointer);
      } else {
        // increment frameindex
        frameIndex++;
      }

      // write sample to output
      outBuf[i] = synthpointer -> getSampleSynth() * amplitude;

      // calculate next sample
      synthpointer -> tickSynth();

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
