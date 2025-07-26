# OLED Waveform Display (128x64, Button Control)

Displays animated Sine, Square, and Triangle waveforms on a 0.96" 128x64 I2C OLED (SSD1306) using the U8g2 library.  
**Press the button to cycle through the waveforms.**

**Author:** Nirmal T M

---

## Features

- Animated Sine, Square, and Triangle waveforms
- Button press cycles to the next waveform
- Title shown in the yellow area (top 16px)
- Author label at the bottom right
- Modular code structure (header/source files)

---

## Hardware

- Arduino Uno, Nano, or compatible board
- 0.96" 128x64 I2C OLED display (SSD1306, yellow+blue)
- Push button

### Wiring

| OLED Pin | Arduino Uno/Nano Pin |
| -------- | -------------------- |
| VCC      | 3.3V or 5V           |
| GND      | GND                  |
| SCL      | A5 (or SCL pin)      |
| SDA      | A4 (or SDA pin)      |

| Button Pin | Arduino Pin |
| ---------- | ----------- |
| One side   | D2          |
| Other side | GND         |

---

## Notes

- The button uses the Arduino’s internal pull-up resistor (no external resistor needed).
- See the main repository [README](../README.md) for build and upload instructions.
- All code is in the `src/` folder.

---
