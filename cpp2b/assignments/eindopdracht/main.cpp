#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "melody.h"
#include "synth.h"
#include "addSynth.h"
#include "fm_synth.h"
#include "uiUtilities.h"
#include <iostream>

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

void write(){
         
   
    WriteToFile fileWriter("output.csv", true);

      for(int i = 0; i < 5000; i++) {
        fileWriter.write(std::to_string(synthpointer -> getSampleSynth()) + "\n");
          synthpointer -> tickSynth();
           }

        std::cout << "\nWROTE TO FILE = DONE." << std::endl;
       

}

void updatePitch(Melody* melody, Synthesizer* fmsynth) {
  float pitch = melody->getPitch();
  // std::cout << "next pitch: " << pitch << std::endl;
  fmsynth->setMidiNote(pitch);
}


void prepare (double sampleRate) override {
  this->sampleRate=sampleRate;

  //section for UI
  std::string value = UIUtilities::retrieveSelection(synthOptions, synthAmount);
  playing = true;
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
	      
      if (playing == true)
      {
	        for (int sample = 0; sample < numFrames; ++sample) {
		        outputChannels[0][sample] = synthpointer -> getSampleSynth() * amplitude;
            outputChannels[1][sample] = synthpointer -> getSampleSynth() * amplitude;
		        synthpointer -> tickSynth(); // rather mixed up functionality
	    frameIndex++;
      if(frameIndex >= noteDelayFactor * sampleRate) {
	      // reset frameIndex
	      frameIndex = 0;
	      updatePitch(&melody, synthpointer);
	    }
	  
	      
	    }// for sample
	  } //if playing
	}  // process()


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

  bool playing = false; //bool so i have control over when the synth is playing

  //lists for input options:
  std::string synthOptions[2] = {"fm", "add"};
  int synthAmount = 2;

  /* instead of using bpm and specifying note lenghts we'll make every note
   * equal length and specify the delay between notes in term of the
   * samplerate
   *
   * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be
   * played
   */
  double noteDelayFactor= 0.5 ;
}; // Callback{}



int main(int argc,char **argv)
{  
  auto callback = Callback{};
  auto jack_module = JackModule(callback);

  jack_module.init(1,2);

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
 
  #if WRITE_TO_FILE 
  callback.write();
  #endif
  return 0;

} // main()

