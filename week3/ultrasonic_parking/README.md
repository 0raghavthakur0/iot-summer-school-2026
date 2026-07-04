# Ultrasonic Parking Sensor

## Components

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Green LED
- Yellow LED
- Red LED
- Passive Buzzer
- 220Ω Resistors
- Breadboard

---

## Connections

Trig → Pin 9

Echo → Pin 10

Green LED → Pin 2

Yellow LED → Pin 3

Red LED → Pin 4

Buzzer → Pin 8

---

## Distance Conditions

Distance > 50 cm

SAFE

Green LED ON

---

20–50 cm

Yellow LED ON

Buzzer every 500 ms

---

10–20 cm

Red LED ON

Buzzer every 200 ms

---

Distance < 10 cm

All LEDs Flash

Buzzer Continuous
