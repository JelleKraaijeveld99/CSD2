#include "games.h"
#include "boardgame.h"


#include <string>
#include <random>
#include <iostream>

using namespace std;

int main()
{
    Boardgame Risk("risk", 4);
    Risk.set_boardgame();
    Risk.print_boardgame();

    Boardgame mensergerjeniet("Mens erger je niet", 6);
    mensergerjeniet.set_boardgame();
    mensergerjeniet.print_boardgame();
    
    return 0;

}


