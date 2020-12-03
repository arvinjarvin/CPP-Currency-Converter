#include <iostream>
#include <list>

#include "CurrencyService.h"

using namespace std;

CurrencyService currencyService = CurrencyService();
list<Currency> currencies;

int main()
{
    /// pounds is 156

    cout << "Welcome to the currency converter." << endl;

    list<Currency> currenciesToRegister;

    Currency toRegister[] =
    {
        /// Currency(string CurrencyName, char SymbolASCII, string Code, float ValueInUSD)
        Currency("Pounds Sterling", (char)156, "GBP", 1.34),
        Currency("Euro", (char)128, "EUR", 1.21),
        Currency("United States Dollars", '$', "USD", 1.00),
        Currency("Indian Rupees", (char)8377, "INR", 0.014),
        Currency("Australian Dollars", '$', "AUD", 0.74),
        Currency("Canadian Dollars", '$', "CAD", 0.78),
        Currency("Singapore Dollars", '$', "SGD", 0.75)
    };

    for(Currency c : toRegister)
    {
        currenciesToRegister.push_back(c);
    }

    currencyService.registerBulkCurrencies(currenciesToRegister);
    currencies = currencyService.getCurrencies();

    cout << "Here are the available currencies;" << endl << endl;

    for(Currency currency : currencies)
    {
        cout << currency.name << " (" << currency.symbol << ") - Code: " << currency.code << endl;
    }

    string currencyCode;
    string targetCode;

    cout << endl << "Enter the CODE of your FROM currency (e.g GBP): ";

    while(getline(cin, currencyCode))
    {
        Currency fromCurrency;
        Currency targetCurrency;
        float amountToConvert;

        CurrencyResponse currentCurrency = currencyService.findOne(currencyCode);

        if(!currentCurrency.success)
        {
            cout << currentCurrency.error << endl;
            cout << "Enter another currency code, the last was incorrect: ";
            continue;
        }

        fromCurrency = currentCurrency.currency;

        cout << "Now enter the code of the currency you want to convert to: ";

        getline(cin, targetCode);

        CurrencyResponse targetResponse = currencyService.findOne(targetCode);

        if(!targetResponse.success)
        {
            cout << targetResponse.error << endl;
            cout << "Enter another starting currency code, the last was incorrect: ";
            continue;
        }

        targetCurrency = targetResponse.currency;

        cout << "How much do you want to convert from " << fromCurrency.code << " to " << targetCurrency.code << ": ";


        cin >> amountToConvert;
        cin.ignore(256, '\n');

        float resultingAmount = targetCurrency.fromCurrency(fromCurrency, amountToConvert, fromCurrency.usdValue);

        cout << "That is " << resultingAmount << targetCurrency.code << " (" << char(targetCurrency.symbol) << resultingAmount << ")." << endl;

        cout << "Enter another starting currency: ";

    }

}
