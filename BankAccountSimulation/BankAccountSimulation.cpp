#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

int main()
{
    int option;
    cout << "Welcome to SimpleBank!" << endl;
    Bank bank;
    bool run = true;

    while (run) {
        cout << endl;

        string BANK_OPTIONS[] = { "Create New Account", "Login", "Deposit Money", "Withdraw Money",
            "View Account Details", "Apply Interest to Savings", "List All Accounts", "Logout", "Exit"
        };

        int NUM_OPTIONS = sizeof(BANK_OPTIONS) / sizeof(BANK_OPTIONS[0]);

        for (int i = 1; i <= NUM_OPTIONS; i++) {
            cout << i << ". " << BANK_OPTIONS[i - 1] << endl;
        }

        cout << "Enter Choice Number: ";
        cin >> option;

        switch (option) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.login();
                break;
            case 3:
                bank.deposit();
                break;
            case 4:
                bank.withdraw();
                break;
            case 5:
                bank.displayAccount();
                break;
            case 6:
                bank.applyInterest();
                break;
            case 7:
                bank.listAccounts();
                break;
            case 8:
                bank.logout();
                break;
            case 9:
                cout << "Thank you for using SimpleBank!" << endl;
                run = false;
                break;
            default:
                cout << "Invalid choice number, please try again." << endl;
            }

    }
    
}
