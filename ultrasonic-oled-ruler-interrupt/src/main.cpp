/**
 * @file    main.cpp
 * @brief   Ultrasonic Ruler with OLED Display and Interrupt Unit Switch
 *
 * This program uses an HC-SR04 ultrasonic sensor to measure distance and displays
 * the result in real time on a 0.91" 128x32 I2C OLED. A button connected to D3
 * (interrupt pin) toggles the display units between centimeters and inches.
 * The display shows up to two decimal places for higher precision.
 *
 * - HC-SR04 Trig: D8, Echo: D9
 * - OLED: 0.91" 128x32 I2C (SDA: A4, SCL: A5)
 * - Button: D3 (to GND, uses interrupt)
 *
 * Author:   Nirmal T M
 * Date:     2025-07-27
 * Version:  1.0
 */
#include <Arduino.h>
#include <U8g2lib.h>

#define TRIG_PIN 8
#define ECHO_PIN 9
#define BUTTON_PIN 3 // D3 supports attachInterrupt()

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

volatile bool switchUnits = false;
bool showInches = false;

void handleButton()
{
  switchUnits = true;
}

float measureDistanceCM()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout
  float distance = duration * 0.0343 / 2.0;       // Use float math!
  return distance;
}

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  u8g2.begin();

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButton, FALLING);
}

void loop()
{
  float distanceCM = measureDistanceCM();
  float displayValue = distanceCM;
  String unit = "cm";

  if (switchUnits)
  {
    showInches = !showInches;
    switchUnits = false;
  }

  if (showInches)
  {
    displayValue = distanceCM * 0.3937;
    unit = "in";
  }

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setCursor(0, 15);
  u8g2.print("Dist: ");
  u8g2.print(displayValue, 2); // 2 decimal places
  u8g2.print(" ");
  u8g2.print(unit);
  u8g2.sendBuffer();
}