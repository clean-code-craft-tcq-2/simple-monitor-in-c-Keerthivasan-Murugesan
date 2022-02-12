#include "PrintBatteryStatus.h"
#include "CheckBatteryStatus.h"

void printhigherlimitexceeded(){
    if(batterystatus.higherlimitBreached << TEMP_MASK) printf("Temperature exceeds higher limit!\n");
    if(batterystatus.higherlimitBreached << SOC_MASK) printf("SOC exceeds higher limit!\n");
    if(batterystatus.higherlimitBreached << CHARGERATE_MASK) printf("Charge rate exceeds higher limit!\n");
}

void printlowerlimitexceeded(){
    if(batterystatus.lowerlimitBreached << TEMP_MASK) printf("Temperature is below lower limit!\n");
    if(batterystatus.lowerlimitBreached << SOC_MASK) printf("SOC is below lower limit!\n");
    if(batterystatus.lowerlimitBreached << CHARGERATE_MASK) printf("Charge rate is below lower limit!\n");
}

void printlowerlimitexceeded(){
    if(batterystatus.lowerlimitBreached << TEMP_MASK) printf("Temperature is below lower limit!\n");
    if(batterystatus.lowerlimitBreached << SOC_MASK) printf("SOC is below lower limit!\n");
    if(batterystatus.lowerlimitBreached << CHARGERATE_MASK) printf("Charge rate is below lower limit!\n");
}

void printhigherlimiwarning(){
    if(batterystatus.higherlimitWarning << TEMP_MASK) printf("Warning! Temperature is about to exceed the higher limit!\n");
    if(batterystatus.higherlimitWarning << SOC_MASK) printf("Warning! SOC is about to exceed the higher limit!\n");
    if(batterystatus.higherlimitWarning << CHARGERATE_MASK) printf("Warning! Charge rate is about to exceed the higher limit!\n");
}

void printlowerlimiwarning(){
    if(batterystatus.lowerlimitWarning << TEMP_MASK) printf("Warning! Temperature is about to breach the lower limit!\n");
    if(batterystatus.lowerlimitWarning << SOC_MASK) printf("Warning! SOC is about to breach the lower limit!\n");
    if(batterystatus.lowerlimitWarning << CHARGERATE_MASK) printf("Warning! Charge rate is about to breach the lower limit!\n");
}

void printonConsole(){
    void printhigherlimitexceeded();
    void printlowerlimitexceeded();
    void printhigherlimiwarning();
    void printlowerlimiwarning();
}