#include <string>
#include <list>

#include "Currency.h"
#include "CurrencyResponse.h"

using namespace std;

class CurrencyService
{
private:
    list<Currency> currencies;
public:
    list<Currency> getCurrencies()
    {
        return currencies;
    }

    void registerBulkCurrencies(list<Currency> _currencies)
    {
        for(Currency currency : _currencies)
        {
            currencies.push_back(currency);
        }
    }

    CurrencyResponse findOne(string code)
    {
        Currency foundCurrency;

        for(Currency currency : currencies)
        {
            if(currency.code == code)
                foundCurrency = currency;
        }

        if(foundCurrency.name != "")
        {
            return CurrencyResponse(foundCurrency);
        }
        else
        {
            return CurrencyResponse("Sorry, that currency wasn't found.");
        }
    }

};
