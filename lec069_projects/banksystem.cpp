#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accNumber;
    double balance;

public:
    BankAccount() {
        name = "";
        accNumber = 0;
        balance = 0.0;
    }

    void createAccount() {
        cout << "Enter account holder name: ";
        getline(cin, name);
        cout << "Enter account number: ";
        cin >> accNumber;
        cout << "Enter initial deposit: ";
        cin >> balance;
        cin.ignore(); // clear input buffer
        cout << "Account created successfully!\n";
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << "\n";
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else if (amount <= 0) {
            cout << "Invalid amount!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << "\n";
        }
    }

    void showDetails() {
        if (name == "") {
            cout << "No account exists.\n";
            return;
        }
        cout << "Account Holder: " << name << "\n";
        cout << "Account Number: " << accNumber << "\n";
        cout << "Current Balance: " << balance << "\n";
    }
};

int main() {
    BankAccount acc;
    int choice;

    while (true) {
        cout << "\n--- Bank Account System ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Show Details\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline from buffer

        switch (choice) {
            case 1: acc.createAccount(); break;
            case 2: acc.deposit(); break;
            case 3: acc.withdraw(); break;
            case 4: acc.showDetails(); break;
            case 5: cout << "Thank you for using the system.\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}
