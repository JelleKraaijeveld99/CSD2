

#include <iostream>
#include <string>
#include <random>
using namespace std;

#include "games.h"

Games::Games(string name_x, int pl_amount){
    
    name = name_x;
    player_amount = pl_amount;
    player_won = rand() % pl_amount;
}

void Games::print_playing()
{
    cout << "Hi, you are playing " << name << " with " << player_amount << " players" << endl;
}