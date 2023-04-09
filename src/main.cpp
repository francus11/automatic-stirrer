

#include <Arduino.h>
#include "buttons.h"
#include "menu.h"
#include "motor.h"
#include <Wire.h>

#include "screen.h"

Screen lcd(A1, A0, 15, 14, 16, 10);
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
      motorA.changeSpeed(-5);
      //motorA.applyChanges();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Speed: ");
      lcd.print(motorA.getSpeed());
      break;
    case 4:
      //Serial.println("Right");
      motorA.changeSpeed(5);
      //motorA.applyChanges();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Speed: ");
      lcd.print(motorA.getSpeed());
      break;
    /* case 5:
      Serial.println("Start");
      break;
    case 6:
      Serial.println("Back");
      break; */
    default:
      //Serial.println("Nothing");
      break;  
  }
  
motorA.run();
//Serial.println(motorA.test());
}