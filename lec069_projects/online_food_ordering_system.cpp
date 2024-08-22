#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Struct to represent a food item
struct FoodItem {
    string name;
    double price;
};

// Function to display the menu
void displayMenu(const vector<FoodItem>& menu) {
    cout << "Menu:" << endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].name << " - $" << fixed << setprecision(2) << menu[i].price << endl;
    }
}

// Function to process the order
double processOrder(const vector<FoodItem>& menu) {
    int choice;
    double total = 0.0;

    cout << "Enter the number of items you want to order (0 to finish): ";
    while (true) {
        cin >> choice;
        if (choice == 0) break;
        if (choice < 1 || choice > menu.size()) {
            cout << "Invalid choice. Please enter a number between 1 and " << menu.size() << ": ";
            continue;
        }
        total += menu[choice - 1].price;
        cout << "Item added. Enter the number of items you want to order (0 to finish): ";
    }
    return total;
}

int main() {
    // Define the menu
    vector<FoodItem> menu = {
        {"Pizza", 12.99},
        {"Burger", 8.49},
        {"Salad", 5.99},
        {"Pasta", 10.99},
        {"Soda", 1.99}
    };

    cout << "Welcome to the Online Food Ordering System!" << endl;

    while (true) {
        displayMenu(menu);

        double total = processOrder(menu);
        cout << "Your total is: $" << fixed << setprecision(2) << total << endl;

        char again;
        cout << "Would you like to order again? (y/n): ";
        cin >> again;

        if (again != 'y' && again != 'Y') break;
    }

    cout << "Thank you for using the Online Food Ordering System!" << endl;
    return 0;
}
