#ifndef CheckBatteryStatus_H
#define CheckBatteryStatus_H

#include "PrintBatteryStatus.h"

#define TEMP_LOW_THR    0
#define TEMP_HIGH_THR   45
#define SOC_LOW_THR     20
#define SOC_HIGH_THR    80
#define CHARGERATE_LOW_THR   0
#define CHARGERATE_HIGH_THR  0.8

#define TEMP_MASK       1
#define SOC_MASK        2
#define CHARGERATE_MASK 4

struct {
    unsigned int higherlimitBreached;
    unsigned int lowerlimitBreached;
    unsigned int higherlimitWarning;
    unsigned int lowerlimitWarning;
}batterystatus;

void lowerThresholdBreached (float value, float threshold, int bitmask);
void higherThresholdBreached (float value, float threshold, int bitmask);

void batteryTemperatureIsOk(float temperature);
void batterySOCIsOk(float soc);
void batterychargeRateIsOk(float chargeRate);

int batteryIsOk(float temperature, float soc, float chargeRate);

#endif