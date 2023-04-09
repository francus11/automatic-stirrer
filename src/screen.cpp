#include "screen.h"

Screen::Screen(int a, int b, int c, int d, int e, int f):LiquidCrystal(a, b, c, d, e, f)
{
    begin(16, 2);
}

void Screen::displayOnScreen(String line1, String line2, int focusedLine)
{
    setCursor(0, 0);
    this->print(line1);
    setCursor(0, 1);
    this->print(line2);
    setCursor(0, 1);
}

void Screen::displayOnScreen(String line1, String line2)
{
    setCursor(0, 0);
}

void Screen::displayOnScreen(const String* line1, int focusedLine)
{
    setCursor(0, 0);

}