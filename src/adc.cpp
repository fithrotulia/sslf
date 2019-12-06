/*
 * ADC.c
 *
 *  Created on: Oct 4, 2019
 *      Author: fithrotulia
 */
#include  <avr/io.h>
#include  "ADC.h"

void ADC_Init(){
	ADCSRA |= (1<<ADATE); //ADC trigger enable
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1); //prescaller 64
	ADCSRB &=~(_BV(ADTS2)|_BV(ADTS1)|_BV(ADTS0)); //free running
	ADMUX  |= (1<<REFS0); //referensi vcc
	//ADMUX  |= (1<<ADLAR);
	ADCSRA |= (1<<ADEN); //ADC enable
	ADCSRA |= (1<<ADSC); //ADC start konversi
    ADMUX &=~ (0x1F);
}

uint16_t ADC_Read(uint8_t mux, char mode)
{
    ADMUX &=~ (0x1F);
    ADMUX |= (mux);
	//data=((ADCH<<2)|(ADCL>>6));
	//return data;
	data1 = ADCL;
	data2 = ADCH;
	
	if (mode == 'F')
	{
		hasil = data2*256 + data1;
	}
	if (mode == 'L')
	{
		hasil = data1;
	}
	if (mode == 'H')
	{
		hasil = data2;
	}

	return hasil;
}
