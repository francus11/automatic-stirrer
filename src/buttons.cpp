#include "buttons.h"

Buttons::Buttons(byte up, byte down, byte left, byte right, byte start, byte back) : up(up), down(down), left(left), right(right), start(start), back(back)
{
    pinMode(up, INPUT_PULLUP);
    pinMode(down, INPUT_PULLUP);
    pinMode(left, INPUT_PULLUP);
    pinMode(right, INPUT_PULLUP);
    pinMode(start, INPUT_PULLUP);
    pinMode(back, INPUT_PULLUP);
    isPressed = 0;
}

byte Buttons::clickedButton()
{
    if (!digitalRead(up)) return clickedButtonResponce(1);
    if (!digitalRead(down)) return clickedButtonResponce(2);
    if (!digitalRead(left)) return clickedButtonResponce(3);
    if (!digitalRead(right)) return clickedButtonResponce(4);
    if (!digitalRead(start)) return clickedButtonResponce(5);
    if (!digitalRead(back)) return clickedButtonResponce(6);
    isPressed = 0;
    return 0;
    /* if (!digitalRead(up)) return 1;
    if (!digitalRead(down)) return 2;
    if (!digitalRead(left)) return 3;
    if (!digitalRead(right)) return 4;
    if (!digitalRead(start)) return 5;
    if (!digitalRead(back)) return 6;
    return 0; */
}
//checks if button is clicked or long pressed
byte Buttons::clickedButtonResponce (byte returnValue)
{
    if (!isPressed)
    {
        isPressed = 1;
        timeOfClick = millis() + 500;
        return returnValue;
    }
    else if (isPressed)
    {
        timeOfPress = millis() + 50;
        return returnValue;
    }
    else
    {
        isPressed = 0;
        return 0;
    }
}
