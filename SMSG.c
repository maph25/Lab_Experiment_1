/*
 * SG.c
 *
 *  Created on: Sep 25, 2018
 *      Author: LuisFernando
 */
#include "SMSG.h"
#include "stdint.h"
#include "NVIC.h"

#define SQUARE 0
#define SINE 1
#define TRI 2

uint8_t FlagPortA = FALSE;

typedef struct
{
	void(*fptrSignal)(void);
	uint8_t next[3];
}State_t;

const State_t FSM_Moore[3]=
{
		{
				DAC_set_value_square,{SQUARE,SINE,TRI}
		},
		{
				DAC_set_value_sine,{SQUARE,SINE,TRI}
		},
		{
				DAC_set_value_tri,{SQUARE,SINE,TRI}
		}
};

void DAC_SM_moore(void)
{
	static uint8_t statePortA = 0;
	static uint8_t counter = 0;
	/**/
	static uint8_t currentState = SQUARE;
	FSM_Moore[currentState].fptrSignal();
	if(TRUE == GPIO_get_IRQ_status(GPIO_A))
	{
		if(!statePortA)
		{
			currentState = FSM_Moore[currentState].next[counter];
			counter++;
			if(counter>3)
				counter = 0;
		}
		else
		{
			currentState = FSM_Moore[currentState].next[counter];
		}
		statePortA = !statePortA;
		GPIO_clear_IRQ_status(GPIO_A);
	}
}
