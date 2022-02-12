#include "CheckBatteryStatus.h"

void lowerThresholdBreached(float value, float threshold, int bitmask){
    float WarningLimit = 1.05*threshold;              //warning limit set 5% higher than threshold
    if (value < threshold) batterystatus.lowerlimitBreached = 1 << bitmask;
    else if (value < WarningLimit) batterystatus.lowerlimitWarning = 1 << bitmask;
    else{   /*do nothing*/  } 
}

void higherThresholdBreached(float value, float threshold, int bitmask){
    float WarningLimit = 0.95*threshold;              //warning limit set 5% lesser than threshold
    if (value > threshold) batterystatus.higherlimitBreached = 1 << bitmask;
    else if (value > WarningLimit) batterystatus.higherlimitWarning = 1 << bitmask;
    else{   /*do nothing*/  } 
}

void CheckbatteryTemperature(float temperature) {

    higherThresholdBreached(temperature, TEMP_HIGH_THR, TEMP_MASK);
    lowerThresholdBreached(temperature, TEMP_LOW_THR, TEMP_MASK);
}

void CheckbatterySOC(float soc){

    higherThresholdBreached(soc, SOC_HIGH_THR, SOC_MASK);
    lowerThresholdBreached(soc, SOC_LOW_THR, SOC_MASK);
}

void CheckbatterychargeRate(float chargeRate){
    higherThresholdBreached(chargeRate, CHARGERATE_HIGH_THR, CHARGERATE_MASK);
    lowerThresholdBreached(chargeRate, CHARGERATE_LOW_THR, CHARGERATE_MASK);
}

int batteryIsOk(float temperature, float soc, float chargeRate){
    CheckbatteryTemperature(temperature);
    CheckbatterySOC(soc);
    CheckbatterychargeRate(chargeRate);
    printonConsole();

    if(batterystatus.higherlimitBreached || batterystatus.lowerlimitBreached) return 0;
    else return 1;
}