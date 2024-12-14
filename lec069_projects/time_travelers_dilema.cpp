#include <iostream>
#include <string>

using namespace std;

// Function to print a divider line for readability
void printDivider() {
    cout << "\n========================================\n";
}

// Introduction to the game
void intro() {
    printDivider();
    cout << "You are Dr. Alex Wright, a brilliant scientist who has just invented a time machine.\n";
    cout << "After years of research, the moment has come to test your invention.\n";
    cout << "The controls are set, and the machine hums to life.\n";
    cout << "Where will you go?\n";
    printDivider();
    cout << "1. Travel to the past\n";
    cout << "2. Travel to the future\n";
}

// The past scenario
void travelToPast() {
    printDivider();
    cout << "You set the machine for the year 1850 and activate it.\n";
    cout << "In a flash of light, you find yourself standing in a bustling 19th-century town.\n";
    cout << "You notice two paths ahead.\n";
    cout << "1. Visit the local library to learn about the era\n";
    cout << "2. Explore the forest on the outskirts of town\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You enter the library and immerse yourself in history books.\n";
        cout << "You learn valuable insights that could change the course of history.\n";
        cout << "You return to your time with newfound knowledge!\n";
    } else {
        cout << "You explore the forest, but a sudden storm traps you in the wilderness.\n";
        cout << "Unable to find your way back, you're lost in time forever.\n";
        cout << "Game Over.\n";
    }
}

// The future scenario
void travelToFuture() {
    printDivider();
    cout << "You set the machine for the year 2200 and activate it.\n";
    cout << "In a bright flash, you arrive in a futuristic city filled with flying cars and towering skyscrapers.\n";
    cout << "A robot greets you and offers to show you around.\n";
    cout << "1. Follow the robot and explore the city\n";
    cout << "2. Decline the offer and investigate on your own\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The robot shows you the wonders of the future.\n";
        cout << "You discover advanced technology that could revolutionize your time.\n";
        cout << "You return home with futuristic knowledge!\n";
    } else {
        cout << "You wander alone and accidentally enter a restricted zone.\n";
        cout << "Security drones apprehend you, and you're trapped in the future forever.\n";
        cout << "Game Over.\n";
    }
}

// The main function
int main() {
    cout << "Welcome to 'The Time Traveler's Dilemma'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        travelToPast();
    } else {
        travelToFuture();
    }

    return 0;
}
