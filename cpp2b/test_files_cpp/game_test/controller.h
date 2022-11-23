#include <iostream> 
#include <string> 
#include <cstdlib>

using namespace std;

class Controller //class
{
public:
string buttons; //attributes
string stick;
string battery; 
string identity;

Controller(string x);// constructor 

void declare_parts_ctrl(); //function for assigning parts

void print_controller(); //function for printing "controller has a:" 
};