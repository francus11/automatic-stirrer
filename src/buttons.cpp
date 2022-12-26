#include "buttons.h"

Buttons::Buttons(byte up, byte down, byte left, byte right, byte start, byte back) : up(up), down(down), left(left), right(right), start(start), back(back)
{
    pinMode(up, INPUT_PULLUP);
    pinMode(down, INPUT_PULLUP);
    pinMode(left, INPUT_PULLUP);
    pinMode(right, INPUT_PULLUP);
    pinMode(start, INPUT_PULLUP);
    pinMode(back, INPUT_PULLUP);
}
byte Buttons::clickedButton()
{
    if (!digitalRead(up)) return 1;
    if (!digitalRead(down)) return 2;
    if (!digitalRead(left)) return 3;
    if (!digitalRead(right)) return 4;
    if (!digitalRead(start)) return 5;
    if (!digitalRead(back)) return 6;
    return 0;
}   