# Arduino Uno Tests

A collection of **basic Arduino Uno projects** focused on testing fundamental coding techniques and interfacing with peripherals such as LEDs, displays, and communication modules.  
All projects are developed using **PlatformIO** in **VS Code** with pure C++ (`.cpp`) structure (no `.ino` files).

---

## ✅ Projects

| Project                                                             | Description                                                                    |
| ------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| [blink-led](blink-led/)                                             | Basic LED blink test with different timing patterns                            |
| [led-pwm-fade](led-pwm-fade/)                                       | Smooth PWM LED fading demo on pin 9 (breathing effect)                         |
| [oled-monochrome-0.91inch](oled-monochrome-0.91inch/)               | Animated waveform display (Sine, Square, Triangle) on 0.91" 128x32 OLED        |
| [oled-monochrome-0.96inch-button](oled-monochrome-0.96inch-button/) | Animated waveform display on 0.96" 128x64 OLED with button to change wave      |
| [uart-lcd-16x2](uart-lcd-16x2/)                                     | Real-time UART to I2C 16x2 LCD: newest char at top-left, circular buffer       |
| [stepper-gate-button](stepper-gate-button/)                         | Button-controlled stepper motor gate: toggles open/close with each press       |
| [ultrasonic-oled-ruler-interrupt](ultrasonic-oled-ruler-interrupt/) | Ultrasonic ruler with OLED display and button interrupt for unit switch        |
| [eeprom-counter](eeprom-counter/)                                   | Button press counter with persistent storage in EEPROM                         |
| [freertos-ldr-serial-button](freertos-ldr-serial-button/)           | FreeRTOS multitasking: LDR reading, button, and serial print in separate tasks |

This collection is actively maintained—upcoming projects will include CAN bus, temperature and humidity sensors, IR remote decoding, servo motor control, and more!

---

## 🛠️ Development Environment

- **Board:** Arduino Uno (ATmega328P)
- **IDE:** VS Code with PlatformIO
- **Language:** C++ (`.cpp`)
- **Framework:** Arduino

---

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/TMNirmal/arduino-uno-tests.git
cd arduino-uno-tests
```
