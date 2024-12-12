#include <iostream>
#include <string>

using namespace std;

// Function to print a divider line for readability
void printDivider() {
    cout << "\n----------------------------------------\n";
}

// Introduction to the game
void intro() {
    printDivider();
    cout << "You stand before a crumbling mansion, known to be haunted for decades.\n";
    cout << "Thunder rumbles, and lightning flashes, revealing the twisted iron gates.\n";
    cout << "The door creaks open by itself, inviting you inside.\n";
    cout << "Do you dare to enter?\n";
    printDivider();
    cout << "1. Enter the mansion\n";
    cout << "2. Turn back and leave\n";
}

// Explore the grand hall
void grandHall() {
    printDivider();
    cout << "You step into the grand hall. Dust covers everything, and cobwebs hang from the ceiling.\n";
    cout << "A staircase leads up, and two doors lead to the left and right.\n";
    cout << "1. Go upstairs\n";
    cout << "2. Enter the door to the left\n";
    cout << "3. Enter the door to the right\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You ascend the creaking stairs. A cold wind brushes past you...\n";
        cout << "A ghostly figure appears at the top, blocking your way!\n";
        cout << "1. Confront the ghost\n";
        cout << "2. Run back downstairs\n";

        int ghostChoice;
        cin >> ghostChoice;

        if (ghostChoice == 1) {
            cout << "You confront the ghost bravely. The ghost vanishes, impressed by your courage.\n";
        } else {
            cout << "You stumble back down the stairs in terror. The ghost's laughter echoes behind you.\n";
        }
    } else if (choice == 2) {
        cout << "You enter the left room and find an old library.\n";
        cout << "A dusty book on a pedestal seems to glow faintly.\n";
        cout << "1. Read the book\n";
        cout << "2. Leave the library\n";

        int libraryChoice;
        cin >> libraryChoice;

        if (libraryChoice == 1) {
            cout << "As you read the book, a vision of the mansion's past floods your mind.\n";
            cout << "You gain knowledge of a hidden passage!\n";
        } else {
            cout << "You leave the library, feeling uneasy.\n";
        }
    } else {
        cout << "You enter the right room and fall into a hidden trapdoor!\n";
        cout << "You land in a dark basement. The door closes above you.\n";
        cout << "Game Over.\n";
    }
}

// The final escape
void finalEscape() {
    printDivider();
    cout << "You discover a hidden passage leading to a secret door.\n";
    cout << "You hear footsteps approaching from behind.\n";
    cout << "1. Open the secret door and escape\n";
    cout << "2. Hide and wait\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You burst through the secret door and find yourself outside the mansion.\n";
        cout << "The storm clears, and you breathe in the fresh air of freedom.\n";
        cout << "Congratulations! You have escaped the haunted mansion!\n";
    } else {
        cout << "You hide, but the ghost finds you. You are trapped forever in the mansion.\n";
        cout << "Game Over.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'Mystery of the Haunted Mansion'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        grandHall();
        finalEscape();
    } else {
        cout << "You decide the mansion is too dangerous and walk away.\n";
        cout << "Perhaps some mysteries are best left unsolved.\n";
        cout << "Game Over.\n";
    }

    return 0;
}
