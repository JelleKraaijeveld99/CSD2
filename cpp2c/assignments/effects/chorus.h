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

    void calculateDelayLine();
    void calculateDelayCenter(); 

    protected:
    //variables
    float minDelay { 1 };
    float modDepth { 0 };
    float maxDelay { 0 };
    float delayCenterMs { 0 };
    float delayCenterSamples { 0 };
    
    float delayMs { 0 };
    float delaySamples { 0 };
    float feedbackAmount { 0 };

    float modulatedDelayLine { 0 };

    //LFO
    Oscillator *osc;

    //Buffer 
    CircBuffer *buffer;

};