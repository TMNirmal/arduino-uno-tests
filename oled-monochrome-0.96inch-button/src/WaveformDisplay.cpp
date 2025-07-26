/**
 * @file    WaveformDisplay.cpp
 * @brief   OLED waveform rendering functions for 128x64 SSD1306 display
 *
 * Implements functions to generate and draw animated waveforms (Sine, Square, Triangle)
 * on a 0.96" 128x64 I2C OLED using the U8g2 library. The title is displayed in the yellow
 * area (top 16px), the waveform is drawn in the blue area, and the author label is shown
 * at the bottom right.
 *
 * Author:   Nirmal T M
 * Date:     2025-07-26
 * Version:  1.1
 */
#include "WaveformDisplay.h"
#include <math.h>

// Display object
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void generateWave(int type, float phase, uint8_t *graphData, int len)
{
    // Waveform area: y = 16 to y = 54 (39 pixels)
    // Center at y=35, amplitude=19 (so min=16, max=54)
    for (int i = 0; i < len; i++)
    {
        float x = (i + phase) * 2 * 3.14159 / 64.0;
        float y = 0;
        switch (type)
        {
        case 0: // Sine
            y = 35 + 19 * sin(x);
            break;
        case 1: // Square
            y = (sin(x) > 0) ? 16 : 54;
            break;
        case 2: // Triangle
            y = 35 + 19 * (2 * fabs(2 * (x / (2 * 3.14159) - floor(x / (2 * 3.14159) + 0.5))) - 1);
            break;
        }
        // Clamp to waveform area
        if (y < 16)
            y = 16;
        if (y > 54)
            y = 54;
        graphData[i] = (uint8_t)y;
    }
}

void drawWaveformDisplay(int waveType, float phase, uint8_t *graphData, int len)
{
    u8g2.clearBuffer();

    // Title bar: 16 pixels high (yellow area)
    const uint8_t titleBarHeight = 16;
    // Bottom label area: y=55 to y=63 (9 pixels)
    const uint8_t bottomLabelY = 63;
    const uint8_t waveformTop = 16;
    const uint8_t waveformBottom = 54;

    // Draw title bar (fills yellow area)
    u8g2.setDrawColor(1);
    u8g2.drawBox(0, 0, 128, titleBarHeight);

    // Draw the top label (white on black)
    u8g2.setDrawColor(0);
    u8g2.setFont(u8g2_font_6x10_tr);
    const char *waveNames[] = {"Sine", "Square", "Triangle"};
    u8g2.drawStr(2, 13, waveNames[waveType]); // y=13 for vertical centering in 16px

    // Draw the waveform (strictly between waveformTop and waveformBottom)
    u8g2.setDrawColor(1);
    for (int x = 1; x < len; x++)
    {
        u8g2.drawLine(x - 1, graphData[x - 1], x, graphData[x]);
    }

    // Draw bottom label background (optional, for clarity)
    u8g2.drawBox(0, 55, 128, 9);

    // Draw the bottom label (right corner, white on black)
    u8g2.setDrawColor(0);
    u8g2.setFont(u8g2_font_6x10_tr);
    const char *author = "By Nirmal T M";
    int16_t tx = 128 - u8g2.getStrWidth(author) - 2;
    u8g2.drawStr(tx, bottomLabelY, author);

    // Draw Y-axis and X-axis (within waveform area)
    u8g2.setDrawColor(1);
    u8g2.drawLine(0, waveformTop, 0, waveformBottom);      // Y-axis
    u8g2.drawLine(0, waveformBottom, 127, waveformBottom); // X-axis

    u8g2.sendBuffer();
}