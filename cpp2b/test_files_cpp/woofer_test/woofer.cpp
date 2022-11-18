#include <iostream>
#include  <cstdlib>

class Woofer
{
public:
  float magnet;
  float coil;
  float random_val;

  void move_coil(float float_pos)
  {
    random_val = rand()%5;
    coil = float_pos * random_val;
  }

  void print_coil_position()
  {
    std::cout << "Coil position: " << coil << std::endl;
  }

  void magnet_strength(int pull_strength)
  {
    magnet = pull_strength;
  }

  void print_magnet()
  {
    std::cout << "Magnet strength: " << magnet << std::endl; 
  }

};


int main()
{
  Woofer myWoofer;
  
  for(int i = 0; i < 10; i++)
  {
      myWoofer.move_coil(0.4);
      myWoofer.print_coil_position();
  }

  myWoofer.magnet_strength(1);
  myWoofer.print_magnet();

  return 0;
}

