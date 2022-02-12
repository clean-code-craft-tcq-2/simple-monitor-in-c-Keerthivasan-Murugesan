#ifndef PrintBatteryStatus_H
#define PrintBatteryStatus_H

#include <stdio.h>
#include "CheckBatteryStatus.h"

void printonConsole(struct batterystatus *bs1);
void printhigherlimitexceeded(struct batterystatus *bs1);
void printlowerlimitexceeded(struct batterystatus *bs1);
void printhigherlimitwarning(struct batterystatus *bs1);
void printlowerlimitwarning(struct batterystatus *bs1);

#endif