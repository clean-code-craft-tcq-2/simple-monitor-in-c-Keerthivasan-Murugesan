#ifndef PrintBatteryStatus_H
#define PrintBatteryStatus_H

#include <stdio.h>
#include <stdbool.h>
#include "CheckBatteryStatus.h"

void printonConsole(bool print, int parameter, int status);
void printalert(unsigned int *batterystatus);

#endif