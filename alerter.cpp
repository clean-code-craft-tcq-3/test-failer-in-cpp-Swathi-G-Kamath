#include <iostream>
#include <assert.h>

int alertFailureCount = 0;
int temperature_thresh= 200.0;

int networkAlertStub(float celcius) {
   
    if(celcius>temperature_thresh)
     {
        std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
        return 500;
     }
    else
    {        
        return 200;
    }
        
}

float convertFarenehitToCelcius(float f)
{
    return((f-32)*5/9);
}

void alertInCelcius(float farenheit) {
    
    float celcius = convertFarenehitToCelcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount ++;
    }
}

void checkTotalFailures()
{
    checkTotalFailures();
    assert(alertFailureCount==0);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(200.0);
    return 0;
}
