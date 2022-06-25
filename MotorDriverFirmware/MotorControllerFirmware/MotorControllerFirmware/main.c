/*
 * MotorControllerFirmware.c
 *
 * Created: 6/23/2022 5:41:19 PM
 * Author : Nathan Stark
 */ 

#include <avr/io.h>

int main(void) {

	// enable split mode for timer
	TCA0.SINGLE.CTRLD = TCA_SINGLE_SPLITM_bm;
	// TODO find out system clock and adjust this accordingly
	// assuming we use a 1 MHz clock, this will set the PWM frequency to 5 kHz
	TCA0.SPLIT.HPER = 199;
	TCA0.SPLIT.LPER = 199;
	// example duty cycle setting, set 50% on high timer, 25% on low
	TCA0.SPLIT.HCMP0 = 100;
	TCA0.SPLIT.LCMP0 = 50;
	// clear the counts in both timer's count register
	TCA0.SPLIT.HCNT = 0;
	TCA0.SPLIT.LCNT = 0;
	// enable PWM outputs
	TCA0.SPLIT.CTRLB = TCA_SPLIT_HCMP0EN_bm | TCA_SPLIT_LCMP0EN_bm;
	TCA0.SPLIT.CTRLA = TCA_SPLIT_ENABLE_bm;
    
}

