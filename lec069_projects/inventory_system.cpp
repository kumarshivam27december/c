#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent an inventory item
struct Item {
    string name;
    int quantity;
};

// Function to add an item to the inventory
void addItem(vector<Item>& inventory, const string& name, int quantity) {
    for (auto& item : inventory) {
        if (item.name == name) {
            item.quantity += quantity;
            return;
        }
    }
    inventory.push_back({name, quantity});
}

// Function to remove an item from the inventory
void removeItem(vector<Item>& inventory, const string& name, int quantity) {
    for (auto& item : inventory) {
        if (item.name == name) {
            if (item.quantity >= quantity) {
                item.quantity -= quantity;
                if (item.quantity == 0) {
                    // Remove item if quantity is zero
                    inventory.erase(remove(inventory.begin(), inventory.end(), item), inventory.end());
                }
            } else {
                cout << "Error: Not enough quantity to remove." << endl;
            }
            return;
        }
    }
    cout << "Error: Item not found." << endl;
}

// Function to display the inventory
void displayInventory(const vector<Item>& inventory) {
    cout << "Inventory:" << endl;
    for (const auto& item : inventory) {
        cout << "Item: " << item.name << ", Quantity: " << item.quantity << endl;
    }
}

int main() {
    vector<Item> inventory;
    int choice;
    string name;
    int quantity;

    do {
        cout << "\nInventory System Menu:" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Display Inventory" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character left in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                getline(cin, name);
                cout << "Enter quantity: ";
                cin >> quantity;
                addItem(inventory, name, quantity);
                break;
            case 2:
                cout << "Enter item name: ";
                getline(cin, name);
                cout << "Enter quantity to remove: ";
                cin >> quantity;
                removeItem(inventory, name, quantity);
                break;
            case 3:
                displayInventory(inventory);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
