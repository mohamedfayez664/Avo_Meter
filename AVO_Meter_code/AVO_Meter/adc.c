/******************************************************************************
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Fayez
 *******************************************************************************/
#include "adc.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 (bit7,6)= to choose reference voltage 
	 * ADLAR   (bit 5) = 0 right adjusted
	 * MUX4:0  (bit4:0)= 0 to choose channel 0 as initialization
	 */
	ADMUX = ( (Config_Ptr->referece) & 0X03)<<5 ;

	/* ADCSRA Register Bits Description:
	 * ADEN    (bit7)= 1 Enable ADC
	 * ADIE    (bit3)= 0 Disable ADC Interrupt
	 * ADPS2:0 (bit2:0)= to choose ADC_Clock=F_CPU/divasion_fac
     *         --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | ( (Config_Ptr->divasion_fac) & 0X07);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	/* channel number must be from 0 --> 7
	 * clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel
	 * choose the correct channel by setting the channel number in MUX4:0 bits
	 */
	ADMUX= (ADMUX & 0XE0) | (channel_num & 0X07);
	
	/* start conversion write '1' to ADSC 
     * clear ADIF by write '1' to it that make flag = 0 
	 */
	ADCSRA|=(1<<ADSC) | (1<<ADIF);    
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait for conversion to complete ADIF becomes '1' */
	return ADC;                       /* return the data register */
}
