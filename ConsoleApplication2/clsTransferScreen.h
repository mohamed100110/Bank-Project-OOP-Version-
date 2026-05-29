#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsTransferScreen :protected clsScreen
{
	static void _PrintSimpleClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n____________________________\n";
		cout << "Full Name   :" << Client.FullName();
		cout << "\nAcc. Number :" << Client.AccountNumber();
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n____________________________\n";

	}
	static string _ReadAccountNumber()
	{
		string AccNum = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccNum))
		{
			cout << "\nAccount Number With [" << AccNum << "] Not exist,Enter anthor one:";
			AccNum = clsInputValidate::ReadString();
		}
		return AccNum;
	}
public:
	static void ShowTransferScreen()
	{
		clsScreen::_DrawScreenHeader("\t     Transfer Screen");

		cout << "\nPlease Enter Account Number to Transfer From:";
		string AccNum1 = _ReadAccountNumber();
		clsBankClient Client1 = clsBankClient::Find(AccNum1);
		_PrintSimpleClientCard(Client1);

		cout << "\nPlease Enter Account Number to Transfer To:";
		string AccNum2 = _ReadAccountNumber();
		while (AccNum2 == AccNum1)
		{
			cout << "\nYou can't Transfer to the same Account Number,Enter anthor one:";
			AccNum2 = _ReadAccountNumber();
		}
		clsBankClient Client2 = clsBankClient::Find(AccNum2);
		_PrintSimpleClientCard(Client2);

		cout << "\nEnter Transfer Amount: ";
		double Amount = clsInputValidate::ReadDblNumberPositive();
		while (Amount > Client1.AccountBalance)
		{
			cout << "\nAmount Exceeds the Available Balance, Enter another Amount? ";
			Amount = clsInputValidate::ReadDblNumberPositive();
		}
		if (clsInputValidate::Ask("\nAre you sure you want to perform this operation? y/n? "))
		{
			if (Client1.Transfer(Amount, Client2))
			{
				cout << "\nTransfer Done Successfully\n";
				_PrintSimpleClientCard(Client1);
				_PrintSimpleClientCard(Client2);
			}
			else
				cout << "\nFailed Operation!";
		}
		


	}
};

