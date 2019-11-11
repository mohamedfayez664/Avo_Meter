/*
 * Motors dash_board
 * Created: 12,10,2019
 * Author : Mohamed Fayez
 */
#include "adc.h"
#include "lcd.h"
#include "delay.h"

int main(void)
{
	uint16 adc_value,    adc_value_temp;   uint32 res_reverence=10000;
	float32 unknown_res, volt,  current;
	ADC_ConfigType myAdcConf={AREF,Div_Fac_8};
	LCD_init();            /* initialize LCD driver */
	ADC_init(&myAdcConf);            /* initialize ADC driver */
    DELAY_init();

    while(1)
	{
		adc_value = ADC_readChannel(0); /* read channel zero where the potentiometer is connect */

		if(adc_value_temp != adc_value){
			LCD_clearScreen();
			adc_value_temp = adc_value;
		}

		LCD_goToRowColumn(0,0);
		LCD_displayString("ADC Value = ");
		LCD_displayNumber(adc_value);            /* display the ADC value on LCD screen */

		/*volt*/
		volt=(float)adc_value*.0048828;          // adc_value * (4.88)/1000 >>> >>> 5000/1024
		LCD_goToRowColumn(1,0);
		LCD_displayString("V=");
		LCD_displayFloatNumber (volt ,3) ;       /* display the ADC value on LCD screen */

		/*for reverence 10 K_ohm */
		unknown_res=( (res_reverence*( volt /5)) / ( 1-(volt/5)) );
		LCD_goToRowColumn(1,9);
		LCD_displayString("R=");
		LCD_displayFloatNumber( (unknown_res/1000) ,3);  /* display the ADC value on LCD screen */

		/*Current*/
		current=(float)volt/(unknown_res/1000) ;
		LCD_goToRowColumn(2,4);
		LCD_displayString("I=");
		LCD_displayFloatNumber (current ,3) ;            /* display the current value on LCD screen */

		DELAY_ms(200);
	}
}
