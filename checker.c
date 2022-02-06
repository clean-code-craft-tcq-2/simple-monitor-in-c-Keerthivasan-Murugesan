#include <stdio.h>
#include <assert.h>

int batteryTemperatureIsOk(float temperature) {
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } else {
    return 1;
  }
}

int batterySOCIsOk(float soc){
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  else{
    return 1;
  }
}

int batterychargeRateIsOk(float chargeRate){
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  else{
    return 1;
  }
}

boolean batteryIsOk(float temperature, float soc, float chargeRate){
  boolean batteryIsOk = FALSE;
  batteryIsOk = (batteryTemperatureIsOk(temperature) && batterySOCIsOk(soc) && batterychargeRateIsOk(chargeRate));
  return batteryIsOk;
}

boolean batteryIsNotOk(float temperature, float soc, float chargeRate){
  boolean batteryIsNotOk = FALSE;
  batteryIsNotOk = (batteryTemperatureIsOk(temperature) || batterySOCIsOk(soc) || batterychargeRateIsOk(chargeRate));
  return batteryIsNotOk;
}

void testbatterystatus(){
  assert(batteryIsOk(25, 70, 0.7));
  assert(batteryIsNotOk(50, 85, 0));
}

int main() {
  testbatterystatus();
}
