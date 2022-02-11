#ifndef CCTONE_H
#define CCTONE_H

#include <Arduino.h>

class CCTone
{
public:
    //------------------------------------ Constructor ------------------------------------//
    CCTone(uint8_t pwmPin);
    //------------------------------- Public functions -----------------------------------//

    void beep(uint32_t frequency, uint32_t timeout);
    bool checkTimeout(void);
    //------------------------------- Public variables -----------------------------------//
private:
    uint8_t _pwm_pin;
    uint32_t _timeout;
    uint32_t _getPwmFrequencyType(uint32_t frequency);
};

#endif