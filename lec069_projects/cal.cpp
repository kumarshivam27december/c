#include <iostream>
#include <cmath> // For scientific operations
using namespace std;

// Function to display the menu
void showMenu() {
    cout << "=== Scientific Calculator ===" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Square root (√)" << endl;
    cout << "6. Power (^)" << endl;
    cout << "7. Sine (sin)" << endl;
    cout << "8. Cosine (cos)" << endl;
    cout << "9. Tangent (tan)" << endl;
    cout << "10. Logarithm (log)" << endl;
    cout << "11. Exit" << endl;
}

// Function to perform basic operations
double basicOperations(int choice, double num1, double num2) {
    switch (choice) {
        case 1: return num1 + num2;
        case 2: return num1 - num2;
        case 3: return num1 * num2;
        case 4: 
            if (num2 != 0) return num1 / num2;
            else {
                cout << "Error: Division by zero." << endl;
                return 0;
            }
        default: return 0;
    }
}

// Function for scientific operations
double scientificOperations(int choice, double num) {
    switch (choice) {
        case 5: return sqrt(num);
        case 6: {
            double exp;
            cout << "Enter the exponent: ";
            cin >> exp;
            return pow(num, exp);
        }
        case 7: return sin(num);
        case 8: return cos(num);
        case 9: return tan(num);
        case 10: return log(num);
        default: return 0;
    }
}

int main() {
    int choice;
    double num1, num2;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 11) {
            cout << "Exiting..." << endl;
            break;
        } else if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            double result = basicOperations(choice, num1, num2);
            cout << "Result: " << result << endl;
        } else if (choice >= 5 && choice <= 10) {
            cout << "Enter a number: ";
            cin >> num1;
            double result = scientificOperations(choice, num1);
            cout << "Result: " << result << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
