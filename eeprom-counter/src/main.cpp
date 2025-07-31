/**
 * @file    main.cpp
 * @brief   EEPROM Button Press Counter
 *
 * This program counts the number of times a button is pressed and stores the count
 * in the Arduino's EEPROM. The counter value is preserved across resets and power cycles.
 * Each button press increments the counter and saves it to EEPROM. The current count
 * is printed to the Serial Monitor.
 *
 * - Button connected between D2 and GND (internal pull-up enabled)
 * - Uses EEPROM to store and retrieve the counter value
 *
 * Author:   Nirmal T M
 * Date:     2025-07-27
 * Version:  1.0
 */
#include <Arduino.h>
#include <EEPROM.h>
#define BUTTON_PIN 2

unsigned long counter = 0;

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

  EEPROM.get(0, counter);
  if (counter == 0xFFFFFFFF)
  {
    counter = 0;
    EEPROM.put(0, counter);
  }
  Serial.print("Counter loaded from EEPROM: ");
  Serial.println(counter);
}

void loop()
{
  if (digitalRead(BUTTON_PIN) == LOW)
  {
    counter++;
    Serial.print("Button pressed! Counter: ");
    Serial.println(counter);
    EEPROM.put(0, counter);
    delay(300); // Simple debounce
  }
}