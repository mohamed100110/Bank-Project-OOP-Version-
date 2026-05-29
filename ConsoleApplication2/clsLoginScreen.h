#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{
	
	static void _Login()
	{
		string UserName, Password;
		bool LoginFailed = false;
		short LoginTry=3;
		do
		{
			if (LoginFailed)
			{
				cout << "\nInvalide UserName/password!";
				LoginTry--;
				cout << "\nYou have " << LoginTry << " Trials to login.\n\n";
				if (LoginTry == 0)
				{
					cout << "\nYou are locked after 3 failed trials.\n";
					IsLogin = false;  //Global
					return;
				}
			}

			cout << "Enter UserName? ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Passward? ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();
		} while (LoginFailed );

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
	}
public:
	static void ShowLoginScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tLogin Screen");
		_Login();


	}
};
