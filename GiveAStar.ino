#include "SH1106Wire.h"

SH1106Wire display(0x3C, 33, 35);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  display.init();
  display.drawString(5, 44, "Give A Star!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
