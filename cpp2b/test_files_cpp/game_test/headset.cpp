#include "headset.h"

#include <iostream> 
#include <string> 
#include <cstdlib>

using namespace std;

void Headset::print_headset()
{
    cout << "a " << identity << " has a " << microphone << " , a " << cable << " and two " << speakers << endl;
}