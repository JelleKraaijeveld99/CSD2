#include "woodwind.h"
#include "instrument.h"

#include <iostream> 
#include <string> 
using namespace std; 

Woodwinds::Woodwinds(string name_x, int pitchrange_y) //declare the constructor of woodwinds
{
    Instrument::name = name_x;
    Instrument::pitchrange = pitchrange_y;
}

void Woodwinds::declare_woodwinds()
{
    Instrument::type = "woodwinds";
    Instrument::sound = "flooeeeeeeeh";
}