/**
 * @file    main.cpp
 * @brief   PWM LED Fading Demo
 *
 * Smoothly fades an LED in and out using PWM on pin 9.
 * The PWM frequency is set to 490 Hz (default for Timer1 on Arduino Uno).
 * Connect the LED (with a resistor) to pin 9 and GND.
 *
 * Author:   Nirmal T M
 * Date:     2025-07-27
 * Version:  1.0
 */

#include <Arduino.h>

#define LED_PIN 9 // Use a PWM-capable pin (e.g., 3, 5, 6, 9, 10, or 11 on Uno)

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  // Set Timer1 prescaler to 64 (default, 490 Hz)
  TCCR1B = (TCCR1B & 0b11111000) | 0x03;
}

void loop()
{
  // Fade in
  for (int brightness = 0; brightness <= 255; brightness += 5)
  {
    analogWrite(LED_PIN, brightness);
    delay(20); // Adjust for speed of fading
  }
  // Fade out
  for (int brightness = 255; brightness >= 0; brightness -= 5)
  {
    analogWrite(LED_PIN, brightness);
    delay(20);
  }
}