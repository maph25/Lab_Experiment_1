/*
 * SG.h
 *
 *  Created on: Sep 25, 2018
 *      Author: LuisFernando
 */

#ifndef SMSG_H_
#define SMSG_H_

#include "MK64F12.h"
#include "GPIO.h"
#include "Bits.h"
#include "PIT.h"
#include "NVIC.h"
#include "DAC.h"
#include "RGB.h"

#define LED_PORT GPIO_D

void DAC_SM_moore(void);

#endif /* SMSG_H_ */
