/*
 * ADC.h
 *  Config ADC driver
 *  Created on: Feb 23, 2022
 *      Author: abdelrahman
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
//define The internal ref voltage
#define ADC_REF_VOLT_VALUE   2.56
/*  define All predicted values of ref volt by putting it in enum  */
typedef enum {
	AREF, AVCC, RESERVED, INTERNAL_REFERENCE_VOLTAGE
} ADC_ReferenceVoltage;
/*  define All predicted values of prescaler by putting it in enum  */
typedef enum {
	RESERVEDD,
	F_CPU_2,
	F_CPU_4,
	F_CPU_8,
	F_CPU_16,
	F_CPU_32,
	F_CPU_64,
	F_CPU_128,
} ADC_Prescaler;

typedef struct {
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
