#include "CheckBatteryStatus.h"

int lowerThresholdBreached(float value, float threshold){
    if (value < threshold) return 1;
    else return 0;
}

int higherThresholdBreached(float value, float threshold){
    if (value > threshold) return 1;
    else return 0;
}

int batteryTemperatureIsOk(float temperature) {

    int result_high = higherThresholdBreached(temperature, TEMP_HIGH_THR);
    int result_low = lowerThresholdBreached(temperature, TEMP_LOW_THR);

    if(result_high || result_low) {
        printf("Temperature out of range!\n");
        return 0;
    }
    else{
        return 1;
    }

}

int batterySOCIsOk(float soc){

    int result_high = higherThresholdBreached(soc, SOC_HIGH_THR);
    int result_low = lowerThresholdBreached(soc, SOC_LOW_THR);

    if(result_high || result_low) {
        printf("SOC out of range!\n");
        return 0;
    }
    else{
        return 1;
    }

}

int batterychargeRateIsOk(float chargeRate){
    int result_high = higherThresholdBreached(chargeRate, CHARGERATE_HIGH_THR);
    int result_low = lowerThresholdBreached(chargeRate, CHARGERATE_LOW_THR);
    if(result_high || result_low) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
     else{
        return 1;
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate){
  return (batteryTemperatureIsOk(temperature) && batterySOCIsOk(soc) && batterychargeRateIsOk(chargeRate));
}

int batteryIsNotOk(float temperature, float soc, float chargeRate){
  return (batteryTemperatureIsOk(temperature) || batterySOCIsOk(soc) || batterychargeRateIsOk(chargeRate));
}