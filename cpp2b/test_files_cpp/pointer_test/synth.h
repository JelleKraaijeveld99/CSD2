#include <iostream>
#include <string>
using namespace std;

class Synth
{
    public:
    Synth(); //constructor
    ~Synth(); //deconstructor

    void setSynthType(string type); //function for setting the synth type
    void getSynthType();

    protected:
    string synthType; //variable for the type of the synth
};