/*
 * RGB.c
 *
 *   Created on: Sep 22, 2018
 *      Author: Andy
 */

#include "RGB.h"
#include "Bits.h"
#include "GPIO.h"

void RGB_init(void)
{
	gpio_pin_control_register_t led_config = GPIO_MUX1;
	gpio_pin_control_register_t sw_config = GPIO_MUX1 | GPIO_PE | GPIO_PS;

	GPIO_clock_gating(BLUE_LED_PORT);
	GPIO_clock_gating(RED_LED_PORT);
	GPIO_clock_gating(GREEN_LED_PORT);

	GPIO_clock_gating(SW2_PORT);

	GPIO_set_pin(RED_LED_PORT, RED_LED_PIN);
	GPIO_set_pin(BLUE_LED_PORT, BLUE_LED_PIN);
	GPIO_set_pin(GREEN_LED_PORT, GREEN_LED_PIN);

	GPIO_pin_control_register(BLUE_LED_PORT, BLUE_LED_PIN, &led_config);
	GPIO_pin_control_register(RED_LED_PORT, RED_LED_PIN, &led_config);
	GPIO_pin_control_register(GREEN_LED_PORT, GREEN_LED_PIN, &led_config);

	GPIO_pin_control_register(SW2_PORT, SW2_PIN, &sw_config);

	GPIO_data_direction_pin(BLUE_LED_PORT, GPIO_OUTPUT, BLUE_LED_PIN);
	GPIO_data_direction_pin(RED_LED_PORT, GPIO_OUTPUT, RED_LED_PIN);
	GPIO_data_direction_pin(GREEN_LED_PORT, GPIO_OUTPUT, GREEN_LED_PIN);
}

void RGB_red_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(RED_LED_PORT, RED_LED_PIN);
	}
	else
	{
		GPIO_set_pin(RED_LED_PORT, RED_LED_PIN);
	}

}

void RGB_blue_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(BLUE_LED_PORT, BLUE_LED_PIN);
	}
	else
	{
		GPIO_set_pin(BLUE_LED_PORT, BLUE_LED_PIN);
	}
}

void RGB_green_led_on_off(uint8_t on_off)
{
	if (LED_ON == on_off )
	{
		GPIO_clear_pin(GREEN_LED_PORT, GREEN_LED_PIN);
	}
	else
	{
		GPIO_set_pin(GREEN_LED_PORT, GREEN_LED_PIN);
	}
}

void RGB_off(void)
{
	RGB_blue_led_on_off(LED_OFF);
	RGB_green_led_on_off(LED_OFF);
	RGB_red_led_on_off(LED_OFF);
}
