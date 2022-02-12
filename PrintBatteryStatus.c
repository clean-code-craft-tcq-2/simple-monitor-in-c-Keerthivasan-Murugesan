#include "PrintBatteryStatus.h"

void printhigherlimitexceeded(){
    if((bs1.higherlimitBreached) & 1) printf("Temperature exceeds higher limit!\n");
    if((bs1.higherlimitBreached) & 2) printf("SOC exceeds higher limit!\n");
    if((bs1.higherlimitBreached) & 4) printf("Charge rate exceeds higher limit!\n");
}

void printlowerlimitexceeded(){
    if((bs1.lowerlimitBreached) & 1) printf("Temperature is below lower limit!\n");
    if((bs1.lowerlimitBreached) & 2) printf("SOC is below lower limit!\n");
    if((bs1.lowerlimitBreached) & 4) printf("Charge rate is below lower limit!\n");
}

void printhigherlimiwarning(){
    if((bs1.higherlimitWarning) & 1) printf("Warning! Temperature is about to exceed the higher limit!\n");
    if((bs1.higherlimitWarning) & 2) printf("Warning! SOC is about to exceed the higher limit!\n");
    if((bs1.higherlimitWarning) & 4) printf("Warning! Charge rate is about to exceed the higher limit!\n");
}

void printlowerlimiwarning(){
    if((bs1.lowerlimitWarning) & 1) printf("Warning! Temperature is about to breach the lower limit!\n");
    if((bs1.lowerlimitWarning) & 2)printf("Warning! SOC is about to breach the lower limit!\n");
    if((bs1.lowerlimitWarning) & 4) printf("Warning! Charge rate is about to breach the lower limit!\n");
}

void printonConsole(){
    void printhigherlimitexceeded();
    void printlowerlimitexceeded();
    void printhigherlimiwarning();
    void printlowerlimiwarning();
}