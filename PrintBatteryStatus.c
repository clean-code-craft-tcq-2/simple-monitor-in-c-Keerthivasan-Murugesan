#include "PrintBatteryStatus.h"

void printhigherlimitexceeded(){
    if((batterystatus[0]) & 1) printf("Temperature exceeds higher limit!\n");
    if((batterystatus[0]) & 2) printf("SOC exceeds higher limit!\n");
    if((batterystatus[0]d) & 4) printf("Charge rate exceeds higher limit!\n");
    printf("%d %d %d %d", batterystatus[0], batterystatus[1], batterystatus[2], batterystatus[3]);
}

void printlowerlimitexceeded(){
    if((batterystatus[2]) & 1) printf("Temperature is below lower limit!\n");
    if((batterystatus[2]) & 2) printf("SOC is below lower limit!\n");
    if((batterystatus[2]) & 4) printf("Charge rate is below lower limit!\n");
}

void printhigherlimitwarning(){
    if((batterystatu[1]) & 1) printf("Warning! Temperature is about to exceed the higher limit!\n");
    if((batterystatu[1]) & 2) printf("Warning! SOC is about to exceed the higher limit!\n");
    if((batterystatu[1]) & 4) printf("Warning! Charge rate is about to exceed the higher limit!\n");
}

void printlowerlimitwarning(){
    if((batterystatu[3]) & 1) printf("Warning! Temperature is about to breach the lower limit!\n");
    if((batterystatu[3]) & 2)printf("Warning! SOC is about to breach the lower limit!\n");
    if((batterystatu[3]) & 4) printf("Warning! Charge rate is about to breach the lower limit!\n");
}

void printonConsole(){
    void printhigherlimitexceeded();
    void printlowerlimitexceeded();
    void printhigherlimitwarning();
    void printlowerlimitwarning();
}