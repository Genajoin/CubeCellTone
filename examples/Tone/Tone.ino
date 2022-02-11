#include "CCTone.h"

CCTone beeper(PWM2);

void setup() {
  beeper.beep(1000, 5000);
}

void loop() {  
  beeper.checkTimeout();
}