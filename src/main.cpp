#include <Arduino.h>
#include "buttons.h"
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(A1, A0, 15, 14, 16, 10);
Buttons buttons(2, 5, 3, 4, 7, 6);
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600); //Ustawienie prędkości transmisji
  lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print("Kurs Arduino");
}

void loop()
{
  //display test
  lcd

  //byte clickedButton = buttons.clickedButton();
  /* switch (clickedButton)
  {
    case 1:
      Serial.println("Up");
      break;
    case 2:
      Serial.println("Down");
      break;
    case 3:
      Serial.println("Left");
      break;
    case 4:
      Serial.println("Right");
      break;
    case 5:
      Serial.println("Start");
      break;
    case 6:
      Serial.println("Back");
      break;
    default:
      Serial.println("Nothing");
      break;
  } */
  
  //delay(500);
}