#ifndef PrintBatteryStatus_H
#define PrintBatteryStatus_H

#include <stdio.h>
#include <stdbool.h>
#include "CheckBatteryStatus.h"

void printalert(bool print, int parameter, int status);
void printonConsole(unsigned int *batterystatus);

#endif