/*
-------------------------------------------------------
Author      : Raghav Thakur
Course      : IIT Jammu Summer School 2026
Module      : Module 3
Question    : Q28
Description : Keypad + LCD Password System
-------------------------------------------------------
*/

#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {A4, A5, 2, 3};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int greenLED = 4;
const int redLED = 5;
const int buzzer = 6;

String correctPIN = "1234";
String enteredPIN = "";

int attempts = 0;

void setup() {

  lcd.begin(16,2);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.print("ENTER PIN:");
}

void loop() {

  char key = keypad.getKey();

  if(key){

    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);

    enteredPIN += key;

    lcd.print(enteredPIN);

    if(enteredPIN.length()==4){

      if(enteredPIN==correctPIN){

        lcd.clear();
        lcd.print("ACCESS GRANTED");

        digitalWrite(greenLED,HIGH);

        delay(3000);

        digitalWrite(greenLED,LOW);

        attempts=0;

      }

      else{

        lcd.clear();
        lcd.print("ACCESS DENIED");

        digitalWrite(redLED,HIGH);

        tone(buzzer,1000,500);

        delay(3000);

        digitalWrite(redLED,LOW);

        attempts++;

        if(attempts>=3){

          lcd.clear();
          lcd.print("LOCKED 10 SEC");

          delay(10000);

          attempts=0;

        }

      }

      enteredPIN="";

      lcd.clear();

      lcd.print("ENTER PIN:");

    }

  }

}
