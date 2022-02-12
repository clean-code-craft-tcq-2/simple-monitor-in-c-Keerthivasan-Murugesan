#include "PrintBatteryStatus.h"

void printhigherlimitexceeded(){
    if((batterystatus.higherlimitBreached) & 1) printf("Temperature exceeds higher limit!\n");
    if((batterystatus.higherlimitBreached) & 2) printf("SOC exceeds higher limit!\n");
    if((batterystatus.higherlimitBreached) & 4) printf("Charge rate exceeds higher limit!\n");
    printf("%d %d %d %d", batterystatus.higherlimitBreached, batterystatus.lowerlimitBreached, batterystatus.higherlimitWarning, batterystatus.lowerlimitWarning);
}

void printlowerlimitexceeded(){
    if((batterystatus.lowerlimitBreached) & 1) printf("Temperature is below lower limit!\n");
    if((batterystatus.lowerlimitBreached) & 2) printf("SOC is below lower limit!\n");
    if((batterystatus.lowerlimitBreached) & 4) printf("Charge rate is below lower limit!\n");
}

void printhigherlimiwarning(){
    if((batterystatus.higherlimitWarning) & 1) printf("Warning! Temperature is about to exceed the higher limit!\n");
    if((batterystatus.higherlimitWarning) & 2) printf("Warning! SOC is about to exceed the higher limit!\n");
    if((batterystatus.higherlimitWarning) & 4) printf("Warning! Charge rate is about to exceed the higher limit!\n");
}

void printlowerlimiwarning(){
    if((batterystatus.lowerlimitWarning) & 1) printf("Warning! Temperature is about to breach the lower limit!\n");
    if((batterystatus.lowerlimitWarning) & 2)printf("Warning! SOC is about to breach the lower limit!\n");
    if((batterystatus.lowerlimitWarning) & 4) printf("Warning! Charge rate is about to breach the lower limit!\n");
}

void printonConsole(){
    void printhigherlimitexceeded();
    void printlowerlimitexceeded();
    void printhigherlimiwarning();
    void printlowerlimiwarning();
}