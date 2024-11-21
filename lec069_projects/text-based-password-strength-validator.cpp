#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

int calculateStrength(const std::string& password) {
    int score = 0;

    // Check length
    if (password.length() >= 8) score += 2; // Strong length
    else if (password.length() >= 5) score += 1; // Medium length

    // Check character variety
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        if (isupper(ch)) hasUpper = true;
        if (isdigit(ch)) hasDigit = true;
        if (ispunct(ch)) hasSpecial = true;
    }

    score += (hasLower + hasUpper + hasDigit + hasSpecial);

    // Check for common weaknesses
    std::string commonPasswords[] = {"password", "123456", "qwerty", "letmein"};
    for (const auto& weak : commonPasswords) {
        if (password.find(weak) != std::string::npos) {
            score = std::max(0, score - 3); // Deduct heavily
        }
    }

    return score;
}

int main() {
    std::string password;
    std::cout << "Enter a password to evaluate its strength: ";
    std::cin >> password;

    int strength = calculateStrength(password);

    std::cout << "Password strength: ";
    if (strength <= 2) std::cout << "Weak";
    else if (strength <= 4) std::cout << "Moderate";
    else std::cout << "Strong";

    std::cout << " (Score: " << strength << ")\n";
    return 0;
}
