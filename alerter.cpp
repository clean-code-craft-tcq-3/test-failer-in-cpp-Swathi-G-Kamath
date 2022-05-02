#include <iostream>
#include <assert.h>

int alertFailureCount = 0;
#define TEMPTHRESHOLD 200.0
#define SUCCESS 200
#define FAILURE 500

int testNetworkAlertStub(float celcius)
{
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if (celcius > TEMPTHRESHOLD)
    {
        return FAILURE;
    }
    else
    {
        return SUCCESS;
    }
}

int testProductionAlertStub(float celcius)
{
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Threshold needs to be defined for production environment, currently returning SUCCESS in all cases.
    return SUCCESS;
}

float convertFarenehitToCelcius(float f)
{
    return((f - 32) * 5 / 9);
}

void alertInCelcius(const char* env, float farenheit)
{
    int returnCode;
    float celcius = convertFarenehitToCelcius(farenheit);
    if (env == "Test environment")
        returnCode = testNetworkAlertStub(celcius);
    else if (env == "Production environment")
        returnCode = testProductionAlertStub(celcius);
    if (returnCode == FAILURE)
    {
        alertFailureCount += 1;
    }
}

void checkTotalFailures()
{
    assert(alertFailureCount == 1);
    std::cout << alertFailureCount << " alerts failed.\n";
}

int main() {
    alertInCelcius("Production environment", 400.5);
    alertInCelcius("Test environment", 403.6);
    checkTotalFailures();
    return 0;
}

