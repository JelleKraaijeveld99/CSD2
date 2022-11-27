#pragma once 
#include <iostream> 
#include <string> 
using namespace std; 


class Instrument {
    
    public:
    string sound; //every instrument has a sound, type, name and pitchrange, those will be declared in the subclasses 
    string type;
    string name;
    int pitchrange;

    Instrument(); //constructor 
    
    void instrument_play(); //function for playing the instrument that is made

};