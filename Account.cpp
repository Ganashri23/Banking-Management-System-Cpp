#include "Account.h"

Account::Account()
{
    accountNo = 0;
    name = "Unknown";
    balance = 0;
}

Account::Account(int accNo, string n, double bal)
{
    accountNo = accNo;
    name = n;
    balance = bal;
}

Account::Account(const Account &a)
{
    accountNo = a.accountNo;
    name = a.name;
    balance = a.balance;
}

Account::~Account()
{
}

int Account::getAccountNo()
{
    return accountNo;
}

string Account::getName()
{
    return name;
}

double Account::getBalance()
{
    return balance;
}

void Account::deposit(double amount)
{
    if(amount <= 0)
    {
        throw "Invalid deposit amount";
    }

    balance = balance + amount;
}

void Account::withdraw(double amount)
{
    if(amount <= 0)
    {
        throw "Invalid withdrawal amount";
    }

    if(amount > balance)
    {
        throw "Insufficient balance";
    }

    balance = balance - amount;
}

bool Account::operator==(const Account &a)
{
    return accountNo == a.accountNo;
}