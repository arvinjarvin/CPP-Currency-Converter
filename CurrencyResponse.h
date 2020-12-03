#include <string>
#include "Currency.h"

using namespace std;

class CurrencyResponse
{
public:
    bool success;
    Currency currency;
    string error;

    CurrencyResponse(string _error)
    {
        success = false;
        error = _error;
    }

    CurrencyResponse(Currency _currency)
    {
        success = true;
        currency = _currency;
    }
};
