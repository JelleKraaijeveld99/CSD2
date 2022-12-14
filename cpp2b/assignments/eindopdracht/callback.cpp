// #include "callback.h"
// #include "oscillator.h"
// #include "sine.h"
// #include "synth.h"
// #include "fm_synth.h"



// void CustomCallback::prepare(int rate) 
// {
//     samplerate = (float) rate;
//     std::cout << "\nsamplerate: " << samplerate << "\n";
// }

// void CustomCallback::process(AudioBuffer buffer) 
// {
//   // start with the first pitch
//   // updatePitch(&melody, &ADDsynth);
//   // frameIndex = 0;
//   // const int frameInterval = 0.05 * samplerate;


//   for (int i = 0; i < buffer.numFrames; ++i) {
//       // check if we need to set the frequency to the next note
//     // if(frameIndex >= frameInterval) {
//     //   // reset frameIndex
//     //   frameIndex = 0;
//     //   updatePitch(&melody, &ADDsynth);
//     // } else {
//     //  // increment frameindex
//     //     frameIndex++;
//     //     std::cout << "\n frameIndex:" << frameIndex << std::endl;
//     //   }

//   // write sample to buffer at channel 0, amp = 0.25
//   buffer.outputChannels[0][i] = ADDsynth.getSampleSynth();
//   ADDsynth.tickSynth();
//   }
// }

// // void CustomCallback::updatePitch(Melody* melody, Synthesizer* synthesizer)
// // {
// //   float pitch = melody->getPitch();
// //    std::cout << "next pitch: " << pitch << std::endl;
// //   synthesizer->setMidiNote(pitch);
// // }
