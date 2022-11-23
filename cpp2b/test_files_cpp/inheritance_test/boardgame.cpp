#include <iostream>
#include <string>
#include "boardgame.h"
#include "games.h"

using namespace std;

Boardgame::Boardgame(string name_x, int pl_amount) : Games(name_x, pl_amount)
{
}

void Boardgame::print_boardgame()
{
 cout << "You'll need a " << board << " and " << dices << " to play " << name << " with " << player_amount << " players. " << endl;
}

void Boardgame::set_boardgame()
{
    board = "board";
    dices = "dices";
}

