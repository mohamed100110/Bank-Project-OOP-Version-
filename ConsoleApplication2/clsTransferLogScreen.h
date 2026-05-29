#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"
using namespace std;
class clsTransferLogScreen:protected clsScreen
{
private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TranferLog)
    {

        cout << setw(8) << left << "" << "| " << left << setw(22) << TranferLog.TimeTransfer ;
        cout << "| " << left << setw(10) << TranferLog.sClient ;
        cout << "| " << left << setw(10) << TranferLog.dClient ;
        cout << "| " << left << setw(10) << TranferLog.Amount ;
        cout << "| " << left << setw(11) << TranferLog.sBalance ;
        cout << "| " << left << setw(11) << TranferLog.dBalance ;
        cout << "| " << left << setw(10) << TranferLog.UserName ;

    }

public:

    static void ShowTransferLogScreen()
    {

        if (!_CheckAccessRights(clsUser::enPermissions::pShowLoginRegister ))
        {
            return;
        }
        vector <clsBankClient::stTransferLogRecord> vTransferLog = clsBankClient::GetTransferLogList();

        string Title = "\tTranfer Log List Screen";
        string SubTitle = "\t  (" + to_string(vTransferLog.size()) + ") Record(s).";

        clsScreen::_DrawScreenHeader(Title,SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(22) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(11) << "s.Balance";
        cout << "| " << left << setw(11) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLog)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

