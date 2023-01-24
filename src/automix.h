#include <Arduino.h>
#include "motor.h"
class Automix
{
    private:
    unsigned short* time;
    byte* speed;
    unsigned short arraySize;

    unsigned short iteration;
    unsigned long long timeOfIteration;
    unsigned long long timeOfPause;
    byte runStatus; //0-run, 1-pause, 255 - init

    Motor* motor;

    void setParametersOfCurrentIterations();
    
    public:
    void run();
    void start();
    void pause();
    void resume();
    void stop();
    Automix(Motor* motor, unsigned short* time, byte* speed, unsigned short arraySize);
    ~Automix();
};