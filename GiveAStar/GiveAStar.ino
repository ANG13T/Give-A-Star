#include "SH1106Wire.h"
#include "graphics.h"

// Fix Software at End, increase delays, make text display better, add images to README, make 3 min video for YouTube, publish

SH1106Wire display(0x3C, 33, 35);

const int leds[5] = {5, 7, 9, 11, 12};
const int button = 16;
// 0 = no animation, 1 = in order, 2 = pairs (set starting point), 3 = flashing
int starAnimation = 0;

// Indeces for each animation
int selectedLED2 = 0;
bool isFlashing = true;
int selectedSlide = 0;

long interval = 1000;
long previousMillis = 0;

void setup() {
  Serial.begin(115200);

  // OLED Setup
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawXbm(5, 5, logo_width, logo_height, logo);
  display.display();
  display.setTextAlignment(TEXT_ALIGN_CENTER);

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

  if (pushed == HIGH) {
    Serial.print("inside");
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

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (starAnimation == 0) {
      showStarImage(0);
      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], HIGH);
      }
    } else if (starAnimation == 1) {
      showStarImage(1);
      digitalWrite(leds[selectedLED2], HIGH);
      digitalWrite(leds[getPrevLED(selectedLED2)], LOW);
      selectedLED2 = getNextLED(selectedLED2);
    } else if (starAnimation == 2) {
      showStarImage(2);
      resetLEDs();
      if (selectedLED2 == 0) {
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
      showStarImage(3);
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
  }

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

void showStarImage(int val) {
  display.clear();
  if (val == 0) {
    display.drawXbm(5, 5, Star_1_width, Star_1_height, Star_1_image);
  } else if (val == 1) {
    display.drawXbm(5, 5, Star_2_width, Star_2_height, Star_2_image);
  } else if (val == 2) {
    display.drawXbm(5, 5, Star_3_width, Star_3_height, Star_3_image);
  } else {
    display.drawXbm(5, 5, Star_4_width, Star_4_height, Star_4_image);
  }
  
  display.display();
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
