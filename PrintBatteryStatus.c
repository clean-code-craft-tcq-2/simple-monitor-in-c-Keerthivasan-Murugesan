#include "PrintBatteryStatus.h"

int language = GERMAN;

LanguageParam alertprinter[2]= {{{"Temperature", "StateofCharge", "ChargeRate"},
                                {"HIGH_BREACH", "HIGH_WARNING", "LOW_BREACH", "LOW_WARNING", "NORMAL"}}, 
                                {{"Temperatur", "Ladezustand", "Ladestrom"},
                                {"HOCH_VERSTOSS", "HOCH_WARNUNG", "NIEDRIG_VERSTOSS", "NIEDRIG_WARNUNG", "NORMAL"}}};


void printonConsole(bool print, int parameter, int status){
    if(print) printf("%s : %s\n", alertprinter[language].batteryParameter[parameter], alertprinter[language].batteryStatus_Str[status]);
    else printf("%s : %s\n", alertprinter[language].batteryParameter[parameter], alertprinter[language].batteryStatus_Str[4]);
}

void printalert(unsigned int *batterystatus){
    int i, j;
    printf("*********************************\n");
    for(i=0; i<=3; i++){
        int k = 0;
        for(j=1; j<=4; j=j*2){
            bool print = batterystatus[i] & j;
            printonConsole(print, k, i);
            k++;
        }
    }
}