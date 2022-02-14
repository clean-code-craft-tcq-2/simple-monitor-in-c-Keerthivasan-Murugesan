#include "CheckBatteryStatus.h"

void higherWarningLimitReached(float value, float threshold, float tolerance, int bitmask, unsigned int *batterystatus){
    float warninglimit = threshold - tolerance;
    if(value > warninglimit && value < threshold)   batterystatus[1] |= 1 << bitmask;
}

void lowerWarningLimitReached(float value, float threshold, float tolerance, int bitmask, unsigned int *batterystatus){
    float warninglimit = threshold + tolerance;
    if(value < warninglimit && value > threshold)   batterystatus[3] |= 1 << bitmask;
}

void lowerThresholdBreached(float value, float threshold, int bitmask, unsigned int *batterystatus){
    if (value < threshold) batterystatus[2] |= 1 << bitmask;
}

void higherThresholdBreached(float value, float threshold, int bitmask, unsigned int *batterystatus){
    if (value > threshold) batterystatus[0] |= 1 << bitmask;
}

void limitchecker(float value, float high_threshold, float low_threshold, int bitmask, unsigned int *batterystatus){
    float tolerance = 0.05*high_threshold;
    higherThresholdBreached(value, high_threshold, bitmask, batterystatus);
    lowerThresholdBreached(value, low_threshold, bitmask, batterystatus);
    higherWarningLimitReached(value, high_threshold, tolerance, bitmask, batterystatus);
    lowerWarningLimitReached(value, low_threshold, tolerance, bitmask, batterystatus);
}

void CheckbatteryTemperature(float temperature, unsigned int *batterystatus) {
    limitchecker(temperature, TEMP_HIGH_THR, TEMP_LOW_THR, TEMP_MASK, batterystatus);
}

void CheckbatterySOC(float soc, unsigned int *batterystatus){
    limitchecker(soc, SOC_HIGH_THR, SOC_LOW_THR, SOC_MASK, batterystatus);
}

void CheckbatterychargeRate(float chargeRate, unsigned int *batterystatus){
    limitchecker(chargeRate, CHARGERATE_HIGH_THR, CHARGERATE_LOW_THR, CHARGERATE_MASK, batterystatus);
}

int batteryIsOk(float temperature, float soc, float chargeRate){

    unsigned int batterystatus[4] = {
        0,       //higherlimitBreached
        0,       //higherlimitWarning
        0,       //lowerlimitBreached
        0        //lowerlimitWarning
    };

    CheckbatteryTemperature(temperature, batterystatus);
    CheckbatterySOC(soc, batterystatus);
    CheckbatterychargeRate(chargeRate, batterystatus);
    printonConsole(batterystatus);

    if(batterystatus[0] || batterystatus[2]) return 0;
    else return 1;
}