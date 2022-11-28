#pragma once

#include "instrument.h"

#include <iostream> 
#include <string> 
using namespace std; 

class Strings : public Instrument {
    public:

    Strings(string name_x, int pitchrange_y); //constructor

    void declare_strings();

};