#include "PrintBatteryStatus.h"

void printhigherlimitexceeded(){
    if((batterystatus.higherlimitBreached >> TEMP_MASK) & 1) printf("Temperature exceeds higher limit!\n");
    if((batterystatus.higherlimitBreached >> SOC_MASK) & 1) printf("SOC exceeds higher limit!\n");
    if((batterystatus.higherlimitBreached >> CHARGERATE_MASK) & 1) printf("Charge rate exceeds higher limit!\n");
}

void printlowerlimitexceeded(){
    if((batterystatus.lowerlimitBreached >> TEMP_MASK) & 1) printf("Temperature is below lower limit!\n");
    if((batterystatus.lowerlimitBreached >> SOC_MASK) & 1) printf("SOC is below lower limit!\n");
    if((batterystatus.lowerlimitBreached >> CHARGERATE_MASK) & 1) printf("Charge rate is below lower limit!\n");
}

void printhigherlimiwarning(){
    if((batterystatus.higherlimitWarning >> TEMP_MASK) & 1) printf("Warning! Temperature is about to exceed the higher limit!\n");
    if((batterystatus.higherlimitWarning >> SOC_MASK) & 1) printf("Warning! SOC is about to exceed the higher limit!\n");
    if((batterystatus.higherlimitWarning >> CHARGERATE_MASK) & 1) printf("Warning! Charge rate is about to exceed the higher limit!\n");
}

void printlowerlimiwarning(){
    if((batterystatus.lowerlimitWarning >> TEMP_MASK) & 1) printf("Warning! Temperature is about to breach the lower limit!\n");
    if((batterystatus.lowerlimitWarning >> SOC_MASK) & 1)printf("Warning! SOC is about to breach the lower limit!\n");
    if((batterystatus.lowerlimitWarning >> CHARGERATE_MASK) & 1) printf("Warning! Charge rate is about to breach the lower limit!\n");
}

void printonConsole(){
    void printhigherlimitexceeded();
    void printlowerlimitexceeded();
    void printhigherlimiwarning();
    void printlowerlimiwarning();
}