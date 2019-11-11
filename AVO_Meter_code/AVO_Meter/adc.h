 /******************************************************************************
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Fayez
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "std_macros.h"
#include "std_micro_comp_conf.h"

typedef enum
{
	AREF, AVCC ,IN2_25=2
}ADC_Reference;

/*division factor
--> ADC must operate in range 50-200Khz
*/
typedef enum
{
	 Div_Fac_2=1, Div_Fac_4, Div_Fac_8, Div_Fac_16, Div_Fac_32, Div_Fac_64, Div_Fac_128
}ADC_Prescaler;

typedef struct
{
	ADC_Reference referece;
	ADC_Prescaler divasion_fac;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :Function responsible for initialize the ADC driver.
 * input : configuration structure contain ADC reference and prescaler
 * output: nothing
 */
void ADC_init(ADC_ConfigType * Config_Ptr);

/*
 * Description : Function responsible for read analog data from a certain ADC channel
 *               and convert it to digital using the ADC driver.
 * input : channel number to ADC 
 * output: ADC value after sampling
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
