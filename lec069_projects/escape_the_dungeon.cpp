#include <iostream>
#include <string>

using namespace std;

void printDivider() {
    cout << "\n========================\n";
}

void intro() {
    cout << "You wake up in a dark dungeon, the smell of damp stone filling the air.\n";
    cout << "You have no memory of how you got here. The only light comes from a torch\n";
    cout << "flickering on the wall, and you hear faint sounds echoing from deep within.\n";
    cout << "What will you do?\n";
}

void roomWithChest() {
    printDivider();
    cout << "You find a wooden chest in the corner of the room. It's slightly open.\n";
    cout << "1. Open the chest\n";
    cout << "2. Ignore it and move on\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Inside the chest, you find a rusty sword. It might come in handy.\n";
        cout << "You take the sword and move on.\n";
    } else {
        cout << "You decide not to risk opening the chest and continue onward.\n";
    }
}

void mysteriousFigure() {
    printDivider();
    cout << "As you proceed, a hooded figure appears in the hallway ahead.\n";
    cout << "They seem to be waiting for you.\n";
    cout << "1. Talk to the figure\n";
    cout << "2. Attack the figure\n";
    cout << "3. Run away\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The figure speaks: 'You're not supposed to be here.'\n";
        cout << "They hand you a map and disappear into the shadows.\n";
        cout << "You now have a way out of the dungeon.\n";
    } else if (choice == 2) {
        cout << "You swing at the figure, but they dodge effortlessly.\n";
        cout << "The figure vanishes into the darkness, leaving you alone.\n";
        cout << "You continue deeper into the dungeon.\n";
    } else {
        cout << "You turn and run back the way you came, stumbling upon another path.\n";
    }
}

void finalDecision() {
    printDivider();
    cout << "You reach a massive iron door with strange runes carved into it.\n";
    cout << "It seems to be the way out, but it's locked.\n";
    cout << "There is a lever on the wall nearby and a glowing crystal on the floor.\n";
    cout << "1. Pull the lever\n";
    cout << "2. Pick up the crystal\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The lever activates a trap, and the ceiling begins to collapse!\n";
        cout << "You try to escape, but the falling stones block your way...\n";
        cout << "Game Over.\n";
    } else {
        cout << "The crystal fits perfectly into a slot on the door.\n";
        cout << "With a loud rumble, the door swings open, and sunlight floods in.\n";
        cout << "You've escaped the dungeon! Congratulations!\n";
    }
}

int main() {
    cout << "Welcome to 'Escape the Dungeon'!" << endl;
    printDivider();

    intro();

    cout << "1. Pick up the torch\n";
    cout << "2. Walk into the darkness\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You pick up the torch, its warm light illuminating the room.\n";
        roomWithChest();
    } else {
        cout << "You step into the darkness, stumbling over unseen objects.\n";
        cout << "You eventually reach another room.\n";
    }

    mysteriousFigure();
    finalDecision();

    return 0;
}
