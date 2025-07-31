# EEPROM Counter

A simple Arduino project that counts button presses and stores the count in EEPROM.  
The counter value is preserved across resets and power cycles.

**Author:** Nirmal T M

---

## Features

- Button press increments a persistent counter
- Counter value is stored in EEPROM (non-volatile memory)
- Value is printed to Serial Monitor

---

## Hardware

- Arduino Uno (ATmega328P)
- Push button
- Breadboard and jumper wires

### Wiring

| Arduino Pin | Connects To     |
| ----------- | --------------- |
| D2          | Button (to GND) |

---

## How it Works

- On startup, the counter is loaded from EEPROM.
- Each button press increments the counter and saves it back to EEPROM.
- The value is printed to Serial Monitor at 9600 baud.

---

## Notes

- The button uses the internal pull-up resistor (no external resistor needed).
- EEPROM has a limited write life (about 100,000 cycles per address).
- See the main [README](../README.md) for build and upload instructions.
- Code is in the `src/` folder.

---
