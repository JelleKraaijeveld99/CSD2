#include "instrument.h"
#include "keys.h"
#include "strings.h"
#include "woodwind.h"

#include <iostream> 
#include <string> 
using namespace std; 

int main()
{
    Keys piano("piano", 6);
    piano.declare_keys();
    piano.instrument_play();

    Strings viool("viool", 3);
    viool.declare_strings();
    viool.instrument_play();

    Woodwinds fluit("fluit", 3);
    fluit.declare_woodwinds();
    fluit.instrument_play();

return 0;
}