#include <iostream>
#include <string>
#include "synth.h"
using namespace std;

Synth::Synth()
{ 
    cout << "this is the constructor of Synth class" << endl;
}

Synth::~Synth()
{
    cout << "this is the deconstructor of Synth class" << endl;
}

void Synth::setSynthType(string type)
{
    synthType = type;
    cout << "this is the setted type of the synth: " << type << endl;
}

void Synth::getSynthType()
{
    cout << "this is the type of synth i got: " << synthType << endl;
}

