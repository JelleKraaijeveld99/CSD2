#pragma once

#include "instrument.h"

#include <iostream> 
#include <string> 
using namespace std; 

class Woodwinds : public Instrument {
    public:

    Woodwinds(string name_x, int pitchrange_y); //constructor

    void declare_woodwinds(); // function to declare the instrument.h variables 

};