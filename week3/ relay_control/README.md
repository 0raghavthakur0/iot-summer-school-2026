# Relay Controlled AC Device Simulation

## Components

- Arduino UNO
- DHT11 Sensor
- LED (Relay Simulation)
- Push Button
- 220Ω Resistor
- Breadboard
- Jumper Wires

## Connections

DHT11 → Pin 2

Relay LED → Pin 8

Manual Override Button → Pin 3

## Working

- Temperature > 32°C → Relay (LED) ON
- Temperature < 28°C → Relay (LED) OFF
- Hysteresis prevents rapid ON/OFF switching.
- Manual override button toggles the relay.
- Serial Monitor logs all relay state changes with temperature.
