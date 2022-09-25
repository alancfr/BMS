#include "display.h"
#include "nextion.h"
#include "stdbool.h"
#include "stm32f1xx.h"
#include "string.h"
extern UART_HandleTypeDef huart3;

extern uint8_t uart_user_message[256];	/* Buffer received for user access */
extern bool error_flag[NUMBER_OF_ERRORS];

uint8_t actual_page;
char Buf[50];

//uint8_t flag_information_to_send = 0;
//NextionPage_e previous_page = PAGE0;
//NextionPage_e actual_page   = PAGE0;
//NextionAdvice_e actual_advice = NO_ADVICE;

void display_init() {
	nexInit();
	NexPageShow(0);
}

void display_show(BMS_struct *BMS){

//HAL_UART_DMAPause(&huart3);

    //Descomentar para HMI com botão
    //HAL_UART_Receive(&huart3, (uint8_t*) Buf,1,1000);
    //actual_page = atoi (Buf);
    //Descomentar para HMI com variável
        actual_page = NexNumberGetValue(0);

        switch(actual_page)
        {
            case N_PAGE0:
            break;

            case N_PAGE1:
                NexXfloatSetValue(0,BMS->maxCellVoltage/100);
                NexXfloatSetValue(1, BMS->minCellVoltage/100);
                NexXfloatSetValue(2, BMS->tractiveSystemVoltage);
                NexXfloatSetValue(3,BMS->maxCellTemperature*10);
                NexVariableSetValue(2, BMS->AIR);
                NexNumberSetValue(1, (BMS->current[0] + BMS->current[2]));
                NexNumberSetValue(2, BMS->error);
            break;

            case N_PAGE2:
                NexXfloatSetValue(0, (int16_t)BMS->sensor[0]->CxV[0]/(-100));
                NexXfloatSetValue(1, (int16_t)BMS->sensor[0]->CxV[1]/(-100));
                NexXfloatSetValue(2, (int16_t)BMS->sensor[0]->CxV[2]/(-100));
                NexXfloatSetValue(3, (int16_t)BMS->sensor[0]->CxV[3]/(-100));
                NexXfloatSetValue(4, (int16_t)BMS->sensor[0]->CxV[4]/(-100));
                NexXfloatSetValue(5, (int16_t)BMS->sensor[0]->CxV[5]/(-100));
                NexXfloatSetValue(6, (int16_t)BMS->sensor[0]->CxV[6]/(-100));
                NexXfloatSetValue(7, (int16_t)BMS->sensor[0]->CxV[7]/(-100));
                NexXfloatSetValue(8, (int16_t)BMS->sensor[0]->CxV[8]/(-100));
                NexXfloatSetValue(9, (int16_t)BMS->sensor[0]->CxV[9]/(-100));
                NexXfloatSetValue(10, (int16_t)BMS->sensor[0]->CxV[10]/(-100));
                NexXfloatSetValue(11, (int16_t)BMS->sensor[0]->CxV[11]/(-100));
                NexXfloatSetValue(12, BMS->sensor[0]->GxV[0]*10);
                NexXfloatSetValue(13, BMS->sensor[0]->GxV[1]*10);
                NexXfloatSetValue(14, BMS->sensor[0]->GxV[2]*10);
                NexXfloatSetValue(15, BMS->sensor[0]->GxV[3]*10);
                NexXfloatSetValue(16, BMS->sensor[0]->GxV[4]*10);
            break;

            case N_PAGE3:
                NexXfloatSetValue(0, (int16_t)BMS->sensor[1]->CxV[0]/(-100));
                NexXfloatSetValue(1, (int16_t)BMS->sensor[1]->CxV[1]/(-100));
                NexXfloatSetValue(2, (int16_t)BMS->sensor[1]->CxV[2]/(-100));
                NexXfloatSetValue(3, (int16_t)BMS->sensor[1]->CxV[3]/(-100));
                NexXfloatSetValue(4, (int16_t)BMS->sensor[1]->CxV[4]/(-100));
                NexXfloatSetValue(5, (int16_t)BMS->sensor[1]->CxV[5]/(-100));
                NexXfloatSetValue(6, (int16_t)BMS->sensor[1]->CxV[6]/(-100));
                NexXfloatSetValue(7, (int16_t)BMS->sensor[1]->CxV[7]/(-100));
                NexXfloatSetValue(8, (int16_t)BMS->sensor[1]->CxV[8]/(-100));
                NexXfloatSetValue(9, (int16_t)BMS->sensor[1]->CxV[9]/(-100));
                NexXfloatSetValue(10, (int16_t)BMS->sensor[1]->CxV[10]/(-100));
                NexXfloatSetValue(11, (int16_t)BMS->sensor[1]->CxV[11]/(-100));
                NexXfloatSetValue(12, BMS->sensor[1]->GxV[0]*10);
                NexXfloatSetValue(13, BMS->sensor[1]->GxV[1]*10);
                NexXfloatSetValue(14, BMS->sensor[1]->GxV[2]*10);
                NexXfloatSetValue(15, BMS->sensor[1]->GxV[3]*10);
                NexXfloatSetValue(16, BMS->sensor[1]->GxV[4]*10);
            break;

            case N_PAGE4:
                NexXfloatSetValue(0, (int16_t)BMS->sensor[2]->CxV[0]/(-100));
                NexXfloatSetValue(1, (int16_t)BMS->sensor[2]->CxV[1]/(-100));
                NexXfloatSetValue(2, (int16_t)BMS->sensor[2]->CxV[2]/(-100));
                NexXfloatSetValue(3, (int16_t)BMS->sensor[2]->CxV[3]/(-100));
                NexXfloatSetValue(4, (int16_t)BMS->sensor[2]->CxV[4]/(-100));
                NexXfloatSetValue(5, (int16_t)BMS->sensor[2]->CxV[5]/(-100));
                NexXfloatSetValue(6, (int16_t)BMS->sensor[2]->CxV[6]/(-100));
                NexXfloatSetValue(7, (int16_t)BMS->sensor[2]->CxV[7]/(-100));
                NexXfloatSetValue(8, (int16_t)BMS->sensor[2]->CxV[8]/(-100));
                NexXfloatSetValue(9, (int16_t)BMS->sensor[2]->CxV[9]/(-100));
                NexXfloatSetValue(10, (int16_t)BMS->sensor[2]->CxV[10]/(-100));
                NexXfloatSetValue(11, (int16_t)BMS->sensor[2]->CxV[11]/(-100));
                NexXfloatSetValue(12, BMS->sensor[2]->GxV[0]*10);
                NexXfloatSetValue(13, BMS->sensor[2]->GxV[1]*10);
                NexXfloatSetValue(14, BMS->sensor[2]->GxV[2]*10);
                NexXfloatSetValue(15, BMS->sensor[2]->GxV[3]*10);
                NexXfloatSetValue(16, BMS->sensor[2]->GxV[4]*10);
            break;

            case N_PAGE5:
                NexXfloatSetValue(0, (int16_t)BMS->sensor[3]->CxV[0]/(-100));
                NexXfloatSetValue(1, (int16_t)BMS->sensor[3]->CxV[1]/(-100));
                NexXfloatSetValue(2, (int16_t)BMS->sensor[3]->CxV[2]/(-100));
                NexXfloatSetValue(3, (int16_t)BMS->sensor[3]->CxV[3]/(-100));
                NexXfloatSetValue(4, (int16_t)BMS->sensor[3]->CxV[4]/(-100));
                NexXfloatSetValue(5, (int16_t)BMS->sensor[3]->CxV[5]/(-100));
                NexXfloatSetValue(6, (int16_t)BMS->sensor[3]->CxV[6]/(-100));
                NexXfloatSetValue(7, (int16_t)BMS->sensor[3]->CxV[7]/(-100));
                NexXfloatSetValue(8, (int16_t)BMS->sensor[3]->CxV[8]/(-100));
                NexXfloatSetValue(12, BMS->sensor[3]->GxV[0]*10);
                   NexXfloatSetValue(13, BMS->sensor[3]->GxV[1]*10);
                   NexXfloatSetValue(14, BMS->sensor[3]->GxV[2]*10);
                   NexXfloatSetValue(15, BMS->sensor[3]->GxV[3]*10);
                   NexXfloatSetValue(16, BMS->sensor[3]->GxV[4]*10);
        }

//HAL_UART_DMAResume(&huart3);
}


