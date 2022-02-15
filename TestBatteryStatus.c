#include <stdio.h>
#include <assert.h>
#include "CheckBatteryStatus.h"

void testbatterystatus(){
  assert(batteryIsOk(25, 70, 0.7));
  assert(batteryIsOk(25, 21, 0.7));
  assert(batteryIsOk(43, 78, 0.01));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(40, 15, -0.1));
  assert(!batteryIsOk(-10, 20, 1));
  assert(!batteryIsOk(30, 10, 0.8));
}

int main() {
  testbatterystatus();
}
