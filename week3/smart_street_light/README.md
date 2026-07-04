# Smart Street Light

## Components

- Arduino UNO
- LDR
- PIR Motion Sensor
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

## Connections

LDR → A0

PIR → Pin 2

LED (PWM) → Pin 9

## Working

- Daylight → LED OFF
- Dark + Motion → LED at 100% brightness for 30 seconds
- No motion after 30 seconds → LED dimmed to 20%
- All events are logged on the Serial Monitor with timestamps.

## Circuit Diagram

Upload a hand-drawn diagram or Tinkercad screenshot to:

week3/schematics/
