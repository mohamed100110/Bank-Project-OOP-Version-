#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrency :protected clsScreen
{
private:
	enum Choice { Code = 1, Country };
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card:";
		cout << "\n______________________";
		cout << "\nCountry    : "<<Currency.Country();
		cout << "\nCode       : "<< Currency.CurrencyCode();
		cout << "\nName       : "<< Currency.CurrencyName();
		cout << "\nRate(1$) = : "<< Currency.Rate();
		cout << "\n______________________\n";
	}
	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)";
			_PrintCurrencyCard(Currency);
		}
		else
			cout << "\nCurrency NOT Found :-(\n";
	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("       Find Currency Screen ");

		clsCurrency Currency = clsCurrency::FindByCode("");

		cout << "\nFind By: [1] Code or [2] country ? ";
		short Num = clsInputValidate::ReadShortNumberBetween(1, 2);

		if (Num == Choice::Code)
		{
			string Code;
			cout << "\nPlease Enter Currency Code: ";
			Code = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCode(Code);
		}
		else if (Num == Choice::Country)
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCountry(Country);
		}
		_ShowResult(Currency);
	}
};

