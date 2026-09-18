#include <iostream>

#include "Bank.h"
#include "Utility.h"

using namespace std;

int main()
{
    Bank bank;

    int choice;

    do
    {
        cout << "\n======================================" << endl;
        cout << "       BANKING MANAGEMENT SYSTEM      " << endl;
        cout << "======================================" << endl;

        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. Transfer Money" << endl;
        cout << "7. Calculate Interest" << endl;
        cout << "8. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.depositMoney();
                break;

            case 3:
                bank.withdrawMoney();
                break;

            case 4:
                bank.checkBalance();
                break;

            case 5:
                bank.displayAllAccounts();
                break;

            case 6:
                bank.transferMoney();
                break;

            case 7:
                bank.calculateInterest();
                break;

            case 8:
                cout << "\nThank you for using Banking Management System." << endl;
                break;

            default:
                cout << "\nInvalid choice." << endl;
        }

    } while(choice != 8);

    return 0;
}