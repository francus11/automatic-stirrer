#include "motor.h"

#ifndef SOFTWARE_PWM
Motor::Motor(byte enablePin, byte phasePin): enablePin(enablePin), phasePin(phasePin), phaseValue(255), enableValue(0)
{

};
void Motor::setSpeed(byte speed)
{
    enableValue = speed;
}
void Motor::changeSpeed(short speed)
{
    if (speed + enableValue > 255) setSpeed(255);
    else if (speed + enableValue < 0) setSpeed(0);
    else setSpeed(speed + enableValue);
}
void Motor::applyChanges()
{
    analogWrite(enablePin, enableValue);
    analogWrite(phasePin, phaseValue);
}
byte Motor::getSpeed()
{
    return enableValue;
}
#endif
#ifdef SOFTWARE_PWM
Motor::Motor(byte enablePin, byte phasePin, unsigned short pwmFreq): enablePin(enablePin), phasePin(phasePin), phaseValue(255), pwmFreq(1000.0 / pwmFreq)
{
    setSpeed(0);
    analogWrite(phasePin, phaseValue);
    timeOn = millis();
    timeOff = millis();
};
void Motor::setSpeed(byte speed)
{
    enableValue = speed;
    pwmOnTime = (speed/255.0) * pwmFreq;
    pwmOffTime = (1 - (speed/255.0)) * pwmFreq;
}
void Motor::changeSpeed(short speed)
{
    if (speed + enableValue > 255) setSpeed(255);
    else if (speed + enableValue < 0) setSpeed(0);
    else setSpeed(speed + enableValue);
}
void Motor::applyChanges()
{
    analogWrite(enablePin, enableValue);
    analogWrite(phasePin, phaseValue);
}
byte Motor::getSpeed()
{
    return enableValue;
}
void Motor::run()
{
    if (enableValue != 0)
    {
        #ifndef USEDELAY
        if (millis() >= timeOff)
        {
            digitalWrite(enablePin, 1);
            timeOn = millis() + pwmOnTime;
            timeOff = millis() + pwmFreq;
        }
        if (millis() >= timeOn)
        {
            digitalWrite(enablePin, 0);
        }
        //delay(pwmOffTime);
        #endif
        #ifdef USEDELAY
            digitalWrite(enablePin, 1);
            delay(pwmOnTime);
            digitalWrite(enablePin, 0);
            delay(pwmOffTime);
        #endif
    }
}
float Motor::test()
{
    return pwmOnTime;
}
#endif