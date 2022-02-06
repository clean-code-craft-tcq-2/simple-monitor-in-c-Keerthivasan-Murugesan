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

void testbatterystatus(){
  assert(batteryTemperatureIsOk(25) && batterySOCIsOk(70) && batterychargeRateIsOk(0.7));
  assert(batteryTemperatureIsOk(50) && batterySOCIsOk(85) && batterychargeRateIsOk(0));
}

int main() {
  testbatterystatus();
}
