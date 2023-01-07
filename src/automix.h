#include <Arduino.h>
#include "motor.h"
class Automix
{
    private:
    unsigned short* time;
    byte* speed;
    unsigned short iteration;
    unsigned short arraySize;
    unsigned long long timeOfIteration;
    byte runStatus; //0-run, 1-pause
    Motor* motor;
    void setParametersOfCurrentIterations();
    public:
    void run();
    void start();
    void pause();
    void stop();
    Automix(Motor* motor, unsigned short* time, byte* speed, unsigned short arraySize);
    ~Automix();
};