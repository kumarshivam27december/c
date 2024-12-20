#include <iostream>
#include <string>

using namespace std;

// Function to print a divider for readability
void printDivider() {
    cout << "\n========================================\n";
}

// Introduction to the game
void intro() {
    printDivider();
    cout << "You are a daring adventurer seeking the legendary treasure of Skull Island.\n";
    cout << "Your ship drops anchor, and you step onto the sandy beach.\n";
    cout << "Palm trees sway in the breeze, and you hear distant drums.\n";
    cout << "Do you dare to search for the treasure?\n";
    printDivider();
    cout << "1. Head into the jungle\n";
    cout << "2. Follow the coastline\n";
}

// Jungle adventure
void jungleAdventure() {
    printDivider();
    cout << "You push through the dense jungle, the air thick with humidity.\n";
    cout << "You hear rustling in the bushes.\n";
    cout << "1. Investigate the sound\n";
    cout << "2. Ignore it and keep moving\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "A venomous snake lunges at you! You barely dodge it and continue your journey.\n";
        cout << "You stumble upon an ancient stone temple hidden in the jungle.\n";
        cout << "1. Enter the temple\n";
        cout << "2. Walk around the temple\n";

        int templeChoice;
        cin >> templeChoice;

        if (templeChoice == 1) {
            cout << "Inside the temple, you find a golden chest filled with treasure!\n";
            cout << "Congratulations! You've found the treasure of Skull Island!\n";
        } else {
            cout << "You walk around the temple and fall into a concealed pit trap.\n";
            cout << "Game Over.\n";
        }
    } else {
        cout << "You ignore the noise and keep walking.\n";
        cout << "Unfortunately, you get lost and wander aimlessly until nightfall.\n";
        cout << "Game Over.\n";
    }
}

// Coastline adventure
void coastlineAdventure() {
    printDivider();
    cout << "You decide to follow the coastline, the waves lapping at your feet.\n";
    cout << "You see a cave entrance up ahead.\n";
    cout << "1. Enter the cave\n";
    cout << "2. Continue along the beach\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You enter the cave and find it filled with shimmering crystals.\n";
        cout << "Deeper inside, you spot a treasure chest guarded by a sleeping pirate ghost.\n";
        cout << "1. Sneak past the ghost and grab the treasure\n";
        cout << "2. Leave the cave quietly\n";

        int caveChoice;
        cin >> caveChoice;

        if (caveChoice == 1) {
            cout << "You carefully sneak past the ghost and grab the treasure chest.\n";
            cout << "You escape the cave and make your way back to the ship.\n";
            cout << "Congratulations! You've claimed the treasure of Skull Island!\n";
        } else {
            cout << "You leave the cave quietly, but the ghost senses you and curses you.\n";
            cout << "Game Over.\n";
        }
    } else {
        cout << "You continue along the beach and find nothing but sand and seashells.\n";
        cout << "As the sun sets, you realize you've missed your chance.\n";
        cout << "Game Over.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'The Treasure of Skull Island'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        jungleAdventure();
    } else {
        coastlineAdventure();
    }

    return 0;
}
