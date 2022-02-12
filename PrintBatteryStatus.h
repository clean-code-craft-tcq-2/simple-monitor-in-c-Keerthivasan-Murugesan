#ifndef PrintBatteryStatus_H
#define PrintBatteryStatus_H

#include <stdio.h>
#include "CheckBatteryStatus.h"

void printonConsole(batterystatus bs1);
void printhigherlimitexceeded(batterystatus bs1);
void printlowerlimitexceeded(batterystatus bs1);
void printhigherlimitwarning(batterystatus bs1);
void printlowerlimitwarning(batterystatus bs1);

#endif