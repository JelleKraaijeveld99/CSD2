#include <iostream> 
#include <string> 
#include <list> 
using namespace std;

class dance
{
public: 
  
  string move;
  string dancestyle;
  string musicgenre;
  

void move_selector()
{
move = "step to the left";
}

void dancestyle_selector()
{
dancestyle = "salsa";
}

void musicgenre_selector()
{
musicgenre = "techno";
}

void dance_printer()
{
cout << "This is the dance move: " << move << endl; 
}
};

int main()
{
dance my_dance;
my_dance.move_selector();
my_dance.dance_printer(); 
}