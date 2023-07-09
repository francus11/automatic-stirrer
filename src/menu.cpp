#include "menu.h"

Menu::Menu(String* array, unsigned short arraySize, int lcda, int lcdb, int lcdc, int lcdd, int lcde, int lcdf):LiquidCrystal(lcda, lcdb, lcdc, lcdd, lcde, lcdf)
{
    menuText = new String[arraySize];
    menuTextElements = arraySize;
    for (int i = 0; i < menuTextElements; i++)
    {
        menuText[i] = array[i];
    }
    chosenOption = 0;
    begin(16, 2);
}
void Menu::select(byte signal)
{
    if(signal == 1)
    {
        if (chosenOption != 0) chosenOption--;
        else chosenOption = menuTextElements - 1;
    }
    else if(signal == 2)
    {
        if (chosenOption != menuTextElements - 1) chosenOption++;
        else chosenOption = 0;
    }
}
void Menu::displayText()
{
    clear();
    setCursor(0, 0);
    print(menuText[chosenOption / 2 * 2]);
    if(chosenOption % 2 == 0) print("<");
    
    if(chosenOption + 1 != menuTextElements)
    {
        setCursor(0, 1);
        print(menuText[(chosenOption / 2 * 2) + 1]);
        if(chosenOption % 2 == 1) print("<");
    }
    else
    {
        if(menuTextElements % 2 == 0)
        {
            setCursor(0, 1);
            print(menuText[(chosenOption / 2 * 2) + 1]);
            if(chosenOption % 2 == 1) print("<");
        }
    }
}
void Menu::displayMenu(byte signal)
{
    if (signal != 0)
    {
        select(signal);
        displayText();
    }
}
byte Menu::getChosenOption()
{
    return chosenOption;
}