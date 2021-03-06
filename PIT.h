/*
 * PIT.h
 *
 *  Created on: Jan 29, 2015
 *      Author: Luis Pizano
 */

#ifndef PIT_H_
#define PIT_H_


#include "stdint.h"
#include "MK64F12.h"


typedef float My_float_pit_t;

/*! This enumerated constant are used to select the PIT to be used*/
typedef enum {PIT_0,PIT_1,PIT_2,PIT_3} PIT_timer_t;


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 This function configure the PIT to generate a delay base on the system clock.
 	 Internally it configures the clock gating and enables the PIT module.
 	 It is important to note that this strictly is not device driver since everything is
 	 contained in a single function, but in general you have to avoid this practices, this only
 	 for the propose of the homework

 	 \param[in]  portName Port to be configured.
 	 \return void
 */
void PIT_delay(PIT_timer_t pit_timer, My_float_pit_t system_clock , My_float_pit_t delay);

/********************************************************************************************/
/*!
 	 \brief	 This function enable the clock signal of the pit

 	 \param[in]  void.
 	 \return void
 */
void PIT_clock_gating(void);

/********************************************************************************************/
/*!
 	 \brief	It return the status of the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
uint8_t PIT0_get_interrupt_glag_status(void);
/********************************************************************************************/
/*!
 	 \brief	It return the status of the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
uint8_t PIT1_get_interrupt_glag_status(void);
/********************************************************************************************/
/*!
 	 \brief	It return clears the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
void PIT0_clear_interrupt_flag(void);
/********************************************************************************************/
/*!
 	 \brief	It return clears the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
void PIT1_clear_interrupt_flag(void);
/********************************************************************************************/
/*!
 	 \brief	It return clears the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
void PIT_enable(void);

/********************************************************************************************/
/*!
 	 \brief	It return clears the interrupt flag. This flag is a variable created by the programmer.
 	 It is not the flag related with bit TIF in PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;

 	 \param[in]  void.
 	 \return uint8_t flag status
 */
static void PIT_enable_interrupt(PIT_timer_t pit);


#endif /* PIT_H_ */
