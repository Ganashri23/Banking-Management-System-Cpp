#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account
{
protected:
    int accountNo;
    string name;
    double balance;

public:
    Account();
    Account(int accNo, string n, double bal);
    Account(const Account &a);

    virtual ~Account();

    int getAccountNo();
    string getName();
    double getBalance();

    void deposit(double amount);
    virtual void withdraw(double amount);

    virtual void calculateInterest() = 0;
    virtual void display() = 0;

    bool operator==(const Account &a);
};

#endif