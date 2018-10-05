/**
	\file
	\brief
		This is the source file for the GPIO device driver for Kinetis K64.
		It contains all the implementation for configuration functions and runtime functions.
		i.e., this is the application programming interface (API) for the GPIO peripheral.
	\author Andrea Perez ie698276@iteso.mx & Fernanda Muñoz ie701371@iteso.mx
	\date	05/Oct/2018
 */

#include "MK64F12.h"
#include "GPIO.h"

static uint8_t FlagPortC;
static uint8_t SW_2;

uint8_t GPIO_get_flag(){
	return FlagPortC = FALSE;
}

void PORTC_IRQHandler(){
		uint32_t port_value;
		port_value = GPIOC->PDIR;

		if(port_value == SW2)
		{
			SW_2 = TRUE;
			GPIO_clear_interrupt(GPIO_C);
		}
		else{
			FlagPortC = TRUE;
			GPIO_clear_interrupt(GPIO_C);
		}
}

void GPIO_clear_interrupt(gpio_port_name_t portName)
{
	switch(portName)/** Selecting the GPIO for clock enabling*/
	{
		case GPIO_A: /** GPIO A is selected*/
			PORTA->ISFR = CLEAR;
			break;
		case GPIO_B: /** GPIO B is selected*/
			PORTB->ISFR = CLEAR;
			break;
		case GPIO_C: /** GPIO C is selected*/
			PORTC->ISFR = CLEAR;
			break;
		case GPIO_D: /** GPIO D is selected*/
			PORTD->ISFR = CLEAR;
			break;
		default: /** GPIO E is selected*/
			PORTE->ISFR = CLEAR;
			break;

	}// end switch
}
uint8_t GPIO_clock_gating(gpio_port_name_t portName)
{
	switch(portName)/** Selecting the GPIO for clock enabling*/
			{
				case GPIO_A: /** GPIO A is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA; /** Bit 9 of SIM_SCGC5 is  set*/
					break;
				case GPIO_B: /** GPIO B is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTB; /** Bit 10 of SIM_SCGC5 is set*/
					break;
				case GPIO_C: /** GPIO C is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTC; /** Bit 11 of SIM_SCGC5 is set*/
					break;
				case GPIO_D: /** GPIO D is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTD; /** Bit 12 of SIM_SCGC5 is set*/
					break;
				case GPIO_E: /** GPIO E is selected*/
					SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTE; /** Bit 13 of SIM_SCGC5 is set*/
					break;
				default: /**If doesn't exist the option*/
					return(FALSE);
			}// end switch
	/**Successful configuration*/
	return(TRUE);
}// end function

uint8_t GPIO_pin_control_register(gpio_port_name_t portName, uint8_t pin,const gpio_pin_control_register_t*  pinControlRegister)
{
	switch(portName)
		{
		case GPIO_A:/** GPIO A is selected*/
			PORTA->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_B:/** GPIO B is selected*/
			PORTB->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_C:/** GPIO C is selected*/
			PORTC->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_D:/** GPIO D is selected*/
			PORTD->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_E: /** GPIO E is selected*/
			PORTE->PCR[pin]= *pinControlRegister;
		default:/**If doesn't exist the option*/
			return(FALSE);
		break;
		}
	/**Successful configuration*/
	return(TRUE);
}

void GPIO_write_port(gpio_port_name_t portName, uint32_t data)
{
	switch(portName)
	{
		case GPIO_A: /**GPIO A is selected*/
			GPIOA->PDOR = data;
			break;
		case GPIO_B: /**GPIO B is selected*/
			GPIOB->PDOR = data;
			break;
		case GPIO_C: /**GPIO C is selected*/
			GPIOC->PDOR = data;
			break;
		case GPIO_D: /**GPIO D is selected*/
			GPIOD->PDOR = data;
			break;
		case GPIO_E: /**GPIO E is selected*/
			GPIOE->PDOR = data;
			break;
	}
}
uint32_t GPIO_read_port(gpio_port_name_t portName)
{
	switch(portName)
	{
		case GPIO_A:/** GPIO A is selected*/
			return GPIOA->PDIR;
			break;
		case GPIO_B:/** GPIO B is selected*/
			return GPIOB->PDIR;
			break;
		case GPIO_C:/** GPIO C is selected*/
			return GPIOC->PDIR;
			break;
		case GPIO_D:/** GPIO D is selected*/
			return GPIOD->PDIR;
			break;
		case GPIO_E: /** GPIO E is selected*/
			return GPIOE->PDIR;
		default:/**If doesn't exist the option*/
			return(FALSE);
		break;
	}
	/**Successful configuration*/
	return(TRUE);
}

uint8_t GPIO_read_pin(gpio_port_name_t portName, uint8_t pin)
{
	switch(portName)
	{
		case GPIO_A:/** GPIO A is selected*/
			GPIOA->PDDR &=~ (ONE << pin);
			break;
		case GPIO_B:/** GPIO B is selected*/
			GPIOB->PDDR &=~ (ONE << pin);
			break;
		case GPIO_C:/** GPIO C is selected*/
			GPIOC->PDDR &=~ (ONE << pin);
			break;
		case GPIO_D:/** GPIO D is selected*/
			GPIOD->PDDR &=~ (ONE << pin);
			break;
		case GPIO_E: /** GPIO E is selected*/
			GPIOE->PDDR &=~ (ONE << pin);
			break;
		default:/**If doesn't exist the option*/
			return(FALSE);
			break;
	}
	/**Successful configuration*/
	return(TRUE);
}

void GPIO_set_pin(gpio_port_name_t portName, uint8_t pin)
{
	switch(portName)
	{
		case GPIO_A: /**GPIO A is selected*/
			GPIOA->PSOR |= (ONE << pin);
			 break;
		case GPIO_B: /**GPIO B is selected*/
			GPIOB->PSOR |= (ONE << pin);
		 	break;
		case GPIO_C: /**GPIO C is selected*/
			GPIOC->PSOR |= (ONE << pin);
			 break;
		case GPIO_D: /**GPIO D is selected*/
			GPIOD->PSOR |= (ONE << pin);
			break;
		case GPIO_E: /**GPIO E is selected*/
			GPIOE->PSOR |= (ONE << pin);
			break;
	}
}

void GPIO_clear_pin(gpio_port_name_t portName, uint8_t pin)
{
	switch(portName)
	{
		case GPIO_A: /**GPIO A is selected*/
			GPIOA-> PCOR |= (ONE << pin);
			 break;
		case GPIO_B: /**GPIO B is selected*/
			GPIOB-> PCOR |= (ONE << pin);
		 	break;
		 case GPIO_C: /**GPIO C is selected*/
			 GPIOC-> PCOR |= (ONE << pin);
			 break;
		 case GPIO_D: /**GPIO D is selected*/
			 GPIOD-> PCOR |= (ONE << pin);
			break;
		 case GPIO_E: /**GPIO E is selected*/
			 GPIOE-> PCOR |= (ONE << pin);
			 break;
	}
}

void GPIO_toogle_pin(gpio_port_name_t portName, uint8_t pin)
{
	switch(portName)
	{
		 case GPIO_A: /**GPIO A is selected*/
			GPIOA-> PTOR = (ONE << pin);
			break;
		 case GPIO_B: /**GPIO B is selected*/
			 GPIOB-> PTOR = (ONE << pin);
		 	break;
		 case GPIO_C: /**GPIO C is selected*/
			 GPIOC-> PTOR = (ONE << pin);
			 break;
		 case GPIO_D: /**GPIO D is selected*/
			 GPIOD-> PTOR = (ONE << pin);
			break;
		 case GPIO_E: /**GPIO E is selected*/
			 GPIOE-> PTOR = (ONE << pin);
			 break;
	}
}

void GPIO_data_direction_port(gpio_port_name_t portName ,uint32_t direction)
{
	switch(portName)
	{
	 	 case GPIO_A: /**GPIO A is selected*/
	 		GPIOA-> PDDR = direction;
	 		 break;
	 	 case GPIO_B: /**GPIO B is selected*/
	 		GPIOB-> PDDR = direction;
		 	 break;
	 	 case GPIO_C: /**GPIO C is selected*/
	 		GPIOC-> PDDR = direction;
	 		 break;
	 	 case GPIO_D: /**GPIO D is selected*/
	 		GPIOD-> PDDR = direction;
	 		 break;
	 	 case GPIO_E: /**GPIO E is selected*/
	 		GPIOE-> PDDR = direction;
	 		 break;
	}
}

void GPIO_data_direction_pin(gpio_port_name_t portName, uint8_t state, uint8_t pin)
{
	switch(portName)
	{
		case GPIO_A: /**GPIO A is selected*/
			GPIOA-> PDDR |= (state << pin);
			break;
		case GPIO_B: /**GPIO B is selected*/
			GPIOB-> PDDR |= (state << pin);
			break;
		case GPIO_C: /**GPIO C is selected*/
			GPIOC-> PDDR |= (state << pin);
			break;
		case GPIO_D: /**GPIO D is selected*/
			GPIOD-> PDDR |= (state << pin);
			break;
		case GPIO_E: /**GPIO E is selected*/
			GPIOE-> PDDR |= (state << pin);
			break;
	}
}


