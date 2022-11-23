#include <iostream> 
#include <string> 
#include <cstdlib>

#include "instr_class.h"

using namespace std;

int main()
{
    instrument instrument1("plingplong"); //make objects and give them a sound
    instrument instrument2("skyaaa"); 
    instrument instrument3("plaaaah");

    instrument1.print_sound(); //use the function in the instrument class to print the sounds of the objects 
    instrument2.print_sound();
    instrument3.print_sound();

    return 0;

}