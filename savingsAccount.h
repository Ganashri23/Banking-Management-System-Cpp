#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount();
    SavingsAccount(int accNo, string n, double bal);

    ~SavingsAccount();

    void calculateInterest() override;
    void withdraw(double amount) override;
    void display() override;
};

#endif