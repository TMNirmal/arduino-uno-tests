/**
 * @file    main.cpp
 * @brief   Stepper Gate with Button Control
 *
 * This program controls a stepper motor to open and close a gate using a push button.
 * Each button press toggles the gate state (open/close) by rotating the stepper motor
 * one full revolution in the appropriate direction.
 *
 * - Uses a 28BYJ-48 stepper motor with ULN2003 driver
 * - Button connected between D7 and GND (internal pull-up enabled)
 * - External 5V power supply recommended for the stepper motor
 *
 * Author:   Nirmal T M
 * Date:     2025-07-27
 * Version:  1.0
 */
#include <Arduino.h>
#include <Stepper.h>

#define STEPS_PER_REV 2048
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define BUTTON_PIN 7

Stepper myStepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

bool gateOpen = false;

void setup()
{
  myStepper.setSpeed(10);            // 10 RPM
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Button to GND
}

void loop()
{
  // Wait for button press
  if (digitalRead(BUTTON_PIN) == LOW)
  {
    // Toggle gate state
    if (gateOpen)
    {
      myStepper.step(-STEPS_PER_REV); // Close gate
      gateOpen = false;
    }
    else
    {
      myStepper.step(STEPS_PER_REV); // Open gate
      gateOpen = true;
    }
    // Wait for button release to avoid multiple triggers
    while (digitalRead(BUTTON_PIN) == LOW)
      ;
    delay(200); // Debounce
  }
}