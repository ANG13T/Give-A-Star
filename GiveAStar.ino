#include "SH1106Wire.h"
#include "graphics.h"

// 1. Finish Image, Fix Push Button Input, Make Text Slideshow, Make Animations, Make Schematic, Print PCB

SH1106Wire display(0x3C, 33, 35);

const int leds[5] = {3, 5, 7, 9, 11};
const String text[4] = {"Hello World", "You are Really Awesome", "Jshddsj dsahjdaskhjd dashdasjkhdjas dashdasjkhdsaj adshdaskjhdsaj daskjadshjkdas"};
const int button = 16;
// 0 = no animation, 1 = in order, 2 = pairs (set starting point), 3 = flashing
int starAnimation = 0;

const unsigned long eventTime_1_LEDs = 1000; // interval in ms
int selectedLED = 0;
const unsigned long eventTime_2_screen = 10;
const unsigned long eventTime_3_button = 10;

unsigned long previousTime_1 = 0;
unsigned long previousTime_2 = 0;
unsigned long previousTime_3 = 0;

// Indeces for each animation
int selectedLED2 = 0;
bool isFlashing = true;

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
  unsigned long currentTime = millis();

  if (currentTime - previousTime_3 >= eventTime_3_button) {
    int pushed = digitalRead(button);

    if (pushed == HIGH) {
      if (starAnimation == 3) {
        starAnimation = 0;
      } else  {
        starAnimation += 1;
        if (starAnimation == 2) {
          selectedLED2 = 0;
        }
      }
      resetLEDs();
      delay(500);
    }
    previousTime_3 = currentTime;
  }

  if (currentTime - previousTime_1 >= eventTime_1_LEDs) {
    if (starAnimation == 0) {
      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], HIGH);
      }
    } else if (starAnimation == 1) {
        digitalWrite(leds[selectedLED2], HIGH);
        digitalWrite(leds[getPrevLED(selectedLED2)], LOW);
        selectedLED2 = getNextLED(selectedLED2);
    } else if (starAnimation == 2) {
       resetLEDs();
      if(selectedLED2 == 0) {
        digitalWrite(leds[2], HIGH);
      } else if (selectedLED2 == 1) {
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[3], HIGH);
      } else {
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[4], HIGH);
      }
      selectedLED2 = getNextLEDPairs(selectedLED2);
    } else {
      if (isFlashing) {
        for (int i = 0; i < 5; i++) {
          digitalWrite(leds[i], HIGH);
        }
      } else {
        for (int i = 0; i < 5; i++) {
          digitalWrite(leds[i], LOW);
        }
      }
      isFlashing = !isFlashing;
    }

    previousTime_1 = currentTime;
  }

  if (currentTime - previousTime_2 >= eventTime_2_screen) {
    display.clear();
    if (starAnimation == 0) {
      display.drawString(40, 0, "Plain Animation");
    } else if (starAnimation == 1) {
      display.drawString(40, 0, "In Order Animation");
    } else if (starAnimation == 2) {
      display.drawString(40, 0, "Pairs Animation");
    } else {
      display.drawString(40, 0, "Flashing");
    }
    
    display.display();

    previousTime_2 = currentTime;
  }

}

void displayIntroScreen() {

}

int getPrevLED(int val) {
  if (val == 0) {
    return 4;
  } else {
    return val - 1;
  }
}

int getNextLED(int val) {
  if (val == 4) {
    return  0;
  } else {
    return val + 1;
  }
}

int getNextLEDPairs(int val) {
  if (val == 2) {
    return 0;  
  } else {
    return val + 1;  
  } 
}

void resetLEDs() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
}
