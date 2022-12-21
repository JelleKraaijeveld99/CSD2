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

#define WRITE_TO_FILE 1

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
  std::cout << "which synthesizer do you want? " << std::endl;
  std::string chosenSynth = UIUtilities::retrieveSelection(synthOptions, synthAmount); //ask user fm or add
  std::cout << "\nyou have chosen: " << chosenSynth << std::endl;

  if(chosenSynth =="fm") //if fm synthesizer
  {
    synthpointer = &fmsynth; //initialise synthpointer
    
    std::cout << "\nwhich waveform do you want the carrier of the FM synth to be? " << std::endl;
    Synthesizer::Waveform waveTypeCarrier = (Synthesizer::Waveform) //make variable containing enum but not declaring
      UIUtilities::retrieveSelectionIndex(oscWaveOptions, Synthesizer::Waveform::Size); //declare the variable
    synthpointer -> setOscillator(waveTypeCarrier, 0);
    synthpointer -> setOscillator(waveTypeCarrier, 2);

    std::cout << "\nwhich waveform do you want the modulator of the FM synth to be? " << std::endl;
    Synthesizer::Waveform waveTypeModulator = (Synthesizer::Waveform) //make variable containing enum but not declaring
      UIUtilities::retrieveSelectionIndex(oscWaveOptions, Synthesizer::Waveform::Size); //declare the variable
    synthpointer -> setOscillator(waveTypeModulator, 1);

    std::cout << "\nwhat do you want the modulation depth to be? " << std::endl;
    float modDepthAnwser = UIUtilities::retrieveValueInRange(1, 1000);
    std::cout << "you have given this awnser: " << modDepthAnwser << std::endl;
    synthpointer -> setModulationDepth(modDepthAnwser);

    std::cout << "\nwhat do you want the modulation frequency to be? " << std::endl;
    float modFreqAnwser = UIUtilities::retrieveValueInRange(20, 14000);
    std::cout << "you have given this awnser: " << modFreqAnwser << std::endl;
    synthpointer -> setModulationDepth(modFreqAnwser);
  } 
  
  else { // if additive
    synthpointer = &addsynth; //initialise synthpointer
    std::cout << "\nwhich waveform do you want the carrier of the additive synth to be? " << std::endl;
    Synthesizer::Waveform waveTypeCarrier = (Synthesizer::Waveform) //make variable containing enum but not declaring
      UIUtilities::retrieveSelectionIndex(oscWaveOptions, Synthesizer::Waveform::Size); //declare the variable
    synthpointer -> setOscillator(waveTypeCarrier, 0);

    std::cout << "\nwhich waveform do you want the first modulator of the additive synth to be? " << std::endl;
    Synthesizer::Waveform waveTypeModulator1 = (Synthesizer::Waveform) //make variable containing enum but not declaring
      UIUtilities::retrieveSelectionIndex(oscWaveOptions, Synthesizer::Waveform::Size); //declare the variable
    synthpointer -> setOscillator(waveTypeModulator1, 1);

    std::cout << "\nwhich waveform do you want the second modulator of the additive synth to be? " << std::endl;
    Synthesizer::Waveform waveTypeModulator2 = (Synthesizer::Waveform) //make variable containing enum but not declaring
      UIUtilities::retrieveSelectionIndex(oscWaveOptions, Synthesizer::Waveform::Size); //declare the variable
    synthpointer -> setOscillator(waveTypeModulator2, 2);
  }

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
  std::string oscWaveOptions[3] = {"sine", "square", "saw"};

  int synthAmount = 2;
  int waveAmount = 3;

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

