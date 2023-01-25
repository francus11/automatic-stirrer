#include <Arduino.h>
#include <string.h>
#include <LiquidCrystal.h>
/*class needs cursor position value to draw arrow*/
class Menu:LiquidCrystal
{
    private:
    unsigned short menuTextElements;
    String* menuText;
    unsigned short chosenOption;
    //here is place for an array of functions assigned to the menu options
    void displayText();
    public:
    Menu(String* menuTexts, unsigned short arraySize, int lcda, int lcdb, int lcdc, int lcdd, int lcde, int lcdf);
    void select(byte signal);
    void displayMenu(byte signal);
    byte getChosenOption();
};