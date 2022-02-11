#include "CCTone.h"

CCTone::CCTone(uint8_t pwmPin)
{
    _pwm_pin = pwmPin;
    pinMode(_pwm_pin, OUTPUT);
    setPWM_Frequency(PWM_CLK_FREQ_24M);
}
void CCTone::beep(uint32_t frequency, uint32_t timeout)
{
    if (frequency < 200 || frequency > 20000)
    {
        analogWrite(_pwm_pin, 0);
        return;
    }
    uint16_t period = 12000000UL / frequency;
    uint16_t duty = period >> 1;
    setPWM_ComparePeriod(period); // period
    analogWrite(_pwm_pin, duty);  // duty cycle 50%
    _timeout = millis() + timeout;
}

bool CCTone::checkTimeout(void)
{
    bool res = millis() > _timeout;
    if (!res)
    {
        analogWrite(_pwm_pin, 0);
        _timeout = 0xFFFFFFFF;
    }
    return res;
}
