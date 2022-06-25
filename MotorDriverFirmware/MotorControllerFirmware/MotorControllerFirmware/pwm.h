#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

// TODO allow for changing of output pins?

void init_pwm_single(uint16_t per);

void init_pwm_split(uint8_t h_per, uint8_t l_per);

void pwm_single_write(uint16_t thresh);

void pwm_split_write_high(uint8_t h_thresh);

void pwm_split_write_low(uint8_t l_thresh);

#endif