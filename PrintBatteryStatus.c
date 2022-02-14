#include "PrintBatteryStatus.h"

const char* batteryParameter[] = {"Temperature", "StateofCharge", "ChargeRate"};
const char* batteryStatus_Str[] = {"exceeds higher limit",
                               "approaching the higher limit", 
                               "below lower limit", 
                               "approaching the lower limit"};

void printonConsole(unsigned int *batterystatus){
    int i, j;
    for(i=0; i<=3; i++){
        int k = 0;
        for(j=1; j<=4; j=j*2){
            if((batterystatus[i]) & j) printf("%s is %s\n", batteryParameter[k], batteryStatus_Str[i]);
            k++;
        }
    }
}