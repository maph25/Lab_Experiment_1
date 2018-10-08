/*
 * motor.c
 *
 *  Created on: Oct 5, 2018
 *      Author: Fernanda Muñoz ie701371@iteso.mx
 */

#include "motor.h"
#include "stdint.h"
#include "Delay.h"
#include "Bits.h"
#include "PIT.h"
#include "RGB.h"
#include "GPIO.h"

uint8_t g_state = SET_DELAY;
uint8_t DATA_AVA;
static uint8_t state;


void Mode1_set_value(void){
	DATA_AVA = PIT_get_interrupt_glag_status(); //recibe la señal de la interrupción


	switch(state)
	{
	case SET_DELAY:
		PIT_delay(PIT_0,SystemClock,Delay);//determina duración de 1 segundo para la interrupcion
		g_state = SEG_1_ON;
		break;
	case SEG_1_ON:
		if(DATA_AVA == TRUE)
		{
		GPIO_set_pin(GPIO_B, bit_9); //prende el puerto y le manda la interrupción??
		g_state = SEG_1_OFF;
		}
	break;

	case SEG_1_OFF:
		if(DATA_AVA == TRUE)
		{
		GPIO_clear_pin(GPIO_B, bit_9); //SE MANTIENE APAGADO EL PUERTO
		g_state = SEG_3_ON;
		}
	break;

	case SEG_3_ON:
		if(DATA_AVA == TRUE)
		{
		PIT_delay(PIT_0,SystemClock,Delay2);//cambia el tiempo de la interrupción a 3 segundos
		GPIO_set_pin(GPIO_B, bit_9);
		g_state = SEG_1_OFF_2;

		}
	break;

	case SEG_1_OFF_2:
		if(DATA_AVA == TRUE)
		{
		PIT_delay(PIT_0,SystemClock,Delay); //REGRESA AL DELAY DE 1 SEGUNDO
		GPIO_clear_pin(GPIO_B, bit_9); //SE MANTIENE APAGADO EL PUERTO
		g_state = SEG_1_ON; //REGRESA AL INICIO DEL CICLO /O VOLVER AL CASO DEFAULT?
		}
	break;

	default:
	break;
	}
	PIT_clear_interrupt_flag(); //LIMPIA LA BANDERA PARA LA INTERRUPCIÓN
}

void Mode2_set_value(void){
	DATA_AVA = PIT_get_interrupt_glag_status();

switch(DATA_AVA)
		{

	 case SET_DELAY:
		PIT_delay(PIT_0,SystemClock, Delay3); //DELAY DE 4 SEGUNDOS
		g_state = SEG_4_ON;
		break;
	case SEG_4_ON:
		if(DATA_AVA == TRUE)
		{
			GPIO_set_pin(GPIO_B, bit_9);
			g_state = SEG_4_OFF;

		}
	break;

	case SEG_4_OFF:
		if(DATA_AVA == TRUE)
		{
			GPIO_clear_interrupt(GPIO_B);
			g_state = SEG_4_ON;
		}
	break;

	default:

	break;


}

/*void Mode3_set_value(void){
	DATA_AVA = PIT_get_flag();
	GPIO_clear_interrupt(GPIO_B, BIT_9); //SE MANTIENE APAGADO EL PUERTO
	//off
}*/



void motor(){

	uint8_t DATA_AVAILABLE = GPIO_get_flag();

		switch (state) {
			case MODE1:
				Mode1_set_value();
				if(DATA_AVAILABLE == TRUE)
				{
					state = MODE2;
					g_state = SET_DELAY;
					GPIO_toogle_pin(GPIO_D, bit_1);
					GPIO_clear_pin(GPIO_D, bit_3);

				}

				break;
			case MODE2:
				Mode2_set_value();
				if(DATA_AVAILABLE == TRUE)
				{
					state = MODE3;
					g_state = SET_DELAY;
					GPIO_toogle_pin(GPIO_D, bit_3);
					GPIO_clear_pin(GPIO_D, bit_1);

				}
				break;

			case MODE3:
				GPIO_clear_interrupt(GPIO_B);
				if(DATA_AVAILABLE == TRUE)
				{
					state = MODE1;
				}
				break;

			default:
				break;
		}
	}
}
