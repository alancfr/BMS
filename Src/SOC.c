#include <SOC.h>
#include <BMS.h>

	static const float OCV_LUT[POINTS_OCV][VALUES_OCV_SOC]= {{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{OCV_MIN,SOC_MIN}};

	void SOC_initial(BMS_struct *BMS) {
		uint16_t cell_voltage;
		float cell_soc;
		float cell_charge;

		if(BMS->AIR == AIR_OPEN){
			for(uint8_t i = 0; i < N_OF_SLAVES; i++) {
				for(uint8_t j = 0; j < N_OF_CELLS; j++) {
					cell_voltage = BMS->sensor[i]->CxV[j];
					for(uint8_t k = 0; k < POINTS_OCV; k++){
						if(cell_voltage <= OCV_LUT[k][OCV_VOLTAGE] && cell_voltage > OCV_LUT[k+1][OCV_VOLTAGE]){
							cell_soc = OCV_LUT[k][OCV_SOC];
							break;
						}
					}
					cell_charge = cell_soc * MAX_CELL_CHARGE;
					BMS->current_total_charge += cell_charge;
				}
			}
			BMS->soc_ocv_initial = BMS->current_total_charge/TOTAL_CHARGE;
		}
		else{
			Error_Handler();
		}
	}
