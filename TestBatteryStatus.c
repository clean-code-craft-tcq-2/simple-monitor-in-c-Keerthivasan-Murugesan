#include <stdio.h>
#include <assert.h>
#include "CheckBatteryStatus.h"

void testbatterystatus(){
  assert(batteryIsOk(25, 70, 0.7));
  assert(batteryIsNotOk(50, 85, 0));
}

int main() {
  testbatterystatus();
}
