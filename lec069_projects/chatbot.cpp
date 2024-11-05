#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to convert user input to lowercase (for case-insensitive comparison)
string toLowerCase(const string &input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to respond to different questions
void respondToUser(const string &userInput) {
    string input = toLowerCase(userInput);

    if (input == "hello" || input == "hi" || input == "hey") {
        cout << "Chatbot: Hello there! How can I assist you today?" << endl;
    }
    else if (input == "how are you") {
        cout << "Chatbot: I'm just a program, but thanks for asking! How are you?" << endl;
    }
    else if (input == "bye") {
        cout << "Chatbot: Goodbye! Have a nice day!" << endl;
    }
    else if (input == "what is your name") {
        cout << "Chatbot: I'm your friendly chatbot! You can call me Chatbot." << endl;
    }
    else if (input == "what is the time") {
        cout << "Chatbot: I don't have a clock, but I hope it's a good time!" << endl;
    }
    else if (input == "tell me a joke") {
        cout << "Chatbot: Why don't programmers like nature? It has too many bugs!" << endl;
    }
    else {
        cout << "Chatbot: I'm sorry, I didn't understand that. Could you ask something else?" << endl;
    }
}

int main() {
    string userInput;

    cout << "Chatbot: Hi! I'm a simple chatbot. Type 'bye' to exit." << endl;

    while (true) {
        cout << "You: ";
        getline(cin, userInput); // Get user input

        if (toLowerCase(userInput) == "bye") {
            respondToUser(userInput);
            break; // Exit the loop if user says 'bye'
        }

        respondToUser(userInput);
    }

    return 0;
}
