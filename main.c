/**
	\file main.c
	\brief
		This is the source file for the main for Kinetis K64.
		It contains all the initialization and the use of the functions for running the program.
	\author Andrea Perez ie698276@iteso.mx & Fernanda Muñoz ie701371@iteso.mx
	\date	05/Oct/2018
 */
#include <stdio.h>
#include "MK64F12.h"
#include "GPIO.h"
#include "Delay.h"
#include "Key.h"

uint8_t state;
uint8_t digit;
uint8_t slct;
uint8_t password[4];
uint8_t DataAvailable;

#define INITIAL_STATE 0u
#define DGT_ONE 1u
#define DGT_TWO 2u
#define DGT_THREE 3u
#define DGT_FOUR 4u
#define DGT_PASS 5u

int main(void) {
	/*Initialization*/
	/*GPIO_A*/
	GPIO_clock_gating(GPIO_A);
	/*GPIO_B*/
	GPIO_clock_gating(GPIO_B);
	/*GPIO_C*/
	GPIO_clock_gating(GPIO_C);
	/*GPIO_D*/
	GPIO_clock_gating(GPIO_D);
	/*Falling Edge, push button and keyboard*/
	gpio_pin_control_register_t key_config = GPIO_MUX1 | GPIO_PE | GPIO_PS | INTR_FALLING_EDGE;
	GPIO_pin_control_register(GPIO_C, bit_6, &key_config);
	GPIO_pin_control_register(GPIO_C, bit_0, &key_config);
	GPIO_pin_control_register(GPIO_C, bit_5, &key_config);
	GPIO_pin_control_register(GPIO_C, bit_7, &key_config);
	GPIO_pin_control_register(GPIO_C, bit_9, &key_config);
	/*Keyboard and push button set as input*/
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, bit_6);
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, bit_0);
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, bit_5);
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, bit_7);
	GPIO_data_direction_pin(GPIO_C, GPIO_INPUT, bit_9);
	/*External LEDs for Keyboard*/
	GPIO_data_direction_pin(GPIO_A, GPIO_OUTPUT, bit_1);
	GPIO_data_direction_pin(GPIO_A, GPIO_OUTPUT, bit_2);
	/*External LEDs for Motor*/
	GPIO_data_direction_pin(GPIO_D, GPIO_OUTPUT, bit_3);
	GPIO_data_direction_pin(GPIO_D, GPIO_OUTPUT, bit_1);
	/*External LEDs for signal*/
	GPIO_data_direction_pin(GPIO_A, GPIO_OUTPUT, bit_3);
	GPIO_data_direction_pin(GPIO_A, GPIO_OUTPUT, bit_1);
	/*Motor*/
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT,bit_9);
	/*SIGNAL*/
	GPIO_data_direction_pin(GPIO_B, GPIO_OUTPUT,bit_9);


    while(1) {
    	for(state = 0; state > DGT_FOUR; state ++){
    		if(state > DGT_FOUR){
    				state = INITIAL_STATE;
    			}
    			else{
    				DataAvailable = GPIO_get_flag();
    			state = DGT_ONE;
    			switch (state) {
    				case DGT_ONE:
    					if(DataAvailable == TRUE)
    					{
    						digit = KEY_get_key();
    						password[0] = KEY_decode(digit);
    						state = DGT_TWO;
    					}
    					break;
    				case DGT_TWO:
    					if(DataAvailable == TRUE)
    					{
    						digit = KEY_get_key();
    						password[1] = KEY_decode(digit);
    						state = DGT_THREE;
    					}
    					break;
    				case DGT_THREE:
    					if(DataAvailable == TRUE)
    					{
    						digit = KEY_get_key();
    						password[2] = KEY_decode(digit);
    						state = DGT_FOUR;
    					}
    					break;
    				case DGT_FOUR:
    					if(DataAvailable == TRUE)
    					{
    						digit = KEY_get_key();
    						password[3] = KEY_decode(digit);
    						state = DGT_PASS;
    					}
    					break;
    				case DGT_PASS:
    					if (password[0] == KEY_ONE && password[1] == KEY_TWO && password[2] == KEY_THREE && password[3] == KEY_FOUR){
    						GPIO_toogle_pin(GPIO_A, bit_2); /**Turn on correct password led*/
    						digit = KEY_get_key();
    						slct = KEY_decode(digit);
    						switch(slct){
    							case KEY_A:
    								GPIO_toogle_pin(GPIO_A, bit_2); /**Turn on correct password led*/
    								break;
    							case KEY_B:
    								GPIO_toogle_pin(GPIO_A, bit_2); /**Turn on correct password led*/
    								break;
    							default:
    								break;
    							/*ERROR*/
    						}
    					}
    					else if(password[0] == KEY_FOUR && password[1] == KEY_FIVE && password[2] == KEY_SIX && password[3] == KEY_SEVEN){
    							GPIO_toogle_pin(GPIO_A, bit_2); /**Turn on correct password led*/
    							motor();
					}
    					else if(password[0] == KEY_SEVEN && password[1] == KEY_EIGHT && password[2] == KEY_NINE && password[3] == KEY_ZERO){
    							GPIO_toogle_pin(GPIO_A, bit_2); /**Turn on correct password led*/
    					}
    				/*ERROR*/
    				default:
    					break;

    			}
    		}/*Else*/

    	}/*For*/

    }/*While*/
    return 0 ;
}
