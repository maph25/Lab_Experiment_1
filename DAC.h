/*
 * DAC.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Andrea Perez, Sandra Fernanda
 */

#ifndef DAC_H_
#define DAC_H_

#include "GPIO.h"
#include "PIT.h"
#include "Bits.h"
#include "Delay.h"
#include "RGB.h"

/**/
#define SET_PIT 4
/**/
#define SQ_ON 0
#define SINE_ON 1
#define TRI_ON 2
/**/
#define SQ 0
#define SINE 1
#define TRI 2

void DAC_clock_gating(void);

void sine_led();
void square_led();
void triangular_led();

void Square_gen();
void Sine_gen();
void Triangular_gen();

void wave_gen();
#endif /* DAC_H_ */
