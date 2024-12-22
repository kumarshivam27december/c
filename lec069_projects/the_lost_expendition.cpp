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
    cout << "You are an explorer lost deep in the heart of a dangerous jungle.\n";
    cout << "Your expedition was separated during a storm, and now you must find your way back to safety.\n";
    cout << "Ahead of you lie three paths, each with its own perils.\n";
    printDivider();
    cout << "1. Take the narrow trail through the dense undergrowth\n";
    cout << "2. Follow the river downstream\n";
    cout << "3. Climb the hill to get a better view\n";
}

// Path: Narrow trail
void narrowTrail() {
    printDivider();
    cout << "You push through the dense undergrowth. The jungle is alive with sounds, but danger lurks everywhere.\n";
    cout << "You stumble upon a snake blocking your path.\n";
    cout << "1. Try to scare it away\n";
    cout << "2. Carefully walk around it\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The snake lunges at you, and you are bitten. You collapse to the ground.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You carefully walk around the snake and find a hidden trail that leads to safety.\n";
        cout << "Congratulations! You survived.\n";
    }
}

// Path: River
void riverPath() {
    printDivider();
    cout << "You decide to follow the river downstream. The sound of water is calming, but you must stay alert.\n";
    cout << "You come across a broken raft on the riverbank.\n";
    cout << "1. Repair the raft and use it to travel downriver\n";
    cout << "2. Continue walking along the riverbank\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You repair the raft and set sail, but the river grows turbulent.\n";
        cout << "The raft capsizes, and you are swept away by the current.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You continue walking along the riverbank and find a fishing village where you are rescued.\n";
        cout << "Congratulations! You survived.\n";
    }
}

// Path: Hill
void hillPath() {
    printDivider();
    cout << "You climb the hill to get a better view. The climb is steep, but you are determined.\n";
    cout << "At the top, you see smoke rising in the distance, indicating a campsite.\n";
    cout << "1. Head toward the smoke\n";
    cout << "2. Stay on the hill to signal for help\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You head toward the smoke and find a friendly group of explorers who guide you to safety.\n";
        cout << "Congratulations! You survived.\n";
    } else {
        cout << "You wait on the hill, but night falls, and the cold takes its toll.\n";
        cout << "Game Over.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'The Lost Expedition'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        narrowTrail();
    } else if (choice == 2) {
        riverPath();
    } else if (choice == 3) {
        hillPath();
    } else {
        cout << "Invalid choice. You wander aimlessly until you are lost forever.\n";
        cout << "Game Over.\n";
    }

    return 0;
}
