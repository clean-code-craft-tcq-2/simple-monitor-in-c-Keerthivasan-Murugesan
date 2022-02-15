#ifndef PrintBatteryStatus_H
#define PrintBatteryStatus_H

#include <stdio.h>
#include <stdbool.h>
#include "CheckBatteryStatus.h"

#define ENGLISH 0
#define GERMAN 1

typedef struct LanguageParameters
{
    char batteryParameter[3][20];
	char batteryStatus_Str[5][20];
}LanguageParam;

extern LanguageParam alertprinter[2];

void printonConsole(bool print, int parameter, int status);
void printalert(unsigned int *batterystatus);

#endif