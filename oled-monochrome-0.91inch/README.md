# OLED Waveform Display

Animated Sine, Square, and Triangle waveforms on a 0.91" 128x32 I2C OLED using the U8g2 library.

**Author:** Nirmal T M

---

## Features

- Animated Sine, Square, and Triangle waveforms (cycles every 3 seconds)
- Dashboard UI with waveform name and right-aligned author label
- Modular code structure (header/source files)

---

## Hardware

- Arduino Uno, Nano, or compatible board
- 0.91" 128x32 I2C OLED display (SSD1306)

### Wiring

| OLED Pin | Arduino Uno/Nano Pin |
| -------- | -------------------- |
| VCC      | 3.3V or 5V           |
| GND      | GND                  |
| SCL      | A5 (or SCL pin)      |
| SDA      | A4 (or SDA pin)      |

---

## Notes

- See the main repository [README](../README.md) for build and upload instructions.
- Code is in `src/` folder.

---
