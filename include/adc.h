/*
 * ADC.c
 *
 *  Created on: Oct 4, 2019
 *      Author: fithrotulia
 */
#ifndef ADC_H_
#define ADC_H_

void ADC_Init();

uint16_t ADC_Read(uint8_t mux,char mode);
uint16_t data1, data2;
uint16_t hasil;

#endif /* ADC_H_ */
