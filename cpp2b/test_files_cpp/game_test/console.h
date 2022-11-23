#include <iostream> 
#include <string> 
#include <cstdlib>

using namespace std;

class Console //making a class
{
public:
string disc_reader;
string storage;
string graphic_card; 
string identity = "console"; 

void declare_parts_cons();

void print_console();
};