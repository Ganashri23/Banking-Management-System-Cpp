#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
{
    interestRate = 4.0;
}

SavingsAccount::SavingsAccount(int accNo, string n, double bal)
    : Account(accNo, n, bal)
{
    interestRate = 4.0;
}

SavingsAccount::~SavingsAccount()
{
}

void SavingsAccount::calculateInterest()
{
    double interest;

    interest = balance * interestRate / 100;

    cout << "Interest: " << interest << endl;
}

void SavingsAccount::withdraw(double amount)
{
    Account::withdraw(amount);
}

void SavingsAccount::display()
{
    cout << "Account No : " << accountNo << endl;
    cout << "Name       : " << name << endl;
    cout << "Type       : Savings" << endl;
    cout << "Balance    : " << balance << endl;
}