# Stepper Gate Button

Control a gate or barrier using a stepper motor and a button.  
Each button press toggles the gate open or closed by rotating the stepper motor.

**Author:** Nirmal T M

---

## Features

- Button toggles gate open/closed
- Stepper motor moves one full revolution per action
- Simple, reliable button debounce logic

---

## Hardware

- Arduino Uno (ATmega328P)
- 28BYJ-48 stepper motor with ULN2003 driver
- Push button
- External 5V power supply for stepper
- Breadboard and jumper wires

### Wiring

| Arduino Pin | Connects To     |
| ----------- | --------------- |
| D2          | Stepper IN1     |
| D3          | Stepper IN2     |
| D4          | Stepper IN3     |
| D5          | Stepper IN4     |
| D7          | Button (to GND) |
| 5V (ext)    | Stepper VCC     |
| GND         | All GNDs        |

---

## How it Works

- Press the button to open or close the gate.
- The stepper motor rotates one full revolution in the appropriate direction.
- The code uses a simple debounce: it waits for the button to be released before allowing another action.

---

## Notes

- Adjust the number of steps in the code for your specific gate or mechanism.
- Use an external 5V supply for the stepper motor for best results.
- All grounds (Arduino, stepper driver, power supply) must be connected together.

---
