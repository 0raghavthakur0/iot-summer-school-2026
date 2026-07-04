/*
-------------------------------------------------------
Author      : Raghav Thakur
Course      : IIT Jammu Summer School 2026
Module      : Module 3
Question    : Q22
Description : Ultrasonic Parking Sensor
-------------------------------------------------------
*/

const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

const int buzzer = 8;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration * 0.034) / 2;

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 50) {

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    noTone(buzzer);

    Serial.println("SAFE");

  }

  else if (distance > 20) {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    tone(buzzer, 1000);
    delay(100);
    noTone(buzzer);
    delay(400);

  }

  else if (distance > 10) {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1000);
    delay(100);
    noTone(buzzer);
    delay(100);

  }

  else {

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1000);

    delay(100);

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    delay(100);

  }

}
