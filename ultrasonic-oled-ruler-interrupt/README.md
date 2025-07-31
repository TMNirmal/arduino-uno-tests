# Ultrasonic OLED Ruler Interrupt

A real-time digital ruler using the HC-SR04 ultrasonic sensor and a 0.91" 128x32 OLED display.  
A button interrupt allows you to instantly switch between centimeters and inches.

**Author:** Nirmal T M

---

## Features

- Real-time distance measurement with HC-SR04
- Displays distance on a 0.91" 128x32 I2C OLED (SSD1306)
- Button (on D3) toggles units between cm and inches using an interrupt
- High precision: displays up to two decimal places

---

## Hardware

- Arduino Uno (ATmega328P)
- HC-SR04 ultrasonic sensor
- 0.91" 128x32 I2C OLED display (SSD1306)
- Push button
- Breadboard and jumper wires

### Wiring

| Module       | Arduino Pin |
| ------------ | ----------- |
| HC-SR04 Trig | D8          |
| HC-SR04 Echo | D9          |
| OLED SDA     | A4          |
| OLED SCL     | A5          |
| Button       | D3 (to GND) |
| HC-SR04 VCC  | 5V          |
| HC-SR04 GND  | GND         |
| OLED VCC     | 3.3V or 5V  |
| OLED GND     | GND         |

---

## How it Works

- The Arduino continuously measures distance using the HC-SR04.
- The distance is displayed on the OLED in real time.
- Pressing the button (D3) toggles the display between centimeters and inches using an interrupt for instant response.
- The display shows up to two decimal places for both units.

---

## Notes

- Use a stable 5V supply for the HC-SR04 for best accuracy.
- The button uses the internal pull-up resistor (no external resistor needed).
- See the main [README](../README.md) for build and upload instructions.
- Code is in the `src/` folder.

---
