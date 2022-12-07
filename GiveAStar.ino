#include "SH1106Wire.h"

SH1106Wire display(0x3C, 33, 35);

const int leds[5] = {3, 5, 7, 9, 11};
const int button = 16;


void setup() {
  Serial.begin(115200);

  // OLED Setup
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(18, 15, "Project Give A Star!");
  display.drawString(20, 35, "By Angelina Tsuboi");
  display.display();

  // LED Setup
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button, INPUT);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH);
  }
}
