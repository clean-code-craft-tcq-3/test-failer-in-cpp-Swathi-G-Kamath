#include <iostream>
#include <assert.h>

int alertFailureCount = 0;
int temperature_thresh= 200.0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if(celcius>temperature_thresh)
     {
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
    assert(alertFailureCount==1);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(200.0);
    checkTotalFailures();
    return 0;
}
