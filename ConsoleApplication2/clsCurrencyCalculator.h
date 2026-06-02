#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
using namespace std;
class clsCurrencyCalculator : protected clsScreen
{
private :
	static clsCurrency _GetCurrency(string m)
	{
		cout << m;
		string Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nCurrency With [" << Code << "] Not Found ,Enter another Again: ";
		   Code = clsInputValidate::ReadString();
		}
		return clsCurrency::FindByCode(Code);
	}
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n______________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n______________________\n";
	}
	static void _PrintCalculationsResults(clsCurrency Currency1, clsCurrency Currency2)
	{
		double Amount;
		cout << "\nEnter Amount to Exchange: ";
		Amount = clsInputValidate::ReadDblNumberPositive();

		cout << "\n\nConvert From: ";
		_PrintCurrencyCard(Currency1);
		cout << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConverToUSD(Amount) << " USD";

		if (Currency2.CurrencyCode() != "USD")
		{
			cout << "\n\nConvert From USD To: ";
			_PrintCurrencyCard(Currency2);
			cout << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConvertToAnotherCurrency(Amount, Currency2) << " " << Currency2.CurrencyCode();

		}
	}
public:
	static void ShowCurrencyCalculatorScreen()
	{
		do
		{
			system("cls");
			_DrawScreenHeader("     Currency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code: ");

			clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code: ");

			if (Currency1.CurrencyCode() != Currency2.CurrencyCode())
				_PrintCalculationsResults(Currency1, Currency2);
			else
				cout << "\nCan't Exchange to the same Currency :-(\n";

		} while (clsInputValidate::Ask("\n\nDo you want to perform another calculation? y/n ? "));

	}
};

