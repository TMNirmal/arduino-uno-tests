/**
 * @file    main.cpp
 * @brief   OLED Waveform Display with Button Control
 *
 * This program displays animated waveforms (Sine, Square, Triangle) on a 0.96" 128x64 I2C OLED.
 * Each press of a button cycles to the next waveform. The display uses the U8g2 library.
 *
 * - Button connected between D2 and GND (internal pull-up enabled)
 * - Author label shown at the bottom right
 * - Title shown in the yellow area (top 16px) of the display
 *
 * Author:   Nirmal T M
 * Date:     2025-07-26
 * Version:  1.1
 */

#include <Arduino.h>
#include "WaveformDisplay.h"

#define BUTTON_PIN 2
uint8_t graphData[128];
float phase = 0;
unsigned long lastSwitch = 0;
int waveType = 0; // 0: Sine, 1: Square, 2: Triangle
uint8_t lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // ms

void setup()
{
  u8g2.begin();
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Button to GND, enable pull-up
  lastSwitch = millis();
}

void loop()
{
  static uint8_t buttonState = HIGH;
  uint8_t reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading == LOW && buttonState == HIGH)
    {
      // Button was just pressed
      waveType = (waveType + 1) % 3;
    }
    buttonState = reading;
  }

  lastButtonState = reading;

  generateWave(waveType, phase, graphData, 128);
  phase += 1;
  if (phase >= 64)
    phase = 0;

  drawWaveformDisplay(waveType, phase, graphData, 128);
  delay(50);
}