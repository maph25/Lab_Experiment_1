/*
 * Key.c
 *
 *  Created on: Oct 5, 2018
 *      Author: Andrea Perez ie698276@iteso.mx
 */
#include "Key.h"
#include "GPIO.h"
#include "Bits.h"

uint32_t KEY_get_key(void)
{
	return GPIO_read_port(GPIO_C);
}

uint32_t KEY_decode (uint32_t reading){
	uint32_t Key_val = reading;
	Key_val = Key_val & (KEY_MASK);
switch (Key_val){
    case KEY_ONE:
    	/*Key value return*/
    	return KEY_ONE;
        break;
    case KEY_TWO:
    	/*Key value return*/
    	return KEY_TWO;
        break;
    case KEY_THREE:
    	/*Key value return*/
    	return KEY_THREE;
        break;
    case KEY_FOUR:
    	/*Key value return*/
    	return KEY_FOUR;
        break;
    case KEY_FIVE:
    	/*Key value return*/
    	return KEY_FIVE;
        break;
    case KEY_SIX:
    	/*Key value return*/
    	return KEY_SIX;
        break;
    case KEY_SEVEN:
    	/*Key value return*/
    	return KEY_SEVEN;
        break;
    case KEY_EIGHT:
    	/*Key value return*/
    	return KEY_EIGHT;
        break;
    case KEY_NINE:
    	/*Key value return*/
    	return KEY_NINE;
        break;
    case KEY_ZERO:
    	/*Key value return*/
    	return KEY_ZERO;
        break;
    case KEY_A:
    	/*Key value return*/
    	return KEY_A;
        break;
    case KEY_B:
    	/*Key value return*/
    	return KEY_B;
        break;
    case KEY_C:
    	/*Key value return*/
       	return KEY_C;
           break;
    case KEY_D:
    	/*Key value return*/
       	return KEY_D;
           break;
    case KEY_ASTERISK:
    	/*Key value return*/
    	return KEY_ASTERISK;
        break;
    case KEY_NUM_SMBL:
    	/*Key value return*/
    	return KEY_NUM_SMBL;
        break;
    default:
        return ERROR; /**This value represent key not recognize*/
	}
}


