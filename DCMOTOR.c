/*
 * DCMOTOR.c
 *
 *  Created on: Feb 23, 2022
 *      Author: abdelrahman
 */

#ifndef DCMOTOR_C_
#define DCMOTOR_C_

#include"common_macros.h"
#include"DCMOTOR.h"
#include"gpio.h"
#include "PWM.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void DcMotor_init(void) {
	GPIO_setupPinDirection( DC_PORT, DC_PIN1, PIN_OUTPUT);
	GPIO_setupPinDirection( DC_PORT, DC_PIN2, PIN_OUTPUT);

	GPIO_writePin( DC_PORT, DC_PIN1, LOGIC_LOW);
	GPIO_writePin( DC_PORT, DC_PIN2, LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	if (state == STOP) {
		GPIO_writePin( DC_PORT, DC_PIN1, LOGIC_LOW);
		GPIO_writePin( DC_PORT, DC_PIN2, LOGIC_LOW);
	} else if (state == CLOCK_WISE) {
		GPIO_writePin( DC_PORT, DC_PIN1, LOGIC_LOW);
		GPIO_writePin( DC_PORT, DC_PIN2, LOGIC_HIGH);
	} else if (state == ANTI_CLOCK_WISE) {
		GPIO_writePin( DC_PORT, DC_PIN1, LOGIC_HIGH);
		GPIO_writePin( DC_PORT, DC_PIN2, LOGIC_LOW);
	}
	uint8 duty_cycle = (uint8) ((speed / 100.0f) * 255);
	PWM_Timer0_Start(duty_cycle);

}

#endif /* DCMOTOR_C_ */
