#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>

#include "Account.h"

using namespace std;

class Bank
{
private:
    vector<Account*> accounts;

public:
    Bank();
    ~Bank();

    void createAccount();
    void depositMoney();
    void withdrawMoney();
    void checkBalance();
    void displayAllAccounts();
    void calculateInterest();
    void transferMoney();

    Account* findAccount(int accountNo);
};

#endif