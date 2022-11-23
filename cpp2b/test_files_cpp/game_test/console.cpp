#include "console.h"

#include <iostream> 
#include <string> 
#include <cstdlib>

using namespace std;

void Console::declare_parts_cons()
{
    disc_reader = "disc reader";
    storage = "storage";
    graphic_card = "grapic card";
}

void Console::print_console()
{
cout << "a " << identity << " has a " << disc_reader << " , a " << graphic_card << " and also some " << storage << endl;
}
