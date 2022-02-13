#include "CheckBatteryStatus.h"

void lowerThresholdBreached(float value, float threshold, int bitmask, struct batterystatus *bs1){
    float WarningLimit = 1.05*threshold;              //warning limit set 5% higher than threshold
    if (value < threshold) batterystatus[2] |= 1 << bitmask;
    else if (value < WarningLimit) batterystatus[3] |= 1 << bitmask;
    else{   /*do nothing*/  } 
}

void higherThresholdBreached(float value, float threshold, int bitmask, struct batterystatus *bs1){
    float WarningLimit = 0.95*threshold;              //warning limit set 5% lesser than threshold
    if (value > threshold) batterystatus[0] |= 1 << bitmask;
    else if (value > WarningLimit) batterystatus[1] |= 1 << bitmask;
    else{   /*do nothing*/  } 
}

void CheckbatteryTemperature(float temperature, struct batterystatus *bs1) {

    higherThresholdBreached(temperature, TEMP_HIGH_THR, TEMP_MASK, &bs1);
    lowerThresholdBreached(temperature, TEMP_LOW_THR, TEMP_MASK, &bs1);
}

void CheckbatterySOC(float soc, struct batterystatus *bs1){

    higherThresholdBreached(soc, SOC_HIGH_THR, SOC_MASK, &bs1);
    lowerThresholdBreached(soc, SOC_LOW_THR, SOC_MASK, &bs1);
}

void CheckbatterychargeRate(float chargeRate, struct batterystatus *bs1){
    higherThresholdBreached(chargeRate, CHARGERATE_HIGH_THR, CHARGERATE_MASK, &bs1);
    lowerThresholdBreached(chargeRate, CHARGERATE_LOW_THR, CHARGERATE_MASK, &bs1);
}

int batteryIsOk(float temperature, float soc, float chargeRate){
   unsigned int batterystatus[4] = {
       0,       //higherlimitBreached
       0,       //higherlimitWarning
       0,       //lowerlimitBreached
       0        //lowerlimitWarning
   };
    CheckbatteryTemperature(temperature);
    CheckbatterySOC(soc);
    CheckbatterychargeRate(chargeRate);
    printonConsole();

    if(batterystatus[0] || batterystatus[2]) return 0;
    else return 1;
}