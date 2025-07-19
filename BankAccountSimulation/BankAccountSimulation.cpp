#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

// The purpose of this bank account simulation was to practice my understanding of pointers by implementing dynamic
// memory allocation to store accounts and inheritance by creating savings as well checking account types that derive 
// from the base bank account class.  
int main()
{
    string option;
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

        if (option == "1") {
            bank.createAccount();
        }
        else if (option == "2") {
            bank.login();
        }
        else if (option == "3") {
            bank.credit();
        }
        else if (option == "4") {
            bank.debit();
        }
        else if (option == "5") {
            bank.displayAccount();
        }
        else if (option == "6") {
            bank.applyInterest();
        }
        else if (option == "7") {
            bank.listAccounts();
        }
        else if (option == "8") {
            bank.logout();
        }
        else if (option == "9") {
            cout << "Thank you for using SimpleBank!" << endl;
            run = false;
        }
        else {
            cout << "Invalid choice number, please try again." << endl;
        }

    }
    
}
