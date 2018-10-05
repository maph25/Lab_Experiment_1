/*
 * Keys.h
 *
 *  Created on: Sep 22, 2018
 *      Author: Andrea Perez ie698276@iteso.mx
 */
#ifndef KEYS_H_
#define KEYS_H_

#include "GPIO.h"
#include "Bits.h"

#define KEY_ONE 0x00 /*!< Key 1 hex value decoder reading*/
#define KEY_TWO 0x01 /*!< Key 2 hex value decoder reading*/
#define KEY_THREE 0x02 /*!< Key 3 hex value decoder reading*/
#define KEY_FOUR 0x04/*!< Key 4 hex value decoder reading*/
#define KEY_FIVE 0x05 /*!< Key 5 hex value decoder reading*/
#define	KEY_SIX 0x06 /*!< Key 6 hex value decoder reading*/
#define KEY_SEVEN 0x08 /*!< Key 7 hex value decoder reading*/
#define KEY_EIGHT 0x09 /*!< Key 8 hex value decoder reading*/
#define KEY_NINE 0x0A /*!< Key 9 hex value decoder reading*/
#define KEY_ZERO 0x0D /*!< Key 0 hex value decoder reading*/
#define KEY_A 0x03 /*!< Key A hex value decoder reading*/
#define KEY_B 0x07 /*!< Key B hex value decoder reading*/
#define KEY_C 0x0B /*!< Key C hex value decoder reading*/
#define KEY_D 0x0F /*!< Key D hex value decoder reading*/
#define KEY_NUM_SMBL 0x0E /*!< Key "#" hex value decoder reading*/
#define KEY_ASTERISK 0x0C /*!< Key "*" hex value decoder reading*/
#define ERROR 0xFF
#define KEY_MASK 0x02A1 /**Mask to read the keyboard without the SW*/

uint32_t KEY_get_key(void);
/**
	 * This function reads the value of the entire port*/


uint32_t KEY_decode (uint32_t reading);

#endif /* KEYS_H_ */
