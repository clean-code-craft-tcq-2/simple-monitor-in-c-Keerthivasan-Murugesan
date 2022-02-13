#ifndef PrintBatteryStatus_H
#define PrintBatteryStatus_H

#include <stdio.h>
#include "CheckBatteryStatus.h"

void printonConsole();
void printhigherlimitexceeded();
void printlowerlimitexceeded();
void printhigherlimitwarning();
void printlowerlimitwarning();

#endif