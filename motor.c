

#include "Motor.h"
#include "stdint.h"
#include "Delay.h"
#include "Bits.h"
#include "PIT.h"
#include "RGB.h"
#include "GPIO.h"

#define state 0
#define DATA_AVA 0
#define Delay 100000
#define Delay2 300000
#define Delay3 400000

uint8_t g_state = SET_DELAY;



void Mode1_set_value(void){
	DATA_AVA = PIT_get_flag();


	switch(state)
	{
	case SET_DELAY:
		pit_delay(PIT_0,system_clock,Delay);
		g_state = SEG_1_ON;
		break;
	case SEG_1_ON:
		if(DATA_AVA == TRUE)
		{
		GPIO_set_pin(GPIO_B, bit_9);
		g_state = SEG_1_OFF;
		GPIO_clear_interrupt(GPIO_B, bit_9);
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
		pit_delay(PIT_0,system_clock,Delay2);
		GPIO_set_pin(GPIO_B, bit_9);
		g_state = SEG_1_OFF_2;

		}
	break;

	case SEG_1_OFF_2:
		if(DATA_AVA == TRUE)
		{
		GPIO_clear_pin(GPIO_B, bit_9); //SE MANTIENE APAGADO EL PUERTO
		g_state = SEG_1_ON; //REGRESA AL INICIO DEL CICLO /O VOLVER AL CASO DEFAULT?
		}
	break;

	default:
	break;
	}
//poner clear de flag
}

void Mode2_set_value(void){
	DATA_AVA = PIT_get_flag();

switch(DATA_AVA)
		{

	 case SET_DELAY:
		pit_delay(PIT_0,system_clock,Delay);
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
			GPIO_clear_interrupt(GPIO_B, bit_9);
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

	uint8 DATA_AVAILABLE = GPIO_get_flag();

		switch (state) {
			case MODE1:
				Mode1_set_value();
				if(DATA_AVAILABLE == TRUE)
				{
					state = MODE2;
					g_state = SET_DELAY;
				}

				break;
			case MODE2:
				Mode2_set_value();
				if(DATA_AVAILABLE == TRUE)
				{
					state = MODE3;
					g_state = SET_DELAY;
				}
				break;

			case MODE3:
				GPIO_clear_interrupt(GPIO_B,bit_9);
				if(DATA_AVAILABLE == TRUE)
				{
					state = MODE1;
				}
				break;

			default:
				break;
		}
}




