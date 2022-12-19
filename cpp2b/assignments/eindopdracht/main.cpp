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
 * NOTE: the development library with headers for jack2 needs to be installed to build this program.
 * 
 * When built, before running the program start jackd, the JACK audio server daemon.
 *
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 *
 * start jackd : jackd -d <backend>
 * where backend is e.g. coreaudio (MacOS) or alsa (Linux)
 *
 * Alternatively there are graphical clients that start jackd.
 */

#define WRITE_TO_FILE 0


class Callback : public AudioCallback
{

public:

void updatePitch(Melody* melody, Synthesizer* fmsynth) {
  float pitch = melody->getPitch();
  std::cout << "next pitch: " << pitch << std::endl;
  fmsynth->setMidiNote(pitch);
}


void prepare (double sampleRate) override {
  this->sampleRate=sampleRate;
  updatePitch(&melody, synthpointer);
} // prepare()


    /*
     * process() gets called by the JACK engine.
     *
     * If you are interested in incoming audio, use inputChannels[channel][sample]
     * For sending audio to the output(s), use outputChannels[channel][sample]
     */
    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
	for (int channel = 0; channel < numOutputChannels; ++channel) {
	    for (int sample = 0; sample < numFrames; ++sample) {
		outputChannels[channel][sample] = synthpointer -> getSampleSynth() * amplitude;
		synthpointer -> tickSynth(); // rather mixed up functionality

	    /* After every sample, check if we need to advance to the next note
	     * This is a bit awkward in this scheme of buffers per channel
	     *  In a multichannel setting we should update pitches independently per channel!
	     */
	    if(frameIndex >= noteDelayFactor * sampleRate) {
	      // reset frameIndex
	      frameIndex = 0;
	      updatePitch(&melody, synthpointer);
	    }
	    else {
	      // increment frameindex
	      frameIndex++;
	    }
	  } // for sample
	} // for channel
    } // process()

protected:
  double sampleRate;
  //make the synth objects
  FmSynth fmsynth{60};
  AddSynth addsynth{60};
  //make a pointer for the synths
  Synthesizer *synthpointer = &fmsynth;

  float amplitude = 0.025;
  Melody melody;
  int frameIndex = 0;

  /* instead of using bpm and specifying note lenghts we'll make every note
   * equal length and specify the delay between notes in term of the
   * samplerate
   *
   * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be
   * played
   */
  double noteDelayFactor=0.5;
}; // Callback{}



int main(int argc,char **argv)
{
  auto callback = Callback{};
  auto jack_module = JackModule(callback);

    #if WRITE_TO_FILE
    WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 5000; i++) {
    fileWriter.write(std::to_string(fmsynth.getSampleSynth()) + "\n");
    fmsynth.tickSynth();
  }
  std::cout << "\nWROTE TO FILE = DONE." << std::endl;
  #else
  

  jack_module.init(1,1);

  std::cout << "\n\nType 'quit' to exit\n";
  bool running = true;
  while (running) {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        break;
    }
  } // while
#endif
  return 0;

} // main()

