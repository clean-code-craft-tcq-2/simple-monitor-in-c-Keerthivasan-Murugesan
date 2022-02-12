#ifndef CheckBatteryStatus_H
#define CheckBatteryStatus_H

#include <stdio.h>
#include "PrintBatteryStatus.h"

#define TEMP_LOW_THR    0
#define TEMP_HIGH_THR   45
#define SOC_LOW_THR     20
#define SOC_HIGH_THR    80
#define CHARGERATE_LOW_THR   0
#define CHARGERATE_HIGH_THR  0.8

#define TEMP_MASK       0
#define SOC_MASK        1
#define CHARGERATE_MASK 2

extern struct {
    unsigned int higherlimitBreached;
    unsigned int lowerlimitBreached;
    unsigned int higherlimitWarning;
    unsigned int lowerlimitWarning;
}batterystatus;

void lowerThresholdBreached (float value, float threshold, int bitmask, struct batterystatus *bs1);
void higherThresholdBreached (float value, float threshold, int bitmask, struct batterystatus *bs1);

void CheckbatteryTemperature(float temperature, struct batterystatus *bs1);
void CheckbatterySOC(float soc, struct batterystatus *bs1);
void CheckbatterychargeRate(float chargeRate, struct batterystatus *bs1);

int batteryIsOk(float temperature, float soc, float chargeRate);

#endif