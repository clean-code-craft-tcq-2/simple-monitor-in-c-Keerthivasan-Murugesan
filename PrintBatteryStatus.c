#include "PrintBatteryStatus.h"

void printhigherlimitexceeded(unsigned int *batterystatus){
   // if((batterystatus[0]) & 1) printf("Temperature exceeds higher limit!\n");
  //  if((batterystatus[0]) & 2) printf("SOC exceeds higher limit!\n");
   // if((batterystatus[0]) & 4) printf("Charge rate exceeds higher limit!\n");
    batterystatus[0] & 1 ? printf("Temperature exceeds higher limit!\n") : printf("Temperature is OK!\n");
    batterystatus[0] & 2 ? printf("SOC exceeds higher limit!\n") : printf("SOC is OK!\n");
    batterystatus[0] & 4 ? printf("Charge rate exceeds higher limit!\n") : printf("Charge rate is OK!\n");
}

void printlowerlimitexceeded(unsigned int *batterystatus){
    if((batterystatus[2]) & 1) printf("Temperature is below lower limit!\n");
    if((batterystatus[2]) & 2) printf("SOC is below lower limit!\n");
    if((batterystatus[2]) & 4) printf("Charge rate is below lower limit!\n");
}

void printhigherlimitwarning(unsigned int *batterystatus){
    if((batterystatus[1]) & 1) printf("Warning! Temperature is approachingd the higher limit!\n");
    if((batterystatus[1]) & 2) printf("Warning! SOC is approaching the higher limit!\n");
    if((batterystatus[1]) & 4) printf("Warning! Charge rate is approaching the higher limit!\n");
}

void printlowerlimitwarning(unsigned int *batterystatus){
    if((batterystatus[3]) & 1) printf("Warning! Temperature is approaching the lower limit!\n");
    if((batterystatus[3]) & 2)printf("Warning! SOC approaching the lower limit!\n");
    if((batterystatus[3]) & 4) printf("Warning! Charge rate is approaching the lower limit!\n");
}

void printonConsole(unsigned int *batterystatus){
    printhigherlimitexceeded(batterystatus);
    printlowerlimitexceeded(batterystatus);
    printhigherlimitwarning(batterystatus);
    printlowerlimitwarning(batterystatus);
}