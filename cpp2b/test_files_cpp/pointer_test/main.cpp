#include <iostream>
#include "synth.h"
#include <string>
using namespace std;


int main()
{


// synth.setSynthType("fm");
Synth synth1;
Synth synth2;

Synth *synthpointer = &synth2; //make a pointer that points at the adress of a synth object

synthpointer -> setSynthType("fm");

synth2.getSynthType();

return 0;
}