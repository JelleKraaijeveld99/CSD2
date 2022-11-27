#include "keys.h"
#include "instrument.h"

#include <iostream> 
#include <string> 
using namespace std; 

Keys::Keys(string name_x, int pitchrange_y) //declare the constructor of keys 
{
    Instrument::name = name_x;
    Instrument::pitchrange = pitchrange_y;
}

void Keys::declare_keys()
{
    Instrument::type = "keys";
    Instrument::sound = "ping pong pong ping peeeeng";
}