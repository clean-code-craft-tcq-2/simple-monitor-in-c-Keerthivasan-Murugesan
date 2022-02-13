#ifndef PrintBatteryStatus_H
#define PrintBatteryStatus_H

#include <stdio.h>
#include "CheckBatteryStatus.h"

extern unsigned int batterystatus[4];

void printonConsole();
void printhigherlimitexceeded();
void printlowerlimitexceeded();
void printhigherlimitwarning();
void printlowerlimitwarning();

#endif