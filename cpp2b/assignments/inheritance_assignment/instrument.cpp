#include "instrument.h"

#include <iostream> 
#include <string> 
using namespace std; 

Instrument::Instrument(){

}

void Instrument::instrument_play(){
    cout << "A " << name << " of the type " << type << " with a pitch range of: " << pitchrange << " octaves is playing: " << sound << endl;
}