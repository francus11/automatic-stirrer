#ifndef buttons_h
#define buttons_h
#include <Arduino.h>
class Buttons 
{
    private:
    byte up;
    byte down;
    byte left;
    byte right;
    byte start;
    byte back;
    bool isPressed;
    unsigned long long timeOfClick;
    unsigned long long timeOfPress;
    byte clickedButtonResponce(byte returnValue);
    public:
    Buttons(byte up, byte down, byte left, byte right, byte start, byte back);
    byte clickedButton();
};
#endif