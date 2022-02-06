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

int batteryIsOk(float temperature, float soc, float chargeRate){
  int batteryIsOk = 1;
  batteryIsOk *= batteryTemperatureIsOk(temperature);
  batteryIsOk *= batterySOCIsOk(soc);
  batteryIsOk *= batterychargeRateIsOk(chargeRate);
  return batteryIsOk;
}

void testbatterystatus(){
  assert(batteryIsOk(25, 70, 0.7));
  assert(batteryIsOk(50, 85, 0));
}

int main() {
  testbatterystatus();
}
