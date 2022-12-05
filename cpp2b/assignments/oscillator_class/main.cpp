#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "oscillator.h"
#include "writeToFile.h"

#include "square.h"
#include "saw.h"

#define audioOutput 1 // macro for giving audio 
#define writeOutput 0 // macro for giving write output

#define SAMPLERATE 44100

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudi
 */



class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override { //give the samplerate to the JACK module 
    samplerate = (float) rate; //set the samplerate of the sine and the samplerate that is send to JACK module the sae
    square.setSamplerate(samplerate); //set the samplerate of the saw
    std::cout << "\nsamplerate: " << samplerate << "\n"; //print the samplerate 
  }

  void process(AudioBuffer buffer) override { //send the audiodata to JACK -- sample for sample with sine.getSample and sine.tick to go to the next sample 
    for (int i = 0; i < buffer.numFrames; ++i) {
      // write sample to buffer at channel 0, amp = 0.25
      buffer.outputChannels[0][i] = square.getSample(); 
      square.tick(); //go to the next sample 
    }
  }
  private:

  float samplerate = SAMPLERATE; //set the samplerate 
  Square square = Square(440, samplerate); //make the saw here 

};


int main(int argc,char **argv)
{

  auto callback = CustomCallback {};
  auto jackModule = JackModule { callback };

if(audioOutput){
  jackModule.init (0, 1);
}

if(writeOutput) //section for writing the sample to python code 
{ 
  WriteToFile fileWriter("output.csv", true);
  
  Square square(220, SAMPLERATE); //making the oscillator 
  std::cout << "Saw frequency: " << square.getFrequency() << "\n";
  
  for(int i = 0; i < SAMPLERATE; i++) {
    fileWriter.write(std::to_string(square.getSample()) + "\n");
    square.tick();
  }
}

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


//saw
//sample = (2*amplitude*phase)-amplitude;

