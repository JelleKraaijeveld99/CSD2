#pragma once

#include "instrument.h"

#include <iostream> 
#include <string> 
using namespace std; 

class Keys : public Instrument {
    public:

    Keys(string name_x, int pitchrange_y); //constructor

    void declare_keys();

};