#include "SH1106Wire.h"
#include "graphics.h"

// 1. Finish Image, Fix Push Button Input, Make Text Slideshow, Make Animations, Make Schematic, Print PCB

SH1106Wire display(0x3C, 33, 35);

const int leds[5] = {3, 5, 7, 9, 11};
const String text[4] = {"Hello World", "You are Really Awesome", "Jshddsj dsahjdaskhjd dashdasjkhdjas dashdasjkhdsaj adshdaskjhdsaj daskjadshjkdas"};
const int button = 16;
// 0 = no animation, 
int starAnimation = 0;


void setup() {
  Serial.begin(115200);

  // OLED Setup
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawXbm(0, 5, logo_width, logo_height, logo);
  display.display();

  // LED Setup
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button, INPUT);
}

void loop() {
  for (int i = 1; i < 5; i++) {
    digitalWrite(leds[i], HIGH);
  }

  int pushed = digitalRead(button);
  if (pushed == HIGH) {
    if (starAnimation == 2) {
      starAnimation = 0;
    } else  {
      starAnimation += 1;
    }
    delay(100);
  }

  
}

void displayIntroScreen() {
  
}
