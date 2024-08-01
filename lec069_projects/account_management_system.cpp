#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Account {
public:
    Account(const std::string& owner, double initialBalance)
        : owner(owner), balance(initialBalance) {
        addTransaction("Account created with initial balance: $" + std::to_string(initialBalance));
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction("Deposited: $" + std::to_string(amount));
        } else {
            std::cerr << "Deposit amount must be positive!" << std::endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction("Withdrew: $" + std::to_string(amount));
            return true;
        } else {
            std::cerr << "Insufficient funds or invalid amount!" << std::endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

    void printTransactionHistory() const {
        std::cout << "Transaction History for " << owner << ":" << std::endl;
        for (const std::string& transaction : transactionHistory) {
            std::cout << transaction << std::endl;
        }
    }

private:
    std::string owner;
    double balance;
    std::vector<std::string> transactionHistory;

    void addTransaction(const std::string& transaction) {
        transactionHistory.push_back(transaction);
    }
};

void displayMenu() {
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Check Balance" << std::endl;
    std::cout << "4. View Transaction History" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    std::string owner;
    double initialBalance;

    std::cout << "Enter account owner name: ";
    std::getline(std::cin, owner);
    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;

    Account account(owner, initialBalance);
    int choice;
    double amount;

    while (true) {
        displayMenu();
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Deposit
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;

            case 2: // Withdraw
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                if (!account.withdraw(amount)) {
                    std::cerr << "Withdrawal failed!" << std::endl;
                }
                break;

            case 3: // Check Balance
                std::cout << "Current balance: $" << account.getBalance() << std::endl;
                break;

            case 4: // View Transaction History
                account.printTransactionHistory();
                break;

            case 5: // Exit
                std::cout << "Exiting..." << std::endl;
                return 0;

            default:
                std::cerr << "Invalid choice! Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
