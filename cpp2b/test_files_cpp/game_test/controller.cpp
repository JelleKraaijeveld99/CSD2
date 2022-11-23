#include <iostream> 
#include <string> 
#include <cstdlib>

#include "controller.h"
using namespace std;

Controller::Controller(string x) // declaring constructor 
{
    identity = x;
}

void Controller::declare_parts_ctrl()
{
    stick = "stick";
    buttons = "buttons";
    battery = "battery"; 
}

void Controller::print_controller()
{
    cout << "a " << identity << " has " << buttons << ", a " << stick << " and a " << battery << endl; 
}


