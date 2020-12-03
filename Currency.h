#pragma once

#include <string>

using namespace std;

class Currency
{
public:
    string name;
    char symbol;
    string code;
    float usdValue;

    Currency() { };

    Currency(string _name, char _symbol, string _code, float _usdValue)
    {
        name = _name;
        symbol = _symbol;
        code = _code;
        usdValue = _usdValue;
    }

    float convertValueTo(Currency currency, float value)
    {
        return currency.fromCurrency(Currency(name, symbol, code, usdValue), value, usdValue);
    }

    float fromCurrency(Currency currency, float value, float currecyUsdValue)
    {
        float receivingUsdValue = value*currecyUsdValue;

        return receivingUsdValue/usdValue;
    }
};

