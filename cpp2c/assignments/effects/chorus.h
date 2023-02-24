#include "effect.h"
#include "oscillator.h"
#include "circ_buff.h"

class Chorus : public Effect
{   
    public: 
    //constructor and destructor 
    Chorus();
    ~Chorus(); 
    
    //functions
    void prepareToPlay(double sampleRate) override;
    float output (float input) override;

    //setters and getters
    void setMaxDelay(int ms);
    void setMinDelay(int ms);
    void setModDepth(int ms);

    protected:
    //variables
    int minDelay { 0 };
    int modDepth { 0 };
    int maxDelay = { 0 };
    int delayMs { 0 };
    int delaySamples { 0 };
    float feedbackAmount { 0 };

    //LFO
    Oscillator *osc;

    //Buffer 
    CircBuffer *buffer;

};