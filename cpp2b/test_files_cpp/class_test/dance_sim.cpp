#include <iostream> 
#include <string> 
#include <list> 
#include  <cstdlib>
using namespace std;

class dance
{
public: 
  
  string move;
  string dancestyle;
  string musicgenre;

  string ingredients[11] = {"step to the left", "step to the right", "hands up", "hands down", "right hand up", "right hand down", "shuffle", "left hand up", "left hand down", "moonwalk", "floss"};

  int random_val;

void move_selector()
{
random_val = rand() % 11;
move = ingredients[random_val];
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

void genre_style_printer()
{
  cout << "This is the genre: " << musicgenre << endl << "This is the dancestyle: " << dancestyle << endl; 
}
};

int main()
{
dance my_dance;
my_dance.dancestyle_selector();
my_dance.musicgenre_selector();
my_dance.genre_style_printer();
for(int i = 0; i < 6; i++)
  {
    my_dance.move_selector();
    my_dance.dance_printer();
  }
}