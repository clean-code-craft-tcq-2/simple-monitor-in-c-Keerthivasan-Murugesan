#ifndef CheckBatteryStatus_H
#define CheckBatteryStatus_H

#define TEMP_LOW_THR    0
#define TEMP_HIGH_THR   45
#define SOC_LOW_THR     20
#define SOC_HIGH_THR    80
#define CHARGERATE_LOW_THR   0
#define CHARGERATE_HIGH_THR  0.8

int lowerThresholdBreached (float value, float threshold);
int higherThresholdBreached (float value, float threshold);

int batteryTemperatureIsOk(float temperature);
int batterySOCIsOk(float soc);
int batterychargeRateIsOk(float chargeRate);

int batteryIsOk(float temperature, float soc, float chargeRate);

#endif