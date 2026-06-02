#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
using namespace std;

class clsUpdateCurrency :protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card:";
		cout << "\n______________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n______________________\n";
	}
	static void _UpdateRate(clsCurrency& Currency)
	{
		cout << "\nUpdate Currency Rate:";
		cout << "\n______________________";
		cout << "\nEnter New Rate: ";
		double Rate = clsInputValidate::ReadDblNumberPositive();
		Currency.UpdateRate(Rate);

		cout << "\nCurrency Rate Updated Sucessfully :-)";
		_PrintCurrencyCard(Currency);
	}
public:
	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("       Update Currency Screen");

		string Code;
		cout << "\nPlease Enter Currency Code: ";
		Code = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(Code);

		if (!Currency.IsEmpty())
		{
			_PrintCurrencyCard(Currency);
			if (clsInputValidate::Ask("\nAre You Sure you want to update the rate of this currency y/n? "))
				_UpdateRate(Currency);
		}
		else
			cout << "\nCurrency NOT Found :-(\n";

	}
};

