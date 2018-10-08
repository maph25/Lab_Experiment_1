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

#define state 0
#define DATA_AVA 0
#define Delay 100000
#define Delay2 300000
#define Delay3 400000
#define SystemClock 21000000

/*PARA LOS CASO DEL MODO 1*/
#define SEG_1_ON 0
#define SEG_1_OFF 1
#define SEG_3_ON 2
#define SEG_1_OFF_2 3

/*PARA LOS CASO DEL MODO 2*/
#define SEG_4_ON 0
#define SEG_4_OFF 1

/*PARA LOS CASO DE MOTOR*/
#define MODE1 0
#define MODE2 1
#define MODE3 2


#define MOTOR_PORT GPIO_B

void Mode1_set_value(void);

void Mode2_set_value(void);

void Mode3_set_value(void);

void ENG_SM_moore(void);

void motor(void);

#endif /* MOTOR_H_ */
