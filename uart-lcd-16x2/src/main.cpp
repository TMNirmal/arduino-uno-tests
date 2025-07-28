/**
 * @file    main.cpp
 * @brief   Real-time UART to I2C 16x2 LCD Display (Newest at Top-Left)
 *
 * This program receives serial data from the UART and displays it on a 16x2 I2C LCD.
 * The latest character always appears at the top-left (0,0), filling left-to-right,
 * top row first, then bottom row. When the display is full, new characters overwrite
 * from the top-left again (circular buffer).
 *
 * - I2C address is auto-detected and printed to Serial.
 * - LCD: 16x2 with I2C backpack (PCF8574, e.g., 0x27)
 * - Serial: 9600 baud, send characters from Serial Monitor.
 *
 * Author:   Nirmal T M
 * Date:     2025-07-27
 * Version:  1.0
 */

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_COLS 16
#define LCD_ROWS 2

uint8_t foundAddress = 0;
LiquidCrystal_I2C *lcd = nullptr;

char lcdBuffer[LCD_COLS * LCD_ROWS];
uint8_t bufferPos = 0;

void findI2CAddress()
{
  Serial.println("Scanning for I2C devices...");
  for (uint8_t address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0)
    {
      foundAddress = address;
      Serial.print("I2C device found at 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
      break;
    }
  }
  if (foundAddress == 0)
  {
    Serial.println("No I2C device found!");
    while (1)
      ; // Stop here
  }
}

void updateLcdDisplay()
{
  lcd->clear();
  // Display the buffer in reverse: newest at (0,0), oldest at (15,1)
  for (uint8_t i = 0; i < LCD_COLS * LCD_ROWS; i++)
  {
    uint8_t bufIndex = (bufferPos + LCD_COLS * LCD_ROWS - 1 - i) % (LCD_COLS * LCD_ROWS);
    uint8_t row = i / LCD_COLS;
    uint8_t col = i % LCD_COLS;
    lcd->setCursor(col, row);
    lcd->print(lcdBuffer[bufIndex]);
  }
}

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  delay(200);

  findI2CAddress();

  lcd = new LiquidCrystal_I2C(foundAddress, LCD_COLS, LCD_ROWS);
  lcd->init();
  lcd->backlight();

  // Initialize buffer with spaces
  for (uint8_t i = 0; i < LCD_COLS * LCD_ROWS; i++)
  {
    lcdBuffer[i] = ' ';
  }
  bufferPos = 0;

  lcd->setCursor(0, 0);
  lcd->print("Welcome! Type:");
  lcd->setCursor(0, 1);
  lcd->print("Serial->LCD LTR");
  delay(1500);
  lcd->clear();
  updateLcdDisplay();

  Serial.print("LCD ready at I2C 0x");
  if (foundAddress < 16)
    Serial.print("0");
  Serial.println(foundAddress, HEX);
  Serial.println("Type to see newest char at top-left, oldest at bottom-right.");
}

void loop()
{
  while (Serial.available())
  {
    char c = Serial.read();
    if (c >= 32 && c <= 126)
    {
      lcdBuffer[bufferPos] = c;
      bufferPos = (bufferPos + 1) % (LCD_COLS * LCD_ROWS);
      updateLcdDisplay();
    }
  }
}