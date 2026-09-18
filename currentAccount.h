#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account
{
private:
    double minimumBalance;

public:
    CurrentAccount();
    CurrentAccount(int accNo, string n, double bal);

    ~CurrentAccount();

    void calculateInterest() override;
    void withdraw(double amount) override;
    void display() override;
};

#endif