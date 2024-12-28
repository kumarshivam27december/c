#include <iostream>
#include <string>

using namespace std;

// Function to print a divider
void printDivider() {
    cout << "\n========================================\n";
}

// Introduction to the game
void intro() {
    printDivider();
    cout << "Welcome to 'The Cursed Island'!" << endl;
    cout << "You are a sailor who survived a shipwreck and found yourself stranded on a mysterious island.\n";
    cout << "The island is rumored to be cursed, and strange things start happening as night falls.\n";
    cout << "Your goal is to survive and find a way off the island.\n";
    printDivider();
    cout << "1. Explore the beach for supplies\n";
    cout << "2. Venture into the jungle\n";
    cout << "3. Build a shelter and wait for rescue\n";
}

// Beach path
void beachPath() {
    printDivider();
    cout << "You decide to explore the beach for supplies. The tide is coming in, and you find:\n";
    cout << "1. A washed-up crate with mysterious contents\n";
    cout << "2. A broken lifeboat\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The crate contains food and tools, but you accidentally disturb a sleeping sea serpent.\n";
        cout << "The serpent attacks, and you cannot escape.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You salvage parts from the lifeboat and use them to create a raft.\n";
        cout << "You successfully escape the island and return to civilization.\n";
        cout << "Congratulations! You survived.\n";
    }
}

// Jungle path
void junglePath() {
    printDivider();
    cout << "You venture into the jungle. The trees are dense, and you feel like you're being watched.\n";
    cout << "You discover:\n";
    cout << "1. An ancient temple with strange symbols\n";
    cout << "2. A hidden path leading deeper into the jungle\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You enter the temple and accidentally activate a trap. The temple collapses, and you are trapped forever.\n";
        cout << "Game Over.\n";
    } else {
        cout << "The hidden path leads you to a natural spring with clean water and fruit trees.\n";
        cout << "You survive for days and are eventually rescued by a passing ship.\n";
        cout << "Congratulations! You survived.\n";
    }
}

// Shelter path
void shelterPath() {
    printDivider();
    cout << "You decide to build a shelter and wait for rescue. As night falls, strange noises come from the jungle.\n";
    cout << "You must:\n";
    cout << "1. Investigate the noises\n";
    cout << "2. Stay hidden in your shelter\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You investigate the noises and encounter a group of hostile island creatures.\n";
        cout << "They attack, and you cannot defend yourself.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You stay hidden in your shelter. The creatures pass by, and you survive the night.\n";
        cout << "In the morning, a rescue ship spots you and takes you to safety.\n";
        cout << "Congratulations! You survived.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'The Cursed Island'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        beachPath();
    } else if (choice == 2) {
        junglePath();
    } else if (choice == 3) {
        shelterPath();
    } else {
        cout << "Invalid choice. Your indecision causes you to succumb to the island's dangers.\n";
        cout << "Game Over.\n";
    }

    return 0;
}
