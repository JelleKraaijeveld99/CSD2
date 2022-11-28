#include "strings.h"
#include "instrument.h"

#include <iostream> 
#include <string> 
using namespace std; 

Strings::Strings(string name_x, int pitchrange_y) //declare the constructor of strings
{
    Instrument::name = name_x;
    Instrument::pitchrange = pitchrange_y;
}

void Strings::declare_strings()
{
    Instrument::type = "strings";
    Instrument::sound = "skrrrrreeeech";
}