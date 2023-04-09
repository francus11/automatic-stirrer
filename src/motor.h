#include <Arduino.h>
#define SOFTWARE_PWM
#define USEDELAY
#ifndef SOFTWARE_PWM
class Motor
{
    private:
    byte enablePin;
    byte phasePin;
    byte phaseValue;
    byte enableValue;
    public:
    byte getSpeed();
    void setSpeed(byte speed);
    void changeSpeed(short speed);
    void setDirection(byte direction);
    void applyChanges();
    Motor(byte enablePin, byte phasePin);
};
#endif
#ifdef SOFTWARE_PWM
class Motor
{
    private:
    byte enablePin;
    byte phasePin;
    byte phaseValue;
    byte enableValue;
    float pwmOnTime;
    float pwmOffTime;
    float pwmFreq;
    unsigned long long timeOn;
    unsigned long long timeOff;
    
    public:
    byte getSpeed();
    void setSpeed(byte speed);
    void changeSpeed(short speed);
    void setDirection(byte direction);
    void applyChanges();
    void run();
    float test();
    Motor(byte enablePin, byte phasePin, unsigned short pwmFreq);
};
#endif