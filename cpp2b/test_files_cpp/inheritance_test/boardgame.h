#pragma once

#include <iostream>
#include <string>
#include "games.h"

using namespace std;

class Boardgame : Games // use "Games" as parent class
{   
    public:
    string board; //attributes for the boardgame class
    string dices;

    Boardgame(string name_x, int pl_amount); //variable constructor

    void print_boardgame(); //function for printing the boardgame 

    void set_boardgame(); //function for declaring the attributes 

};