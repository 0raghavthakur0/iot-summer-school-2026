/*
-------------------------------------------------------
Author      : Raghav Thakur
Course      : IIT Jammu Summer School 2026
Module      : Module 2
Question    : Q16
Description : Serial Command Interface
-------------------------------------------------------
*/

const int led = 13;

String command = "";
int blinkCounter = 0;
bool ledState = false;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  Serial.println("=== Serial Command Interface ===");
}

void loop() {

  if (Serial.available()) {

    command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "LED_ON") {

      digitalWrite(led, HIGH);
      ledState = true;
      Serial.println("LED ON");

    }

    else if (command == "LED_OFF") {

      digitalWrite(led, LOW);
      ledState = false;
      Serial.println("LED OFF");

    }

    else if (command.startsWith("BLINK_")) {

      int times = command.substring(6).toInt();

      if (times >= 1 && times <= 9) {

        for (int i = 0; i < times; i++) {

          digitalWrite(led, HIGH);
          delay(300);

          digitalWrite(led, LOW);
          delay(300);

          blinkCounter++;
        }

        Serial.print("Blink Count = ");
        Serial.println(blinkCounter);
      }

      else {
        Serial.println("ERROR: Blink value must be between 1 and 9");
      }
    }

    else if (command == "STATUS") {

      Serial.print("LED State : ");

      if (ledState)
        Serial.println("ON");
      else
        Serial.println("OFF");

      Serial.print("Blink Counter : ");
      Serial.println(blinkCounter);
    }

    else if (command == "RESET") {

      blinkCounter = 0;
      Serial.println("Blink Counter Reset");

    }

    else {

      Serial.println("ERROR: Unknown command");

    }

  }

}
