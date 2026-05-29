#include "clsLoginScreen.h"
#include "Global.h"
int main()
{

   // clsMainScreen::ShowMainMenue();
    while(IsLogin)
    {
        clsLoginScreen::ShowLoginScreen();
    }
    return 0;
}