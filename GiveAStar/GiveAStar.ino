#include "SH1106Wire.h"
#include "graphics.h"

SH1106Wire display(0x3C, 33, 35);
const int leds[5] = {5, 7, 9, 11, 12};
const int button = 16;

// 0 = no animation, 1 = in order sequence, 2 = pairs (set starting point), 3 = flashing
int starAnimation = 0;

// variables for animation controls
int selectedLED = 0;
bool isFlashing = true;

// timing controls
long interval = 750; // length of animation interval (milliseconds)
long previousMillis = 0;

void setup() {
  Serial.begin(115200);

  // OLED set up with logo
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawXbm(5, 5, logo_width, logo_height, logo);
  display.display();
  display.setTextAlignment(TEXT_ALIGN_CENTER);

  // LED set up
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  pinMode(button, INPUT);
  delay(1000);
  display.clear();
}

void loop() {
  int pushed = digitalRead(button);
  unsigned long currentMillis = millis();

  // button input code (sets animation number)
  if (pushed == HIGH) {

    if (starAnimation == 3) {
      starAnimation = 0;
    } else  {
      starAnimation += 1;
      if (starAnimation == 2) {
        selectedLED = 0;
      }
    }
    
    resetLEDs();
    delay(500);
  }

  if (currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (starAnimation == 0) {
      // Animation 1: All LEDs on
      showStarImage(0);
      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], HIGH);
      }
      
    } else if (starAnimation == 1) {
      // Animation 2: One LED at a time sequence
      showStarImage(1);
      digitalWrite(leds[selectedLED], HIGH);
      digitalWrite(leds[getPrevLED(selectedLED)], LOW);
      selectedLED = getNextLED(selectedLED);
      
    } else if (starAnimation == 2) {
       // Animation 3: LED pairs animation
      showStarImage(2);
      if (selectedLED == 0) {
        digitalWrite(leds[2], HIGH); // top led
      } else if (selectedLED == 1) {
        digitalWrite(leds[1], HIGH); // middle leds
        digitalWrite(leds[3], HIGH);
      } else {
        digitalWrite(leds[0], HIGH); // bottom leds
        digitalWrite(leds[4], HIGH);
      }
      selectedLED = getNextLEDPairs(selectedLED);
      
    } else {
      // Animation 4: Flashing LEDs
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

// Helper Functions

// shows the star graphic indicating animation number
void showStarImage(int animation) {
  display.clear();
  if (animation == 0) {
    display.drawXbm(30, 2, Star_1_width, Star_1_height, Star_1_image);
  } else if (animation == 1) {
    display.drawXbm(30, 2, Star_2_width, Star_2_height, Star_2_image);
  } else if (animation == 2) {
    display.drawXbm(30, 2, Star_3_width, Star_3_height, Star_3_image);
  } else {
    display.drawXbm(30, 2, Star_4_width, Star_4_height, Star_4_image);
  }
  
  display.display();
}

// gets previous LED in sequence
int getPrevLED(int val) {
  if (val == 0) {
    return 4;
  } else {
    return val - 1;
  }
}

// gets next LED in sequence
int getNextLED(int val) {
  if (val == 4) {
    return  0;
  } else {
    return val + 1;
  }
}

// gets next LED pairs in sequence
int getNextLEDPairs(int val) {
  if (val == 2) {
    return 0;
  } else {
    return val + 1;
  }
}

// turns off all LEDs
void resetLEDs() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
}
