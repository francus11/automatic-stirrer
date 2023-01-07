#include "automix.h"
Automix::Automix(Motor* motor, unsigned short* time, byte* speed, unsigned short arraySize)
{
    iteration = 0;
}

void Automix::run()
{
    if(runStatus == 0)
    {
        motor->run();
        if (millis() >= timeOfIteration)
        {
            iteration++;
            if (iteration >= arraySize)
            {
                stop();
            }
            else
            {
                setParametersOfCurrentIterations();
            }
        }
    }
    else if(runStatus == 1) return;
}

void Automix::start()
{
    setParametersOfCurrentIterations();
}
void Automix::pause()
{
    runStatus = 1;
}
void Automix::stop()
{
    pause();
    //~Automix();
}

void Automix::setParametersOfCurrentIterations()
{
    timeOfIteration = millis() + (1000 * time[iteration]);
    motor->setSpeed(speed[iteration]);
}