#include <Arduino.h>
#include "motor.h"
class Automix:Motor
{
    private:
    unsigned short* time;
    byte* speed;
    unsigned short arraySize;

    unsigned short iteration;
    unsigned long long timeOfIteration;
    unsigned long long timeOfPause;
    byte runStatus; //0-run, 1-pause, 255 - init

    void setParametersOfCurrentIterations();
    
    public:
    void runAutomix();
    void start();
    void pause();
    void resume();
    void stop();
    byte showStatus();
    Automix(byte enablePin, byte phasePin, unsigned short pwmFreq, unsigned short* time, byte* speed, unsigned short arraySize);
};