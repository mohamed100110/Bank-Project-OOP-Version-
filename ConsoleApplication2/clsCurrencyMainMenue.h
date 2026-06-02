#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include "clsCurrencyList.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsCurrencyCalculator.h"
using namespace std;
class clsCurrencyMainMenue :protected clsScreen
{
private:
	enum enCurrencyMenueOptions {
		eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};
	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static  void _GoBackToCurrencyMenu()
	{
		cout << "\nPress any key to go back to Currency Menu...";

		system("pause>0");
		ShowCurrencyMenuScreen();
	}
	static void _ShowCurrencyList()
	{
		//cout << "Currency List Will Be Here." << endl;
		clsCurrencyList::ShowCurrencyList();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "Find Currency Will Be Here." << endl;
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "Update Rate Will Be Here." << endl;
		clsUpdateCurrency::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculator()
	{
		//cout << "Currency Calculator Will Be Here." << endl;
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
	}
	static void _PerfromCurrencyMenuOption(enCurrencyMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enCurrencyMenueOptions::eListCurrency:
		{
			system("cls");
			_ShowCurrencyList();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}

		case enCurrencyMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyMenueOptions::eMainMenue:

			break;

		}
	}


public:
	static void ShowCurrencyMenuScreen()
	{
		system("cls");
		_DrawScreenHeader("  Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "            Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currency.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerfromCurrencyMenuOption((enCurrencyMenueOptions)_ReadMainMenueOption());
	}

};

