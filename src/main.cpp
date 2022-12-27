

#include <Arduino.h>
#include "buttons.h"
#include "menu.h"
#include "motor.h"
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(A1, A0, 15, 14, 16, 10);
Buttons buttons(2, 5, 3, 4, 7, 6);
Motor motorA(9, 8, 128);
int menu_items = 4;
String menuPrompts[] = {"Menu 1", "Menu 2", "Menu 3", "Menu 4"};
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600); //Ustawienie prędkości transmisji
  lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print("Speed: ");
  lcd.print(motorA.getSpeed());
}
bool stillPushed = 0;
  unsigned long long lastPushed;
void loop()
{
  //display test
  
  
  byte clickedButton = buttons.clickedButton();
  switch (clickedButton)
  {
    /* case 1:
      Serial.println("Up");
      break;
    case 2:
      Serial.println("Down");
      break; */
    case 3:
      //Serial.println("Left");
      if (stillPushed == 0)
      {
        motorA.changeSpeed(-5);
        //motorA.applyChanges();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Speed: ");
        lcd.print(motorA.getSpeed());
        stillPushed = 1;
        lastPushed = millis() + 20;
      }
      break;
    case 4:
      //Serial.println("Right");
      if (stillPushed == 0)
      {
        motorA.changeSpeed(5);
        //motorA.applyChanges();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Speed: ");
        lcd.print(motorA.getSpeed());
        stillPushed = 1;
        lastPushed = millis() + 20;
      }
      break;
    /* case 5:
      Serial.println("Start");
      break;
    case 6:
      Serial.println("Back");
      break; */
    default:
      //Serial.println("Nothing");
      if (millis() >= lastPushed) stillPushed = 0;
      break;  
  }
  
motorA.run();
//Serial.println(motorA.test());
}