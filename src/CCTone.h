#ifndef CCTONE_H
#define CCTONE_H

#include <Arduino.h>

class CCTone
{
public:
    //------------------------------------ Constructor ------------------------------------//
    CCTone(uint8_t pwmPin);
    //------------------------------- Public functions -----------------------------------//

    void beep(int16_t frequency, int16_t timeout, int16_t pause);
    bool checkInProgress(void);
    //------------------------------- Public variables -----------------------------------//
private:
    uint8_t _pwm_pin;
    uint32_t _timeout = 0;
    uint32_t _pause = 0;
    uint32_t _getPwmFrequencyType(uint32_t frequency);
};

#endif