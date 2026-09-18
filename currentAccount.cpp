#include "CurrentAccount.h"

CurrentAccount::CurrentAccount()
{
    minimumBalance = 1000;
}

CurrentAccount::CurrentAccount(int accNo, string n, double bal)
    : Account(accNo, n, bal)
{
    minimumBalance = 1000;
}

CurrentAccount::~CurrentAccount()
{
}

void CurrentAccount::calculateInterest()
{
    cout << "Current Account does not provide interest." << endl;
}

void CurrentAccount::withdraw(double amount)
{
    if(amount <= 0)
    {
        throw "Invalid withdrawal amount";
    }

    if(balance - amount < minimumBalance)
    {
        throw "Minimum balance should be maintained";
    }

    balance = balance - amount;
}

void CurrentAccount::display()
{
    cout << "Account No : " << accountNo << endl;
    cout << "Name       : " << name << endl;
    cout << "Type       : Current" << endl;
    cout << "Balance    : " << balance << endl;
}