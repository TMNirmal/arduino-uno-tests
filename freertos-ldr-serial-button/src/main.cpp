/**
 * @file    main.cpp
 * @brief   FreeRTOS LDR Serial Button Demo
 *
 * This project demonstrates multitasking on Arduino Uno using FreeRTOS.
 * - Task 1: Reads an LDR (light sensor) value every 100ms.
 * - Task 2: Prints the value (raw or percent) to Serial Monitor every 500ms.
 * - Task 3: Handles a button to toggle between raw and percent display modes.
 *
 * Due to RAM limitations on the Uno, display libraries (OLED/LCD) were not used
 * in multitasking mode. Serial output is used to best showcase FreeRTOS task separation.
 *
 * Hardware:
 *   - Arduino Uno (ATmega328P)
 *   - LDR with 10k resistor (voltage divider) to A0
 *   - Push button between D2 and GND (internal pull-up enabled)
 *
 * Author:   Nirmal T M
 * Date:     2025-07-27
 * Version:  1.0
 */
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define LDR_PIN A0
#define BUTTON_PIN 2

volatile bool showPercent = false;
volatile int ldrValue = 0;

void TaskReadLDR(void *pvParameters)
{
  (void)pvParameters;
  for (;;)
  {
    ldrValue = analogRead(LDR_PIN);
    vTaskDelay(100 / portTICK_PERIOD_MS); // 100ms
  }
}

void TaskSerialPrint(void *pvParameters)
{
  (void)pvParameters;
  for (;;)
  {
    if (showPercent)
    {
      float percent = ldrValue / 1023.0 * 100.0;
      Serial.print("Light: ");
      Serial.print(percent, 1);
      Serial.println(" %");
    }
    else
    {
      Serial.print("LDR: ");
      Serial.println(ldrValue);
    }
    vTaskDelay(500 / portTICK_PERIOD_MS); // 500ms
  }
}

void TaskButton(void *pvParameters)
{
  (void)pvParameters;
  bool lastState = HIGH;
  for (;;)
  {
    bool state = digitalRead(BUTTON_PIN);
    if (lastState == HIGH && state == LOW)
    {
      showPercent = !showPercent;
      vTaskDelay(300 / portTICK_PERIOD_MS); // Debounce
    }
    lastState = state;
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  xTaskCreate(TaskReadLDR, "ReadLDR", 64, NULL, 1, NULL);
  xTaskCreate(TaskSerialPrint, "SerialPrint", 128, NULL, 1, NULL);
  xTaskCreate(TaskButton, "Button", 64, NULL, 1, NULL);
  vTaskStartScheduler();
}

void loop()
{
  // Not used with FreeRTOS
}