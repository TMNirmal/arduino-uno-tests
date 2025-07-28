# UART to I2C 16x2 LCD Display (Newest at Top-Left)

Displays serial data received via UART on a 16x2 I2C LCD in real time.  
**The latest character always appears at the top-left (0,0), filling left-to-right, top row first, then bottom row.**  
When the display is full, new characters overwrite from the top-left again (circular buffer).

**Author:** Nirmal T M

---

## Features

- Real-time display of serial data on a 16x2 I2C LCD
- Latest character always at top-left, oldest at bottom-right
- I2C address is auto-detected and printed to Serial
- Works with any 16x2 LCD with I2C backpack (PCF8574, e.g., 0x27)
- Clean, modular C++ code for PlatformIO/VS Code

---

## Hardware

- Arduino Uno (ATmega328P)
- 16x2 LCD with I2C backpack (PCF8574)
- Breadboard and jumper wires

### Wiring

| LCD Pin | Arduino Uno Pin |
| ------- | --------------- |
| VCC     | 5V              |
| GND     | GND             |
| SDA     | A4              |
| SCL     | A5              |

---

## How it Works

- On startup, the Arduino scans for the I2C LCD address and prints it to Serial.
- The LCD displays a welcome message, then waits for serial input.
- Each character you type in the Serial Monitor (9600 baud) appears immediately at the top-left of the LCD, pushing older characters right and down.
- When the display is full, new characters overwrite from the top-left again.

---

## Notes

- Set your Serial Monitor to **9600 baud** and "No line ending" for best results.
- See the main [README](../README.md) for build and upload instructions.
- Code is in the `src/` folder.

---
