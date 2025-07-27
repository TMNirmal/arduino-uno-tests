# LED PWM Fade

Smoothly fades an LED in and out using PWM on Arduino Uno pin 9.

**Author:** Nirmal T M

---

## Features

- Uses PWM to smoothly fade an LED up and down
- PWM frequency set to 490 Hz (default for Timer1 on Uno)
- Clean, simple C++ code for PlatformIO/VS Code

---

## Hardware

- Arduino Uno (ATmega328P)
- 1x LED
- 1x 220Ω resistor
- Breadboard and jumper wires

### Wiring

| Arduino Pin | Component       |
| ----------- | --------------- |
| 9           | LED anode (+)   |
| GND         | LED cathode (–) |

_(Place a 220Ω resistor in series with the LED)_

---

## How it Works

- The code uses `analogWrite()` to set the LED brightness.
- The `for` loops increase and decrease the duty cycle, creating a smooth "breathing" effect.
- The PWM frequency is set to 490 Hz (default for pin 9).

---

## Notes

- See the main [README](../README.md) for build and upload instructions.
- Code is in the `src/` folder.

---
