/* WaveformDisplay.cpp
---------------------------------------------
Author: Nirmal T M
Description: Implements OLED waveform display functions
---------------------------------------------*/

#include "WaveformDisplay.h"
#include <math.h>

// Define the display object
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void generateWave(int type, float phase, uint8_t *graphData, int len)
{
    for (int i = 0; i < len; i++)
    {
        float x = (i + phase) * 2 * 3.14159 / 64.0;
        switch (type)
        {
        case 0: // Sine
            graphData[i] = 16 + 10 * sin(x);
            break;
        case 1: // Square
            graphData[i] = (sin(x) > 0) ? 6 : 26;
            break;
        case 2: // Triangle
            graphData[i] = 16 + 10 * (2 * fabs(2 * (x / (2 * 3.14159) - floor(x / (2 * 3.14159) + 0.5))) - 1);
            break;
        }
    }
}

void drawWaveformDisplay(int waveType, float phase, uint8_t *graphData, int len)
{
    u8g2.clearBuffer();

    // Draw a filled bar as a background (e.g., for a title)
    u8g2.setDrawColor(1);
    u8g2.drawBox(0, 0, 128, 10);

    // Draw the top label (white text on black bar)
    u8g2.setDrawColor(0); // Invert color for text on bar
    u8g2.setFont(u8g2_font_6x10_tr);

    const char *waveNames[] = {"Sine Wave", "Square Wave", "Triangle Wave"};
    u8g2.drawStr(2, 8, waveNames[waveType]);

    // Draw the bottom label (right corner)
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_5x8_tr);
    const char *author = "By Nirmal T M";
    int16_t tx = 128 - u8g2.getStrWidth(author) - 2; // 2px padding from right
    u8g2.drawStr(tx, 31, author);

    // Draw the waveform
    for (int x = 1; x < len; x++)
    {
        u8g2.drawLine(x - 1, graphData[x - 1], x, graphData[x]);
    }

    // Draw Y-axis and X-axis
    u8g2.drawLine(0, 10, 0, 31);   // Y-axis
    u8g2.drawLine(0, 31, 127, 31); // X-axis

    u8g2.sendBuffer();
}