#ifndef PrintBatteryStatus_H
#define PrintBatteryStatus_H

#include <stdio.h>
#include "CheckBatteryStatus.h"

void printonConsole(struct batterystatus);
void printhigherlimitexceeded(struct batterystatus);
void printlowerlimitexceeded(struct batterystatus);
void printhigherlimitwarning(struct batterystatus);
void printlowerlimitwarning(struct batterystatus);

#endif