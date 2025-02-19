///****************************************************************/
///**					Team Formula Tesla UFMG - 2018				*/
///** Microcontroller: STM32F103XXXX								*/
///** Compiler: AC6 - STM worbench								*/
///** Author: Henrique, Eric, Virginia							*/
///** License: Free - Open Source									*/
///** 															*/
///****************************************************************/
//
//#ifndef DHAB_H
//#define DHAB_H
//
//#include "defines.h"
//#include "stm32f1xx_hal.h"
//#include <math.h>
//
//
//typedef struct DHAB{
//
//	//CURRENT VARIABLES:
//
//	uint16_t c_sum;
//	uint8_t c_error[4];
//
//}DHAB;
//
//void DHAB_init();
//
//uint8_t DHAB_get_error(DHAB* sensor);
//
//#endif

#include "dwt_stm32_delay.h"
#include "defines.h"
#include "usart.h"
#include <stdlib.h>


typedef struct DHAB_sensor{
	double current;
	double current_adc;
	double coulombCounting;
}DHAB_sensor;

void DHAB_init();
void DHAB_get_error(DHAB_sensor *sensor);
void DHAB_read(DHAB_sensor *sensor);
double DHAB_currentIntegration(DHAB_sensor *sensor);
