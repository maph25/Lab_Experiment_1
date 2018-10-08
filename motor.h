/*
 * motor.h
 *
 *  Created on: Oct 8, 2018
 *      Author: Fernanda Muñoz ie701371@iteso.mx
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "GPIO.h"
#include "PIT.h"
#include "Bits.h"
#include "Delay.h"

#define MOTOR_PORT GPIO_B

void Mode1_set_value(void);

void Mode2_set_value(void);

void Mode3_set_value(void);

void ENG_SM_moore(void);

void motor(void);

#endif /* MOTOR_H_ */
