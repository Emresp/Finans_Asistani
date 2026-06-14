#include "FinanceManager.h"
#include "Transaction.h"
#include "menu.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    //Konsolu Türkçe Yaptık
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

     Menu myMenu;
    myMenu.baslat();

    return 0;
}