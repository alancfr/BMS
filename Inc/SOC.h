#include "LTC6804.h"
#include "DHAB_s125.h"
#include "defines.h"
#include "BMS.h"

#define POINTS_OCV	11
#define VALUES_OCV_SOC	2
#define OCV_MIN	2.0
#define SOC_MIN	0

typedef enum{

	OCV_SOC = 1,
	OCV_VOLTAGE = 0,

}OCV_TABLE;
