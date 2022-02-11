#include "CCTone.h"

CCTone::CCTone(uint8_t pwmPin)
{
    _pwm_pin = pwmPin;
    pinMode(_pwm_pin, OUTPUT);
    setPWM_Frequency(PWM_CLK_FREQ_24M);
}
void CCTone::beep(int16_t frequency, int16_t timeout, int16_t pause)
{
    if (frequency < 200 || frequency > 20000)
    {
        analogWrite(_pwm_pin, 0);
        return;
    }
    uint16_t period = 12000000UL / (uint32_t)frequency;
    uint16_t duty = period >> 1;
    setPWM_ComparePeriod(period); // period
    analogWrite(_pwm_pin, duty);  // duty cycle 50%
    _timeout = millis() + (uint32_t)timeout;
    _pause = _timeout + (uint32_t)pause;
}

bool CCTone::checkInProgress(void)
{
    if (millis() > _timeout)
    {
        analogWrite(_pwm_pin, 0);
        _timeout = 0xFFFFFFFF;
    }
    return millis() < _pause;
}
