#include <iostream>
#include <string>

using namespace std;

// Function to print a divider line for readability
void printDivider() {
    cout << "\n=======================================\n";
}

// Introduction to the game
void intro() {
    printDivider();
    cout << "You stand before an old, abandoned mansion under a stormy sky.\n";
    cout << "Lightning flashes, and for a moment, you think you see a shadow\n";
    cout << "moving behind one of the windows.\n";
    cout << "Despite your fear, curiosity compels you to enter.\n";
    cout << "What will you do?\n";
    printDivider();
    cout << "1. Enter the mansion\n";
    cout << "2. Run away\n";
}

// The grand foyer scene
void grandFoyer() {
    printDivider();
    cout << "You step into the grand foyer of the mansion.\n";
    cout << "Cobwebs hang from the chandeliers, and the air smells of decay.\n";
    cout << "A grand staircase leads up, and two doors stand before you.\n";
    cout << "1. Go upstairs\n";
    cout << "2. Open the door on the left\n";
    cout << "3. Open the door on the right\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You climb the creaky stairs. Suddenly, a cold hand grips your ankle!\n";
        cout << "You scream and fall backward... everything goes dark.\n";
        cout << "Game Over.\n";
    } else if (choice == 2) {
        cout << "You open the left door and find a dusty library filled with ancient books.\n";
        cout << "A strange book catches your eye.\n";
        cout << "1. Read the book\n";
        cout << "2. Leave the library\n";

        int libraryChoice;
        cin >> libraryChoice;

        if (libraryChoice == 1) {
            cout << "As you read the book, a ghostly voice whispers secrets of the mansion.\n";
            cout << "You feel wiser and more confident. This knowledge might save you.\n";
        } else {
            cout << "You decide not to touch anything and quietly leave the library.\n";
        }
    } else if (choice == 3) {
        cout << "You open the door on the right and find a dusty kitchen.\n";
        cout << "A strange, rotten smell fills the room, and you hear footsteps behind you.\n";
        cout << "You turn around, but no one is there...\n";
    } else {
        cout << "Invalid choice! A cold wind blows, and you feel the walls closing in...\n";
        cout << "Game Over.\n";
    }
}

// The basement scene
void basementScene() {
    printDivider();
    cout << "You discover a hidden trapdoor in the floor.\n";
    cout << "1. Open the trapdoor and go down\n";
    cout << "2. Ignore it and explore the rest of the house\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You climb down into a dark, damp basement.\n";
        cout << "A chilling voice whispers: 'You shouldn't be here...'\n";
        cout << "Suddenly, the trapdoor slams shut above you.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You decide to stay away from the basement. Wise choice!\n";
        cout << "You hear faint music coming from upstairs and decide to investigate.\n";
    }
}

// The final choice
void finalChoice() {
    printDivider();
    cout << "You reach a grand ballroom where ghostly figures are dancing.\n";
    cout << "A ghost approaches and asks you to join the dance.\n";
    cout << "1. Join the ghostly dance\n";
    cout << "2. Refuse and run for the exit\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You join the dance, feeling yourself fade away...\n";
        cout << "You become one of the ghosts, forever trapped in the mansion.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You sprint for the exit, the ghosts screaming behind you.\n";
        cout << "You burst through the doors into the stormy night.\n";
        cout << "You've escaped the haunted house! Congratulations!\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'The Haunted House' Adventure Game!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        grandFoyer();
        basementScene();
        finalChoice();
    } else {
        cout << "You run away from the mansion. Some mysteries are better left unsolved.\n";
        cout << "Game Over.\n";
    }

    return 0;
}
