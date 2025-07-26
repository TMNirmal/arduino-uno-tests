/* main.cpp
 ---------------------------------------------
 Author: Nirmal T M
 Description: Main file for OLED waveform display demo
 ---------------------------------------------*/

#include <Arduino.h>
#include "WaveformDisplay.h"

uint8_t graphData[128];
float phase = 0;
unsigned long lastSwitch = 0;
int waveType = 0; // 0: Sine, 1: Square, 2: Triangle

void setup()
{
  u8g2.begin();
  lastSwitch = millis();
}

void loop()
{
  // Switch waveform every 3 seconds
  if (millis() - lastSwitch > 3000)
  {
    waveType = (waveType + 1) % 3;
    lastSwitch = millis();
  }

  generateWave(waveType, phase, graphData, 128);
  phase += 1;
  if (phase >= 64)
    phase = 0;

  drawWaveformDisplay(waveType, phase, graphData, 128);
  delay(50);
}