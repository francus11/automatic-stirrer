#include "automix.h"
Automix::Automix(byte enablePin, byte phasePin, unsigned short pwmFreq, unsigned short* time, byte* speed, unsigned short arraySize):Motor(enablePin, phasePin, pwmFreq)
{
    iteration = 0;
    runStatus = 255;
    this->arraySize = arraySize;
    this->time = new unsigned short[arraySize];
    this->speed = new byte[arraySize];
    for (int i = 0; i < this->arraySize; i++)
    {
        Automix::time[i] = time[i];
        Automix::speed[i] = speed[i];
    }
}

void Automix::runAutomix()
{
    if(runStatus == 0)
    {
        run();
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
    runStatus = 0;
}
void Automix::pause()
{
    if (runStatus != 1)
    {
        runStatus = 1;
        timeOfPause = millis();
    }
}
void Automix::resume()
{
    if (runStatus != 0)
    {
        runStatus = 0;
        timeOfIteration += millis() - timeOfPause;
    }
}
void Automix::stop()
{
    runStatus = 2;
}
byte Automix::showStatus()
{
    return runStatus;
}
void Automix::setParametersOfCurrentIterations()
{
    timeOfIteration = millis() + (1000 * time[iteration]);
    setSpeed(speed[iteration]);
}