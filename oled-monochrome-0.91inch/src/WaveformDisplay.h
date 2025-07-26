/* WaveformDisplay.h
---------------------------------------------
Author: Nirmal T M
Description: Declarations for OLED waveform display functions
Supports: Sine, Square, Triangle waveforms with U8g2
---------------------------------------------*/

#ifndef WAVEFORMDISPLAY_H
#define WAVEFORMDISPLAY_H

#include <Arduino.h>
#include <U8g2lib.h>

// Externally defined display object
extern U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2;

// Function to generate waveform data
void generateWave(int type, float phase, uint8_t *graphData, int len);

// Function to draw the display
void drawWaveformDisplay(int waveType, float phase, uint8_t *graphData, int len);

#endif // WAVEFORMDISPLAY_H