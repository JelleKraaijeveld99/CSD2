#include <iostream> 
#include <string> 
#include <cstdlib>

#include "instr_class.h"

using namespace std;

instrument::instrument(string x) //declare the constructor 
{
    sound = x; 
}


void instrument::print_sound() //declare the function for printing the sound
{
    cout << sound << endl; 
}
