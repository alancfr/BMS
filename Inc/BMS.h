/*
 * bms.h
 *
 *  Created on: 17 de mar de 2022
 *      Author: Thiago
 */

#ifndef BMS_H
#define BMS_H
#define MAX_CELL_CHARGE 72000 //20mA * 3600s
#define TOTAL_CHARGE MAX_CELL_CHARGE * N_OF_CELLS * N_OF_PACKS

#include "ltc.h"
#include "constants.h"
#include "stdlib.h"


typedef struct BMS_struct {

	//GENERAL
	uint8_t mode;
	uint16_t error;

	LTC_sensor *sensor[NUMBER_OF_SLAVES];
	LTC_config *config;
//	DHAB_sensor *dhabSensor[N_OF_DHAB];

	uint16_t tractiveSystemVoltage;
	uint16_t maxCellVoltage;
	uint16_t minCellVoltage;
	uint16_t deltaVoltage;
	uint16_t maxCellTemperature;

	//CURRENT
	float current[ADC_BUFFER_SIZE];
	float c_adc[ADC_BUFFER_SIZE];

	//AIR
	uint8_t AIR;
	
	//SOC
	float current_total_charge; //Accumulator
	float soc_ocv_initial;
	
}BMS_struct;

typedef enum{

	OVER_VOLTAGE 	 = 0,
	UNDER_VOLTAGE  	 = 1,
	OVER_TEMPERATURE = 2

}BMS_RETRIES;

#define BMS_CONVERT_CELL 	1
#define BMS_CONVERT_GPIO	2
#define BMS_CONVERT_STAT	4
#define BMS_CONVERT_CONFIG	8

void BMS_Init(BMS_struct *BMS);
void BMS_SetSafetyLimits(BMS_struct* BMS);
void BMS_Monitoring(BMS_struct *BMS);
void BMS_Convert(uint8_t BMS_CONVERT, BMS_struct *BMS);
void BMS_Balance(BMS_struct *BMS);
void BMS_AIR_status(BMS_struct *BMS);
void BMS_ErrorTreatment(BMS_struct *BMS);

#endif
