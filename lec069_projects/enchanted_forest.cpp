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
    cout << "You find yourself at the edge of an enchanted forest.\n";
    cout << "Legends say the forest holds treasures, magic, and danger.\n";
    cout << "The air hums with strange energy, and a narrow path leads into the trees.\n";
    cout << "Do you dare enter the Enchanted Forest?\n";
    printDivider();
    cout << "1. Enter the forest\n";
    cout << "2. Turn back\n";
}

// The mystical glade scene
void mysticalGlade() {
    printDivider();
    cout << "You follow the path and arrive at a glowing glade.\n";
    cout << "A fairy appears and offers you a gift.\n";
    cout << "1. Accept the fairy's gift\n";
    cout << "2. Politely decline and move on\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The fairy grants you a magical shield that protects you from harm.\n";
    } else {
        cout << "You decline the gift and continue cautiously.\n";
    }
}

// The dark cave scene
void darkCave() {
    printDivider();
    cout << "You come across a dark cave entrance. You hear growling from within.\n";
    cout << "1. Enter the cave\n";
    cout << "2. Avoid the cave and continue on the path\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You bravely enter the cave and encounter a sleeping dragon!\n";
        cout << "1. Try to steal some treasure\n";
        cout << "2. Sneak out quietly\n";

        int caveChoice;
        cin >> caveChoice;

        if (caveChoice == 1) {
            cout << "The dragon awakens and breathes fire! You barely escape with your life.\n";
            cout << "Your clothes are singed, but you manage to grab a small gem.\n";
        } else {
            cout << "You sneak out quietly and continue your journey, avoiding danger.\n";
        }
    } else {
        cout << "You decide not to risk it and stick to the path. The forest grows denser.\n";
    }
}

// The ancient tree scene
void ancientTree() {
    printDivider();
    cout << "You find an ancient tree with a face carved into its bark.\n";
    cout << "It speaks: 'Answer my riddle, and I shall grant you safe passage.'\n";
    cout << "Riddle: What has roots as nobody sees, is taller than trees,\n";
    cout << "up, up it goes, and yet it never grows?\n";
    cout << "\n1. A Mountain\n2. A River\n3. A Shadow\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The tree smiles. 'Correct! You may pass safely.'\n";
    } else {
        cout << "The tree frowns. 'Incorrect! Beware the dangers ahead.'\n";
    }
}

// The final encounter scene
void finalEncounter() {
    printDivider();
    cout << "You finally reach a clearing where a treasure chest glitters in the sunlight.\n";
    cout << "But a mystical guardian blocks your path!\n";
    cout << "1. Fight the guardian\n";
    cout << "2. Talk to the guardian\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You charge at the guardian, but it overpowers you.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You speak to the guardian, who respects your wisdom.\n";
        cout << "The guardian steps aside, and you claim the treasure!\n";
        cout << "Congratulations, you have won the game!\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'The Enchanted Forest' Adventure Game!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        mysticalGlade();
        darkCave();
        ancientTree();
        finalEncounter();
    } else {
        cout << "You decide the forest is too dangerous and head home.\n";
        cout << "Maybe another day you'll find the courage to explore.\n";
        cout << "Game Over.\n";
    }

    return 0;
}
