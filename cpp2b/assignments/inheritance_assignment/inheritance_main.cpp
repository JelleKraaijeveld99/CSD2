#include "instrument.h"
#include "keys.h"

#include <iostream> 
#include <string> 
using namespace std; 

int main()
{
    Keys piano("piano", 330);
    piano.declare_keys();
    piano.instrument_play();
    return 0;
}