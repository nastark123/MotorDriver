#include "pwm.h"

void init_pwm_single(uint16_t per) {
	// set single mode
	TCA0.SINGLE.CTRLD &= ~TCA_SINGLE_SPLITM_bm;
	// initialize the period register to the appropriate value
	TCA0.SINGLE.PER = per;
	// clear the comparison registers
	// these can be written later using pwm_single_write
	TCA0.SINGLE.CMP0 = 0;
	TCA0.SINGLE.CMP1 = 0;
	TCA0.SINGLE.CMP2 = 0;
	// clear count register
	TCA0.SINGLE.CNT = 0;
	// enable PWM
	TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm;
	TCA0.SINGLE.CTRLA = TCA_SPLIT_ENABLE_bm;
}

void init_pwm_split(uint8_t h_per, uint8_t l_per) {
	// set split mode
	TCA0.SINGLE.CTRLD |= TCA_SINGLE_SPLITM_bm;
	// initialize period registers to the appropriate value
	TCA0.SPLIT.HPER = h_per;
	TCA0.SPLIT.LPER = l_per;
	// clear comparison registers
	// these can be written later using pwm_single_write
	TCA0.SPLIT.HCMP0 = 0;
	TCA0.SPLIT.LCMP0 = 0;
	TCA0.SPLIT.HCMP1 = 0;
	TCA0.SPLIT.LCMP1 = 0;
	TCA0.SPLIT.HCMP2 = 0;
	TCA0.SPLIT.LCMP2 = 0;
	// clear count registers
	TCA0.SPLIT.HCNT = 0;
	TCA0.SPLIT.LCNT = 0;
	// enable PWM
	TCA0.SPLIT.CTRLB = TCA_SPLIT_HCMP0EN_bm | TCA_SPLIT_LCMP0EN_bm;
	TCA0.SPLIT.CTRLA = TCA_SPLIT_ENABLE_bm;
}

void pwm_single_write(uint16_t thresh) {
	
}

void pwm_split_write_high(uint8_t h_thresh) {
	
}

void pwm_split_write_low(uint8_t l_thresh) {
	
}