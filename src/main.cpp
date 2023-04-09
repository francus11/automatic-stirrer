#include <Arduino.h>
#include "buttons.h"
#include "menu.h"

#include "automix.h"
#include <Wire.h>

#include "screen.h"

Screen lcd(A1, A0, 15, 14, 16, 10);
Buttons buttons(2, 5, 3, 4, 7, 6);
Motor motorA(9, 8, 128);

// menu test
int menu_items = 4;
String menuPrompts[] = {"Manual", "Automatic", "Menu 3", "Menu 4"};
Menu menu0(menuPrompts, 4, A1, A0, 15, 14, 16, 10);

// automix presets
unsigned short timeTest[2] = {10, 10};
byte speedTest[2] = {128, 255};
Automix automix(9, 8, 128, timeTest, speedTest, 2);
void setup()
{
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(2, INPUT_PULLUP);
    Serial.begin(9600);  // Ustawienie prędkości transmisji
    lcd.begin(16, 2);    // Deklaracja typu
    lcd.setCursor(0, 0); // Ustawienie kursora
    lcd.print("Speed: ");
    lcd.print(motorA.getSpeed());
    
    automix.start();

}

void loop()
{
    byte clickedButton = buttons.clickedButton();
    //do wsadzenia w menu manual
    switch (clickedButton)
    {
    case 3:
        // Serial.println("Left");
        motorA.changeSpeed(-5);
        // motorA.applyChanges();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Speed: ");
        lcd.print(motorA.getSpeed());
        break;
    case 4:
        // Serial.println("Right");
        motorA.changeSpeed(5);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Speed: ");
        lcd.print(motorA.getSpeed());
        break;
    default:
        // Serial.println("Nothing");
        break;
    }

    motorA.run();
    //do wsadzenia w menu automatic
    while(1)
    {
        automix.runAutomix();
        if (automix.showStatus() == 2) break;
    }
    menu0.displayMenu(255);
}