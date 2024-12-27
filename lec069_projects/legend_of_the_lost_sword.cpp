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
    cout << "Welcome to 'Legend of the Lost Sword'!" << endl;
    cout << "You are a courageous adventurer in a mystical medieval land.\n";
    cout << "A legend speaks of a powerful sword hidden deep in the Forest of Shadows.\n";
    cout << "This sword is said to grant unmatched power to its wielder.\n";
    cout << "Your goal is to retrieve the sword and return safely to your village.\n";
    printDivider();
    cout << "1. Enter the Forest of Shadows\n";
    cout << "2. Seek advice from the village elder\n";
    cout << "3. Prepare by gathering supplies\n";
}

// Forest path
void forestPath() {
    printDivider();
    cout << "You bravely enter the Forest of Shadows. The air grows colder as the trees thicken.\n";
    cout << "You hear eerie sounds and notice two paths ahead.\n";
    cout << "1. Take the dark, narrow path\n";
    cout << "2. Take the well-lit but overgrown path\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You follow the dark path and encounter a giant spider!\n";
        cout << "With no weapon strong enough, you are caught in its web.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You take the well-lit path and discover an ancient shrine.\n";
        cout << "The shrine reveals a map leading to the sword's location.\n";
        cout << "You safely retrieve the sword and return as a hero.\n";
        cout << "Congratulations! You completed your quest.\n";
    }
}

// Village elder path
void villageElderPath() {
    printDivider();
    cout << "You visit the village elder, who shares ancient wisdom about the sword.\n";
    cout << "He warns of a cursed guardian protecting the sword.\n";
    cout << "1. Heed his advice and ask for a protective charm\n";
    cout << "2. Ignore his warnings and set out immediately\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The elder gives you a protective charm. Armed with it, you avoid the curse.\n";
        cout << "You retrieve the sword and become a legend in your land.\n";
        cout << "Congratulations! You completed your quest.\n";
    } else {
        cout << "You set out immediately but fall victim to the guardian's curse.\n";
        cout << "Your quest ends in failure.\n";
        cout << "Game Over.\n";
    }
}

// Supplies path
void suppliesPath() {
    printDivider();
    cout << "You decide to gather supplies before entering the forest.\n";
    cout << "You find a merchant selling a magical lantern and a healing potion.\n";
    cout << "1. Buy the magical lantern\n";
    cout << "2. Buy the healing potion\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "With the magical lantern, you easily navigate the forest's darkness.\n";
        cout << "You discover the sword and return home victorious.\n";
        cout << "Congratulations! You completed your quest.\n";
    } else {
        cout << "You buy the healing potion but get lost in the forest.\n";
        cout << "Despite your efforts, you never find the sword.\n";
        cout << "Game Over.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'Legend of the Lost Sword'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        forestPath();
    } else if (choice == 2) {
        villageElderPath();
    } else if (choice == 3) {
        suppliesPath();
    } else {
        cout << "Invalid choice. You hesitate too long and miss your chance to begin the quest.\n";
        cout << "Game Over.\n";
    }

    return 0;
}
