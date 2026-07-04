/*
-------------------------------------------------------
Author      : Raghav Thakur
Course      : IIT Jammu Summer School 2026
Module      : Module 3
Question    : Q23
Description : Smart Street Light using LDR + PIR
-------------------------------------------------------
*/

const int ldrPin = A0;
const int pirPin = 2;
const int ledPin = 9;      // PWM pin

const int threshold = 500;

unsigned long motionTime = 0;
bool motionDetected = false;

void setup() {

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int lightValue = analogRead(ldrPin);

  // DAY MODE
  if (lightValue > threshold) {

    analogWrite(ledPin, 0);

    logEvent("DAYLIGHT - LED OFF");

    delay(1000);
    return;
  }

  // NIGHT MODE
  if (digitalRead(pirPin) == HIGH) {

    motionDetected = true;
    motionTime = millis();

    analogWrite(ledPin, 255);

    logEvent("MOTION DETECTED - LED FULL BRIGHTNESS");

  }

  if (motionDetected) {

    if (millis() - motionTime >= 30000) {

      analogWrite(ledPin, 51);      // 20% of 255

      logEvent("NO MOTION - DIM MODE");

      motionDetected = false;
    }

  }

  delay(100);

}

void logEvent(String event) {

  unsigned long sec = millis() / 1000;

  int h = sec / 3600;
  int m = (sec % 3600) / 60;
  int s = sec % 60;

  Serial.print("[");
  if (h < 10) Serial.print("0");
  Serial.print(h);
  Serial.print(":");

  if (m < 10) Serial.print("0");
  Serial.print(m);
  Serial.print(":");

  if (s < 10) Serial.print("0");
  Serial.print(s);

  Serial.print("] EVENT: ");

  Serial.println(event);

}
