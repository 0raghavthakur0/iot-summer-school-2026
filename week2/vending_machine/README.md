# Vending Machine State Machine

## Components

- Arduino UNO
- 3 Push Buttons
- 3 LEDs
- 220Ω Resistors
- Breadboard

## Buttons

Pin 2 → Insert Coin

Pin 3 → Select Item

Pin 4 → Cancel

## LEDs

Red → IDLE

Yellow → COIN_INSERTED

Green → ITEM_SELECTED

Red + Green → DISPENSING

## State Flow

IDLE

↓

COIN_INSERTED

↓

ITEM_SELECTED

↓

DISPENSING

↓

IDLE

Cancel returns to IDLE.
