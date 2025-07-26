/**
 * @file main.cpp
 * @brief Arduino Uno LED Blink Test
 *
 * This program toggles the onboard LED (connected to pin 13) in a predefined
 * pattern with varying delays. It serves as a basic test for Arduino Uno GPIO
 * output functionality and timing control.
 *
 * Pattern:
 * - ON 1s, OFF 1s
 * - ON 200ms, OFF 200ms
 * - ON 500ms, OFF 500ms
 *
 * @author  Nirmal T M
 * @date    2025-07-26
 * @version 1.0
 */

#include <Arduino.h>

void setup()
{
  /* Setting inbuilt LED pin as poutput */
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  /* LED On */
  digitalWrite(LED_BUILTIN, HIGH);
  /* Delay */
  delay(1000);
  /* LED Off*/
  digitalWrite(LED_BUILTIN, LOW);
  /* Delay */
  delay(1000);
  /* LED On */
  digitalWrite(LED_BUILTIN, HIGH);
  /* Delay */
  delay(200);
  /* LED Off*/
  digitalWrite(LED_BUILTIN, LOW);
  /* Delay */
  delay(200);
  /* LED On */
  digitalWrite(LED_BUILTIN, HIGH);
  /* Delay */
  delay(500);
  /* LED Off*/
  digitalWrite(LED_BUILTIN, LOW);
  /* Delay */
  delay(500);
}