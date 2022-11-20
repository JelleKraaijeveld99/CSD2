#include <iostream> 
#include <string> 
#include <list> 
#include <cstdlib>

using namespace std;

class instrument //class
{
public:
string sound; //atribute

instrument(string x){ //constructor 
    sound = x; 
}

void print_sound(){ //function for printing the sound 
    cout << sound << endl; 
}

};

int main()
{
    instrument instrument1("plingplong"); //make objects and give them a sound
    instrument instrument2("skyaaaa"); 

    instrument1.print_sound(); //use the function in the instrument class to print the sounds of the objects 
    instrument2.print_sound();

    return 0;

}