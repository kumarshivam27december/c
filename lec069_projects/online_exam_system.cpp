#include <iostream>
#include <string>
using namespace std;

class OnlineExamSystem {
private:
    string username, password;
    int score;

public:
    OnlineExamSystem() : score(0) {}

    bool login() {
        string inputUsername, inputPassword;
        cout << "Welcome to the Online Exam System\n";
        cout << "Please log in to proceed.\n";

        // Sample login credentials
        username = "admin";
        password = "12345";

        cout << "Enter Username: ";
        cin >> inputUsername;
        cout << "Enter Password: ";
        cin >> inputPassword;

        if (inputUsername == username && inputPassword == password) {
            cout << "Login Successful!\n";
            return true;
        } else {
            cout << "Invalid Username or Password!\n";
            return false;
        }
    }

    void quiz() {
        int answer;
        cout << "\nStart the quiz now:\n";

        // Question 1
        cout << "1. What is the capital of France?\n";
        cout << "1) Berlin  2) Madrid  3) Paris  4) Rome\n";
        cout << "Enter your answer: ";
        cin >> answer;
        if (answer == 3) score++;

        // Question 2
        cout << "2. Who wrote 'Hamlet'?\n";
        cout << "1) Charles Dickens  2) William Shakespeare  3) Mark Twain  4) J.K. Rowling\n";
        cout << "Enter your answer: ";
        cin >> answer;
        if (answer == 2) score++;

        // Question 3
        cout << "3. What is 2 + 2?\n";
        cout << "1) 3  2) 4  3) 5  4) 6\n";
        cout << "Enter your answer: ";
        cin >> answer;
        if (answer == 2) score++;
    }

    void displayResult() {
        cout << "\nQuiz completed!\n";
        cout << "Your score: " << score << "/3\n";

        if (score == 3) {
            cout << "Excellent!\n";
        } else if (score == 2) {
            cout << "Good job!\n";
        } else {
            cout << "Better luck next time!\n";
        }
    }
};

int main() {
    OnlineExamSystem exam;

    if (exam.login()) {
        exam.quiz();
        exam.displayResult();
    } else {
        cout << "Login failed. Exiting...\n";
    }

    return 0;
}
