// simple_banking_system.cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accNumber, string accHolderName, double initialBalance)
        : accountNumber(accNumber), accountHolderName(accHolderName), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount(int accNumber, string accHolderName, double initialBalance) {
        accounts.emplace_back(accNumber, accHolderName, initialBalance);
        cout << "Account created successfully." << endl;
    }

    Account* findAccount(int accNumber) {
        for (auto& acc : accounts) {
            if (accNumber == acc.getAccountNumber()) {
                return &acc;
            }
        }
        return nullptr;
    }
};

int main() {
    Bank bank;

    bank.createAccount(1001, "John Doe", 500.0);
    bank.createAccount(1002, "Jane Smith", 300.0);

    int choice;
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display Account\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            int accNumber;
            cout << "Enter account number: ";
            cin >> accNumber;

            Account* acc = bank.findAccount(accNumber);
            if (!acc) {
                cout << "Account not found." << endl;
                continue;
            }

            if (choice == 1) {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc->deposit(amount);
            } else if (choice == 2) {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc->withdraw(amount);
            } else if (choice == 3) {
                acc->displayAccountInfo();
            }
        }
    } while (choice != 4);

    cout << "Exiting system." << endl;
    return 0;
}
