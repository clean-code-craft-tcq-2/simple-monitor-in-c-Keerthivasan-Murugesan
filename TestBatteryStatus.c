#include <stdio.h>
#include <assert.h>
#include "CheckBatteryStatus.h"

void testbatterystatus(){
  assert(batteryIsOk(25, 70, 0.7));
  assert(batteryIsNotOk(50, 85, 0));
  assert(batteryIsNotOk(40, 15, -0.1));
}

int main() {
  testbatterystatus();
}
