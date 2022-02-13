#include "CheckBatteryStatus.h"

void lowerThresholdBreached(float value, float threshold, int bitmask, unsigned int *batterystatus){
    float WarningLimit = 1.05*threshold;              //warning limit set 5% higher than threshold
    if (value < threshold) batterystatus[2] |= 1 << bitmask;
    else if (value < WarningLimit) batterystatus[3] |= 1 << bitmask;
    else{   /*do nothing*/  } 
}

void higherThresholdBreached(float value, float threshold, int bitmask, unsigned int *batterystatus){
    float WarningLimit = 0.95*threshold;              //warning limit set 5% lesser than threshold
    if (value > threshold) batterystatus[0] |= 1 << bitmask;
    else if (value > WarningLimit) batterystatus[1] |= 1 << bitmask;
    else{   /*do nothing*/  } 
}

void CheckbatteryTemperature(float temperature, unsigned int *batterystatus) {

    higherThresholdBreached(temperature, TEMP_HIGH_THR, TEMP_MASK, batterystatus);
    lowerThresholdBreached(temperature, TEMP_LOW_THR, TEMP_MASK, batterystatus);
}

void CheckbatterySOC(float soc, unsigned int *batterystatus){

    higherThresholdBreached(soc, SOC_HIGH_THR, SOC_MASK, batterystatus);
    lowerThresholdBreached(soc, SOC_LOW_THR, SOC_MASK, batterystatus);
}

void CheckbatterychargeRate(float chargeRate, unsigned int *batterystatus){
    higherThresholdBreached(chargeRate, CHARGERATE_HIGH_THR, CHARGERATE_MASK, batterystatus);
    lowerThresholdBreached(chargeRate, CHARGERATE_LOW_THR, CHARGERATE_MASK, batterystatus);
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

    printf("%d %d %d %d \n", batterystatus[0], batterystatus[1], batterystatus[2], batterystatus[3]);

    if(batterystatus[0] || batterystatus[2]) return 0;
    else return 1;
}