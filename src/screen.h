#ifndef screen_h
#define screen_h
#include <Arduino.h>
#include <LiquidCrystal.h>

class Screen : LiquidCrystal
{
    public:

    Screen(int a, int b, int c, int d, int e, int f);

    void displayOnScreen(String line1, String line2, int focusedLine);
    void displayOnScreen(String line1, String line2);
    void displayOnScreen(const String* line1, int focusedLine);

};
#endif