#include <Arduino.h>
class Menu
{
    private:
    unsigned short menuIterations;
    String* menuText;
    unsigned short chosenOption;
    //here is place for an array of functions assigned to the menu options
    public:
    Menu();
    void select(byte signal);
    void displayMenu(String line0, String line1 );
};