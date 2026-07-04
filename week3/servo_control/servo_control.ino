/*
-------------------------------------------------------
Author      : Raghav Thakur
Course      : IIT Jammu Summer School 2026
Module      : Module 3
Question    : Q25
Description : Servo Control using Potentiometer
-------------------------------------------------------
*/

#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int buttonPin = 2;
const int servoPin = 9;

bool lastButtonState = HIGH;

void setup() {

  myServo.attach(servoPin);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);

}

void loop() {

  int potValue = analogRead(potPin);

  int angle = map(potValue, 0, 1023, 0, 180);

  myServo.write(angle);

  Serial.print("Servo Angle : ");
  Serial.println(angle);

  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {

    sweepServo();

  }

  lastButtonState = buttonState;

  delay(100);

}

void sweepServo() {

  for (int i = 0; i <= 180; i++) {

    myServo.write(i);

    delay(10);

  }

  for (int i = 180; i >= 0; i--) {

    myServo.write(i);

    delay(10);

  }

}
