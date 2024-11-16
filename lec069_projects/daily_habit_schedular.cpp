#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // for formatting output
using namespace std;

struct Habit {
    string name;
    vector<bool> log;

    Habit(string habitName, int days) : name(habitName), log(days, false) {}

    void markDay(int day) {
        if (day >= 0 && day < log.size()) {
            log[day] = true;
        } else {
            cout << "Invalid day. Please enter a valid day number.\n";
        }
    }

    void display() const {
        cout << "Habit: " << name << "\n";
        cout << "Progress: ";
        for (bool completed : log) {
            cout << (completed ? "✔ " : "✘ ");
        }
        cout << "\n";
    }
};

int main() {
    int numDays;
    cout << "Enter the number of days to track your habits: ";
    cin >> numDays;

    vector<Habit> habits;
    int choice;

    do {
        cout << "\n1. Add a new habit\n";
        cout << "2. Mark a day as completed for a habit\n";
        cout << "3. Display habit progress\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string habitName;
            cout << "Enter the habit name: ";
            cin.ignore();
            getline(cin, habitName);
            habits.push_back(Habit(habitName, numDays));
        } else if (choice == 2) {
            int habitIndex, day;
            cout << "Enter the habit number (1 to " << habits.size() << "): ";
            cin >> habitIndex;
            if (habitIndex > 0 && habitIndex <= habits.size()) {
                cout << "Enter the day number to mark (1 to " << numDays << "): ";
                cin >> day;
                habits[habitIndex - 1].markDay(day - 1);
            } else {
                cout << "Invalid habit number.\n";
            }
        } else if (choice == 3) {
            for (int i = 0; i < habits.size(); ++i) {
                cout << "\nHabit " << (i + 1) << ":\n";
                habits[i].display();
            }
        } else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    cout << "Goodbye! Keep tracking your habits.\n";
    return 0;
}
