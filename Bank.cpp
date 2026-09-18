#include "Bank.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

Bank::Bank()
{
}

Bank::~Bank()
{
    for(int i = 0; i < accounts.size(); i++)
    {
        delete accounts[i];
    }
}

Account* Bank::findAccount(int accountNo)
{
    for(int i = 0; i < accounts.size(); i++)
    {
        if(accounts[i]->getAccountNo() == accountNo)
        {
            return accounts[i];
        }
    }

    return NULL;
}

void Bank::createAccount()
{
    int accountNo;
    int type;
    string name;
    double balance;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    if(findAccount(accountNo) != NULL)
    {
        cout << "Account already exists." << endl;
        return;
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Initial Balance: ";
    cin >> balance;

    if(balance < 0)
    {
        cout << "Invalid balance." << endl;
        return;
    }

    cout << "\n1. Savings Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "Enter Account Type: ";
    cin >> type;

    if(type == 1)
    {
        accounts.push_back(
            new SavingsAccount(accountNo, name, balance)
        );

        cout << "\nAccount created successfully." << endl;
    }
    else if(type == 2)
    {
        if(balance < 1000)
        {
            cout << "Current account requires minimum balance of 1000." << endl;
            return;
        }

        accounts.push_back(
            new CurrentAccount(accountNo, name, balance)
        );

        cout << "\nAccount created successfully." << endl;
    }
    else
    {
        cout << "Invalid account type." << endl;
    }
}

void Bank::depositMoney()
{
    int accountNo;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    Account *ptr = findAccount(accountNo);

    if(ptr == NULL)
    {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Enter Amount: ";
    cin >> amount;

    try
    {
        ptr->deposit(amount);

        cout << "Amount deposited successfully." << endl;
    }
    catch(const char *msg)
    {
        cout << "Error: " << msg << endl;
    }
}

void Bank::withdrawMoney()
{
    int accountNo;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    Account *ptr = findAccount(accountNo);

    if(ptr == NULL)
    {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Enter Amount: ";
    cin >> amount;

    try
    {
        ptr->withdraw(amount);

        cout << "Amount withdrawn successfully." << endl;
    }
    catch(const char *msg)
    {
        cout << "Error: " << msg << endl;
    }
}

void Bank::checkBalance()
{
    int accountNo;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    Account *ptr = findAccount(accountNo);

    if(ptr == NULL)
    {
        cout << "Account not found." << endl;
        return;
    }

    cout << "\nCurrent Balance: "
         << ptr->getBalance() << endl;
}

void Bank::displayAllAccounts()
{
    if(accounts.empty())
    {
        cout << "\nNo accounts available." << endl;
        return;
    }

    cout << "\n========== ACCOUNT DETAILS ==========\n";

    for(int i = 0; i < accounts.size(); i++)
    {
        accounts[i]->display();
        cout << "-------------------------------------" << endl;
    }
}

void Bank::calculateInterest()
{
    int accountNo;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    Account *ptr = findAccount(accountNo);

    if(ptr == NULL)
    {
        cout << "Account not found." << endl;
        return;
    }

    ptr->calculateInterest();
}

void Bank::transferMoney()
{
    int from;
    int to;
    double amount;

    cout << "\nEnter Sender Account Number: ";
    cin >> from;

    cout << "Enter Receiver Account Number: ";
    cin >> to;

    Account *sender = findAccount(from);
    Account *receiver = findAccount(to);

    if(sender == NULL || receiver == NULL)
    {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Enter Amount: ";
    cin >> amount;

    try
    {
        sender->withdraw(amount);
        receiver->deposit(amount);

        cout << "Transfer successful." << endl;
    }
    catch(const char *msg)
    {
        cout << "Transfer failed: " << msg << endl;
    }
}