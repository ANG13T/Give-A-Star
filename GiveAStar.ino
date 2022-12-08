#include "SH1106Wire.h"
#include "graphics.h"

// 1. Finish Image, Fix Push Button Input, Make Text Slideshow, Make Animations, Make Schematic, Print PCB

SH1106Wire display(0x3C, 33, 35);

const int leds[5] = {3, 5, 7, 9, 11};
const String text[4] = {"Hello World", "You are Really Awesome", "Jshddsj dsahjdaskhjd dashdasjkhdjas dashdasjkhdsaj adshdaskjhdsaj daskjadshjkdas"};
const int button = 16;
// 0 = no animation, 1 = in order, 2 = pairs, 3 = flashing
int starAnimation = 0;


void setup() {
  Serial.begin(115200);

  // OLED Setup
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawXbm(5, 5, logo_width, logo_height, logo);
  display.display();

  // LED Setup
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button, INPUT);
  delay(1000);
  display.clear();
}

void loop() {
 
  int pushed = digitalRead(button);

  display.drawString(40, 0, starAnimation + " anim");
  display.display();
  
  if (pushed == HIGH) {
    Serial.print("pushed!!");
    if (starAnimation == 2) {
      starAnimation = 0;
    } else  {
      starAnimation += 1;
    }
    resetLEDs();
  }

  if (starAnimation == 0) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], HIGH);
    }
  } else if (starAnimation == 1) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], HIGH);
      delay(1000);
      digitalWrite(leds[i], LOW);
    }
  } else if (starAnimation == 2) {
     digitalWrite(leds[2], HIGH);
     delay(1000);
     resetLEDs();
     digitalWrite(leds[1], HIGH);
     digitalWrite(leds[3], HIGH);
     delay(1000);
     resetLEDs();
     digitalWrite(leds[0], HIGH);
     digitalWrite(leds[4], HIGH);
     delay(1000);
     resetLEDs();
  } else {
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], HIGH);
    }
    delay(1000);
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], LOW);
    }
    delay(1000);
  }

  delay(100);
  display.clear();
}

void displayIntroScreen() {
  
}

void resetLEDs() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
}
