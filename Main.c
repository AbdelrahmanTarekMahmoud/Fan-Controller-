/*
 * Main.c
 *
 *  Created on: Feb 23, 2022
 *      Author: abdelrahman
 */

#include "ADC.h"
#include "LCD.h"
#include "DCMOTOR.h"
#include "gpio.h"
#include "lm35_sensor.h"
#include "PWM.h"
#include "avr/io.h"

int main() {
	ADC_ConfigType ConfigType = { INTERNAL_REFERENCE_VOLTAGE, F_CPU_8 };
	/* Initialize LCD,ADC and DCmotor */
	LCD_init();
	DcMotor_init();
	ADC_init(&ConfigType);
	LCD_displayString("FAN is      ");
	LCD_moveCursor(1, 0);
	LCD_displayString("Temp =      C ");
	uint16 Temperature; /* delcaring variable to store LMSENSOR value in it*/
	uint8 state = STOP; /* delcaring variable to store DCMOTOR STATE value in it*/
	uint16 speed = 0;/* delcaring variable to store Speed value in it*/
	while (1) {
		Temperature = LM35_getTemperature(); /*recieving sensor value */
		if (Temperature < 30) {
			LCD_moveCursor(0, 7);
			LCD_displayString("OFF");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(Temperature);
			state = STOP;
			speed = 0;
			DcMotor_Rotate(state, speed);
		} else if ((Temperature >= 30) && (Temperature < 60)) {
			LCD_moveCursor(0, 7);
			LCD_displayString("ON");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(Temperature);
			state = CLOCK_WISE;
			speed = 25;
			DcMotor_Rotate(state, speed);
		} else if ((Temperature >= 60) && (Temperature < 90)) {
			LCD_moveCursor(0, 7);
			LCD_displayString("ON");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(Temperature);
			state = CLOCK_WISE;
			speed = 50;
			DcMotor_Rotate(state, speed);
		} else if ((Temperature >= 90) && (Temperature < 120)) {
			LCD_moveCursor(0, 7);
			LCD_displayString("ON");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(Temperature);
			state = CLOCK_WISE;
			speed = 75;
			DcMotor_Rotate(state, speed);
		} else if (Temperature >= 120) {
			LCD_moveCursor(0, 7);
			LCD_displayString("ON");
			LCD_moveCursor(1, 7);
			LCD_intgerToString(Temperature);
			state = CLOCK_WISE;
			speed = 100;
			DcMotor_Rotate(state, speed);
		}
		if (speed < 100)
			LCD_displayCharacter(' ');
	}
}

