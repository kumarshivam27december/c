#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Expense {
    string description;
    double amount;
    string category;
};

class ExpenseTracker {
private:
    vector<Expense> expenses;

public:
    void addExpense(const string& description, double amount, const string& category) {
        expenses.push_back({description, amount, category});
    }

    void viewExpenses() {
        cout << fixed << setprecision(2);
        for (const auto& expense : expenses) {
            cout << expense.description << " | " << expense.amount << " | " << expense.category << endl;
        }
    }

    void monthlySummary() {
        double total = 0;
        cout << "Category Breakdown:\n";
        // You can enhance this part to categorize expenses and summarize
        for (const auto& expense : expenses) {
            total += expense.amount;
        }
        cout << "Total Expenses: " << total << endl;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        for (const auto& expense : expenses) {
            file << expense.description << "," << expense.amount << "," << expense.category << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string description, category;
            double amount;
            getline(ss, description, ',');
            ss >> amount;
            ss.ignore(); // ignore comma
            getline(ss, category);
            addExpense(description, amount, category);
        }
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.loadFromFile("expenses.txt");

    while (true) {
        cout << "1. Add Expense\n2. View Expenses\n3. Monthly Summary\n4. Save and Exit\nChoose an option: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Ignore the newline character after integer input

        if (choice == 1) {
            string description, category;
            double amount;
            cout << "Enter description: ";
            getline(cin, description);
            cout << "Enter amount: ";
            cin >> amount;
            cin.ignore();
            cout << "Enter category: ";
            getline(cin, category);
            tracker.addExpense(description, amount, category);
        } else if (choice == 2) {
            tracker.viewExpenses();
        } else if (choice == 3) {
            tracker.monthlySummary();
        } else if (choice == 4) {
            tracker.saveToFile("expenses.txt");
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }
    return 0;
}
