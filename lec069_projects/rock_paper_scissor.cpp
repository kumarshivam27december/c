#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK = 1, PAPER, SCISSORS };

Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3 + 1);
}

void printChoice(Choice choice) {
    switch (choice) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }
}

Choice getPlayerChoice() {
    int choice;
    cout << "Enter your choice (1: Rock, 2: Paper, 3: Scissors): ";
    cin >> choice;
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin >> choice;
    }
    return static_cast<Choice>(choice);
}

void determineWinner(Choice player, Choice computer) {
    if (player == computer) {
        cout << "It's a tie!" << endl;
    } else if ((player == ROCK && computer == SCISSORS) ||
               (player == PAPER && computer == ROCK) ||
               (player == SCISSORS && computer == PAPER)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    cout << "Rock, Paper, Scissors Game!" << endl;
    
    Choice playerChoice = getPlayerChoice();
    Choice computerChoice = getComputerChoice();
    
    cout << "You chose: ";
    printChoice(playerChoice);
    cout << endl;
    
    cout << "Computer chose: ";
    printChoice(computerChoice);
    cout << endl;

    determineWinner(playerChoice, computerChoice);

    return 0;
}
