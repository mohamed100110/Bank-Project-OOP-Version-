#pragma once
#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsCurrency.h"
#include <iomanip>
using namespace std;
class clsCurrencyList:protected clsScreen
{
private:

    static void _PrintCurrencyRecordLine(clsCurrency CurrecnyRecord)
    {
        cout << setw(8) << left << "" << "| " << left << setw(30) << CurrecnyRecord.Country();
        cout << "| " << left << setw(10) << CurrecnyRecord.CurrencyCode();
        cout << "| " << left << setw(42) << CurrecnyRecord.CurrencyName() ;
        cout << "| " << left << setw(15) << CurrecnyRecord.Rate();
    }


public:
	static void ShowCurrencyList()
	{
		vector<clsCurrency> vCurrenciesList = clsCurrency::GetCurrenciesList();

		string Title = "      Currencies List Screen";
		string SubTitle = "         " + to_string(vCurrenciesList.size()) + " Currencies.";
		_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(42) << "Name";
        cout << "| " << left << setw(15) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrenciesList.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency &C : vCurrenciesList)
            {

                _PrintCurrencyRecordLine(C);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
	}
};

