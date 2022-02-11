#include "CCTone.h"

CCTone beeper(PWM2);

void setup()
{
}

void loop()
{
  if (beeper.checkInProgress())
    return;
  beeper.beep(1000, 5000, 1000);
}
