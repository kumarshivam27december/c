#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Function to check password strength
string checkPasswordStrength(const string& password) {
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        else if (isupper(ch)) hasUpper = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSpecial = true;
    }

    if (password.length() < 8) 
        return "Weak: Too short (minimum 8 characters)";
    else if (hasLower && hasUpper && hasDigit && hasSpecial) 
        return "Strong: Meets all criteria";
    else if ((hasLower || hasUpper) && hasDigit && hasSpecial) 
        return "Moderate: Missing some complexity";
    else 
        return "Weak: Lacks diversity in characters";
}

// Function to generate a random password
string generatePassword(int length) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string special = "!@#$%^&*()-_=+[]{}|;:',.<>?/";
    const string allChars = lower + upper + digits + special;

    string password;
    srand(time(0));

    // Ensure password has at least one of each type of character
    password += lower[rand() % lower.length()];
    password += upper[rand() % upper.length()];
    password += digits[rand() % digits.length()];
    password += special[rand() % special.length()];

    // Fill the rest of the password with random characters
    for (int i = 4; i < length; ++i) {
        password += allChars[rand() % allChars.length()];
    }

    // Shuffle the password to randomize character order
    random_shuffle(password.begin(), password.end());
    return password;
}

int main() {
    int choice;
    cout << "Password Strength Checker and Generator\n";
    cout << "1. Check password strength\n";
    cout << "2. Generate strong password\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        string password;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Password strength: " << checkPasswordStrength(password) << endl;
    } else if (choice == 2) {
        int length;
        cout << "Enter desired password length (minimum 8): ";
        cin >> length;

        if (length < 8) {
            cout << "Password length must be at least 8 characters.\n";
        } else {
            string strongPassword = generatePassword(length);
            cout << "Generated strong password: " << strongPassword << endl;
        }
    } else {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
