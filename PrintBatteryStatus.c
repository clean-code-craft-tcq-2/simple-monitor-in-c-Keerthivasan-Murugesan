#include "PrintBatteryStatus.h"

const char* batteryParameter[] = {"Temperature", "StateofCharge", "ChargeRate"};
const char* batteryStatus_Str[] = {"exceeds higher limit",
                               "approaching the higher limit", 
                               "below lower limit", 
                               "approaching the lower limit"};

void printonConsole(unsigned int *batterystatus){
    int i, j;
    for(i=0; i++; i<=3){
        int k = 0;
        for(j=1; j*2; j<=4){
            printf("%d %d", batterystatus[i], k);
            if((batterystatus[i]) & j) printf("%s is %s", batteryParameter[k], batteryStatus_Str[i]);
            k++;
        }
    }
}