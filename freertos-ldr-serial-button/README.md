Absolutely! Here’s your **final, detailed README.md** for the `freertos-ldr-serial-button` project, including task configuration, integration hurdles, and your design decisions:

---

```markdown
# FreeRTOS LDR Serial Button

A FreeRTOS-based Arduino Uno project that reads an LDR (light sensor) and prints the value to the Serial Monitor.  
A button toggles the display between raw value and percentage, all handled with separate FreeRTOS tasks.

**Author:** Nirmal T M

---

## Features

- Reads LDR value in a FreeRTOS task
- Prints value (raw or percent) to Serial Monitor in a separate task
- Button toggles display mode (raw/percent) in a third task
- Demonstrates multitasking with FreeRTOS on Arduino Uno

---

## Hardware

- Arduino Uno (ATmega328P)
- LDR (light-dependent resistor) with 10k resistor (voltage divider)
- Push button
- Breadboard and jumper wires

### Wiring

| Arduino Pin | Connects To         |
| ----------- | ------------------- |
| A0          | LDR voltage divider |
| D2          | Button (to GND)     |

---

## How it Works

- The LDR value is read every 100ms in one task.
- The value is printed to Serial Monitor every 500ms in another task, as either a raw value or a percentage.
- The button toggles between raw and percent display modes using a third task.

---

## FreeRTOS Task Configuration and Integration Notes

### Task Configuration

- **Task 1:** Reads the LDR value every 100ms (`TaskReadLDR`, stack size: 64)
- **Task 2:** Prints the value to Serial Monitor every 500ms (`TaskSerialPrint`, stack size: 128)
- **Task 3:** Handles button input and toggles display mode (`TaskButton`, stack size: 64)
- **All tasks run with priority 1**

### Integration Hurdles

- **RAM Limitations:**  
  The Arduino Uno has only 2KB of RAM.  
  When using graphical libraries like U8g2 (for OLED) or even some LCD libraries, each FreeRTOS task requires its own stack, and the display libraries require significant buffer memory.  
  This quickly exhausts available RAM, causing FreeRTOS to fail to start tasks (the built-in LED blinks, but nothing else works).

- **OLED/LCD with FreeRTOS:**

  - **OLED (U8g2):** Only possible to run a single task (combining LDR, button, and display logic) due to high RAM usage.
  - **LCD (LiquidCrystal_I2C):** Slightly better, but still not enough RAM for three separate tasks with display updates.
  - **Conclusion:** On Uno, multitasking with display libraries is not practical for demonstrating FreeRTOS task separation.

- **Why Serial Output?**  
  To truly showcase the multitasking capabilities of FreeRTOS on Arduino Uno, we switched to using Serial output.  
  This approach allows for three independent tasks (LDR reading, button handling, and serial printing) without running into RAM limitations, making it ideal for educational and demonstration purposes.

---

## Notes

- The button uses the internal pull-up resistor (no external resistor needed).
- Open Serial Monitor at 9600 baud to view the output.
- See the main [README](../README.md) for build and upload instructions.
- Code is in the `src/` folder.

---
```

---

**Copy and paste this into your project’s `README.md`!**  
Let me know if you want a code header or further documentation.
