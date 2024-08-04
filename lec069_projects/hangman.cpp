#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class HangmanGame {
private:
    string word;
    string guessedWord;
    int attemptsRemaining;
    vector<char> guessedLetters;

    void initializeGame() {
        word = "hangman";  // The word to guess (can be changed or randomized)
        guessedWord = string(word.length(), '_');
        attemptsRemaining = 6;  // Number of attempts
        guessedLetters.clear();
    }

    void displayStatus() const {
        cout << "Word to guess: " << guessedWord << endl;
        cout << "Attempts remaining: " << attemptsRemaining << endl;
        cout << "Guessed letters: ";
        for (char c : guessedLetters) {
            cout << c << ' ';
        }
        cout << endl;
    }

    void processGuess(char guess) {
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You've already guessed that letter." << endl;
            return;
        }

        guessedLetters.push_back(guess);

        if (word.find(guess) != string::npos) {
            for (size_t i = 0; i < word.length(); ++i) {
                if (word[i] == guess) {
                    guessedWord[i] = guess;
                }
            }
            cout << "Good guess!" << endl;
        } else {
            --attemptsRemaining;
            cout << "Wrong guess." << endl;
        }
    }

    bool isWordGuessed() const {
        return guessedWord == word;
    }

    bool isGameOver() const {
        return attemptsRemaining <= 0 || isWordGuessed();
    }

public:
    void play() {
        initializeGame();
        char guess;

        while (!isGameOver()) {
            displayStatus();
            cout << "Enter your guess (a single letter): ";
            cin >> guess;
            guess = tolower(guess);  // Convert to lowercase to be case-insensitive
            processGuess(guess);
        }

        if (isWordGuessed()) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
        } else {
            cout << "Game over! The word was: " << word << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));  // Seed random number generator
    HangmanGame game;
    game.play();
    return 0;
}
