
#include "PIT.h"
#include "Bits.h"

static uint8_t g_pit_intr_flag = FALSE;


void PIT0_IRQHandler()
{
	volatile uint32_t dummyRead;

	PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;
	dummyRead = PIT->CHANNEL[0].TCTRL;	//read control register for clear PIT flag, this is silicon bug

	PIT->CHANNEL[0].TCTRL &= ~(PIT_TCTRL_TIE_MASK);//enables PIT timer interrupt
	PIT->CHANNEL[0].TCTRL &= ~(PIT_TCTRL_TEN_MASK);//enables timer0

	g_pit_intr_flag = TRUE;
}


void PIT_delay(PIT_timer_t pit_timer,My_float_pit_t system_clock , My_float_pit_t delay)
{
	uint32_t LDVAL = 0;
	My_float_pit_t clock_period = 0.0F;
	system_clock = system_clock /2;
	clock_period = (1/system_clock);
	LDVAL = (uint32_t)(delay / clock_period);
	LDVAL = LDVAL - 1;

	//PIT->MCR  &= ~PIT_MCR_MDIS_MASK;//turns on PIT
	//PIT->MCR  |= PIT_MCR_FRZ_MASK;

	switch(pit_timer)
	{
	case PIT_0:
		PIT->CHANNEL[0].LDVAL = LDVAL;
		PIT_enable_interrupt(PIT_0);
		break;

	default:
		PIT->CHANNEL[0].LDVAL = LDVAL;
		PIT_enable_interrupt(PIT_0);
		break;
	}


}


void PIT_enable(void)
{
	PIT->MCR  |= PIT_MCR_FRZ_MASK;
	PIT->MCR &= ~PIT_MCR_MDIS_MASK; /* Enable PIT*/
}

static void PIT_enable_interrupt(PIT_timer_t pit)
{
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK;//enables PIT timer interrupt
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK;//enables timer0
}

void PIT_clock_gating(void)
{
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
}

uint8_t PIT_get_interrupt_glag_status(void)
{
	return(g_pit_intr_flag);
}

void PIT_clear_interrupt_flag(void)
{
	g_pit_intr_flag = FALSE;
}

