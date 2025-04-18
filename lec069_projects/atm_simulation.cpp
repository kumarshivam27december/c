#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class User {
    string pin;
    double balance;

public:
    User(string pin, double balance = 0.0) : pin(pin), balance(balance) {}

    bool authenticate(string enteredPin) {
        return pin == enteredPin;
    }

    void checkBalance() {
        cout << "Your current balance is: ₹" << balance << "\n";
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "₹" << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else if (amount <= 0) {
            cout << "Invalid amount.\n";
        } else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        }
    }
};

int main() {
    unordered_map<string, User> users = {
        {"1234", User("1234", 1000.0)},
        {"5678", User("5678", 500.0)}
    };

    string enteredPin;
    cout << "Welcome to the ATM\nEnter your 4-digit PIN: ";
    cin >> enteredPin;

    if (users.find(enteredPin) == users.end() || !users[enteredPin].authenticate(enteredPin)) {
        cout << "Authentication failed. Exiting...\n";
        return 0;
    }

    cout << "Login successful!\n";
    int choice;
    double amount;

    do {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                users[enteredPin].checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ₹";
                cin >> amount;
                users[enteredPin].deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ₹";
                cin >> amount;
                users[enteredPin].withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
