/*
 * RGB.h
 *
 *   Created on: Sep 22, 2018
 *      Author: Andy
 */

#ifndef RGB_H_
#define RGB_H_

#include "stdint.h"
#include "Bits.h"
#include "GPIO.h"


#define LED_ON (0x01u)
#define LED_OFF (0x00)

#define BLUE_LED_PORT  GPIO_B
#define RED_LED_PORT   GPIO_B
#define GREEN_LED_PORT GPIO_E

#define BLUE_LED_PIN  bit_21
#define RED_LED_PIN   bit_22
#define GREEN_LED_PIN bit_26

#define SW2_PORT GPIO_C
#define SW2_PIN bit_6

void RGB_init(void);

void RGB_red_led_on_off(uint8_t on_off);
void RGB_blue_led_on_off(uint8_t on_off);
void RGB_green_led_on_off(uint8_t on_off);

void RGB_red(void);
void RGB_blue(void);
void RGB_green(void);

void RGB_off(void);

#endif /* RGB_H_ */
