#pragma once
#include <iostream>
#include <string>

using namespace std;

class Games //this is the parent class
{   
    public:
    
    string name;
    int player_amount;
    int player_won; 

    Games(string name_x, int pl_amount); //var constructor 
    
    void print_playing(); //first print function, what game are we playing? 

};