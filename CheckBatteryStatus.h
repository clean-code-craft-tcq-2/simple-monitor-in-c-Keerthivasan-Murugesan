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

void lowerWarningLimitReached(float value, float threshold, float tolerance, int bitmask, unsigned int *batterystatus);
void higherWarningLimitReached(float value, float threshold, float tolerance, int bitmask, unsigned int *batterystatus);
void lowerThresholdBreached (float value, float threshold, int bitmask, unsigned int *batterystatus);
void higherThresholdBreached (float value, float threshold, int bitmask, unsigned int *batterystatus);
void limitchecker(float value, float high_threshold, float low_threshold, int bitmask, unsigned int *batterystatus);

void CheckbatteryTemperature(float temperature, unsigned int *batterystatus);
void CheckbatterySOC(float soc, unsigned int *batterystatus);
void CheckbatterychargeRate(float chargeRate, unsigned int *batterystatus);

int batteryIsOk(float temperature, float soc, float chargeRate);

#endif