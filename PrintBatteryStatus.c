#include "PrintBatteryStatus.h"

const char* batteryParameter[] = {"Temperature", "StateofCharge", "ChargeRate"};
const char* batteryStatus_Str[] = {"above higher limit",
                                   "approaching the higher limit", 
                                   "below lower limit", 
                                   "approaching the lower limit"};

void printonConsole(bool print, int parameter, int status){
    if(print) printf("%s is %s\n", batteryParameter[parameter], batteryStatus_Str[status]);
}

void printalert(unsigned int *batterystatus){
    int i, j;
    for(i=0; i<=3; i++){
        int k = 0;
        for(j=1; j<=4; j=j*2){
            bool print = batterystatus[i] & j;
            printonConsole(print, k, i);
            k++;
        }
    }
}