#include "SH1106Wire.h"

SH1106Wire display(0x3C, 33, 35);

const int leds[1] = {5};

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
  pinMode(leds[0], OUTPUT);
}

void loop() {
  digitalWrite(leds[0], HIGH);
}
