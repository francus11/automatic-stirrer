#include "menu.h"
#include <string.h>

void Menu::select(byte signal)
{
    if (signal == 0) return;
    if (signal == 1)
    {
        if (chosenOption - 1 < 0) return;
        else chosenOption--;
    }
    if (signal == 1)
    {
        if (chosenOption + 1 == menuIterations) return;
        else chosenOption++;
    }
}