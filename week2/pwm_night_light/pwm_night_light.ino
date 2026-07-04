/*
-------------------------------------------------------
Author      : Raghav Thakur
Course      : IIT Jammu Summer School 2026
Module      : Module 2
Question    : Q17
Description : PWM Fading Night Light
-------------------------------------------------------
*/

const int ledPin = 9;      // PWM pin
const int buttonPin = 2;

int mode = 1;
bool lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Mode 1 : Slow Breathing");
}

void loop() {

  bool currentButton = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButton == LOW) {
    mode++;
    if (mode > 3) mode = 1;

    switch (mode) {
      case 1:
        Serial.println("Mode 1 : Slow Breathing");
        break;

      case 2:
        Serial.println("Mode 2 : Fast Pulse");
        break;

      case 3:
        Serial.println("Mode 3 : SOS");
        break;
    }

    delay(200);
  }

  lastButtonState = currentButton;

  switch (mode) {

    case 1:
      breathing(12);      // ~3 sec cycle
      break;

    case 2:
      breathing(2);       // ~0.5 sec cycle
      break;

    case 3:
      SOS();
      break;
  }

}

void breathing(int d) {

  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(d);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(d);
  }

}

void SOS() {

  for (int i = 0; i < 3; i++) {
    flash(150);
  }

  for (int i = 0; i < 3; i++) {
    flash(450);
  }

  for (int i = 0; i < 3; i++) {
    flash(150);
  }

  delay(1000);

}

void flash(int t) {
  digitalWrite(ledPin, HIGH);
  delay(t);
  digitalWrite(ledPin, LOW);
  delay(150);
}
