/*

important games script based game

creating a text  based game



1.create a KBC  game
2.create a cid game (crime related puzzle related)


////just creating a text based game with no good looking quality
--using function switch and loops





///for example for kbc game

#include <iostream>
using namespace std;

void askQuestion(string question, string optionA, string optionB, string optionC, string optionD, char correctAnswer, int& score) {
    cout << question << endl;
    cout << "A. " << optionA << endl;
    cout << "B. " << optionB << endl;
    cout << "C. " << optionC << endl;
    cout << "D. " << optionD << endl;

    char userAnswer;
    cout << "Your answer: ";
    cin >> userAnswer;

    if (userAnswer == correctAnswer) {
        cout << "Correct!" << endl;
        score += 1000;
    } else {
        cout << "Incorrect! The correct answer is " << correctAnswer << endl;
    }
}

int main() {
    int score = 0;
    char play;
    do {
        cout << "Welcome to Who Wants to Be a Millionaire!" << endl;
        cout << "Question 1:" << endl;
        askQuestion("What is the capital of France?", "London", "Paris", "Berlin", "Rome", 'B', score);

        cout << endl << "Your total score is: " << score << " points." << endl;
        cout << "Do you want to play again? (Y/N): ";
        cin >> play;
    } while (play == 'Y' || play == 'y');

    cout << "Thanks for playing! Your final score is: " << score << " points." << endl;

    return 0;
}


*/


#include <iostream>
using namespace std;

void askQuestion(string question, string optionA, string optionB, string optionC, string optionD, char correctAnswer, int& score) {
    cout << question << endl;
    cout << "A. " << optionA << endl;
    cout << "B. " << optionB << endl;
    cout << "C. " << optionC << endl;
    cout << "D. " << optionD << endl;

    char userAnswer;
    cout << "Your answer: ";
    cin >> userAnswer;

    if (userAnswer == correctAnswer) {
        cout << "Correct!" << endl;
        score += 1000;
    } else {
        cout << "Incorrect! The correct answer is " << correctAnswer << endl;
    }
}

int main() {
    int score = 0;
    char play;
    do {
        cout << "Welcome to Who Wants to Be a Millionaire!" << endl;
        cout << "Question 1:" << endl;
        askQuestion("What is the capital of France?", "London", "Paris", "Berlin", "Rome", 'B', score);

        cout << endl << "Your total score is: " << score << " points." << endl;
        cout << "Do you want to play again? (Y/N): ";
        cin >> play;
    } while (play == 'Y' || play == 'y');

    cout << "Thanks for playing! Your final score is: " << score << " points." << endl;

    return 0;
}

