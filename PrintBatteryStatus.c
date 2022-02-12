#include "PrintBatteryStatus.h"

void printhigherlimitexceeded(struct batterystatus *bs1){
    if((bs1->higherlimitBreached) & 1) printf("Temperature exceeds higher limit!\n");
    if((bs1->higherlimitBreached) & 2) printf("SOC exceeds higher limit!\n");
    if((bs1->higherlimitBreached) & 4) printf("Charge rate exceeds higher limit!\n");
    printf("%d %d %d %d", batterystatus->higherlimitBreached, batterystatus->lowerlimitBreached, batterystatus->higherlimitWarning, batterystatus->lowerlimitWarning);
}

void printlowerlimitexceeded(struct batterystatus *bs1){
    if((bs1->lowerlimitBreached) & 1) printf("Temperature is below lower limit!\n");
    if((bs1->lowerlimitBreached) & 2) printf("SOC is below lower limit!\n");
    if((bs1->lowerlimitBreached) & 4) printf("Charge rate is below lower limit!\n");
}

void printhigherlimitwarning(struct batterystatus *bs1){
    if((bs1->higherlimitWarning) & 1) printf("Warning! Temperature is about to exceed the higher limit!\n");
    if((bs1->higherlimitWarning) & 2) printf("Warning! SOC is about to exceed the higher limit!\n");
    if((bs1->higherlimitWarning) & 4) printf("Warning! Charge rate is about to exceed the higher limit!\n");
}

void printlowerlimitwarning(struct batterystatus *bs1){
    if((bs1->lowerlimitWarning) & 1) printf("Warning! Temperature is about to breach the lower limit!\n");
    if((bs1->lowerlimitWarning) & 2)printf("Warning! SOC is about to breach the lower limit!\n");
    if((bs1->lowerlimitWarning) & 4) printf("Warning! Charge rate is about to breach the lower limit!\n");
}

void printonConsole(struct batterystatus *bs1){
    void printhigherlimitexceeded(&bs1);
    void printlowerlimitexceeded(&bs1);
    void printhigherlimitwarning(&bs1);
    void printlowerlimitwarning(&bs1);
}