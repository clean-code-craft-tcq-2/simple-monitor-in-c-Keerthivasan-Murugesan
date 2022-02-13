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

extern unsigned int batterystatus[4];

void lowerThresholdBreached (float value, float threshold, int bitmask);
void higherThresholdBreached (float value, float threshold, int bitmask);

void CheckbatteryTemperature(float temperature);
void CheckbatterySOC(float soc);
void CheckbatterychargeRate(float chargeRate);

int batteryIsOk(float temperature, float soc, float chargeRate);

#endif