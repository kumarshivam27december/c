#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));  // Use current time as seed for random generator
    
    int number = rand() % 100 + 1;  // Random number between 1 and 100
    int guess;
    int attempts = 0;
    int maxAttempts = 5;  // Limit the number of attempts
    
    cout << "Welcome to the Casino Number Guessing Game!" << endl;
    cout << "I have picked a number between 1 and 100." << endl;
    cout << "You have " << maxAttempts << " attempts to guess the correct number." << endl;

    // Loop until the player runs out of attempts or guesses the number
    while (attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high!" << endl;
        } else if (guess < number) {
            cout << "Too low!" << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts!" << endl;
            break;
        }
        
        if (attempts == maxAttempts) {
            cout << "Sorry, you've run out of attempts. The number was " << number << "." << endl;
        } else {
            cout << "Attempts left: " << maxAttempts - attempts << endl;
        }
    }

    return 0;
}
