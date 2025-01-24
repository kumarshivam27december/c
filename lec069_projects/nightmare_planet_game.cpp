#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

void delay(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

// Astronaut Class
class Astronaut {
public:
    string name;
    int health;
    int sanity;
    int resources;

    Astronaut(string astronautName) {
        name = astronautName;
        health = 100;
        sanity = 100;
        resources = 50;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    void loseSanity(int amount) {
        sanity -= amount;
        if (sanity < 0) sanity = 0;
    }

    void gatherResources(int amount) {
        resources += amount;
    }

    void useResources(int amount) {
        resources -= amount;
        if (resources < 0) resources = 0;
    }

    bool isAlive() {
        return health > 0;
    }

    void displayStatus() {
        cout << "\n--- Astronaut Status ---" << endl;
        cout << "Health: " << health << "% | Sanity: " << sanity << "% | Resources: " << resources << endl;
    }
};

// Alien Encounter Function
void alienEncounter(Astronaut& astronaut) {
    cout << "\nYou hear strange noises in the dark..." << endl;
    delay(2);
    int event = rand() % 3;
    if (event == 0) {
        cout << "A shadowy figure appears and attacks you!" << endl;
        int damage = rand() % 20 + 10; // Damage between 10-30
        astronaut.takeDamage(damage);
        cout << "You take " << damage << "% damage!" << endl;
    } else if (event == 1) {
        cout << "You see something horrifying. Your sanity decreases!" << endl;
        int sanityLoss = rand() % 15 + 10; // Sanity loss between 10-25
        astronaut.loseSanity(sanityLoss);
        cout << "You lose " << sanityLoss << "% sanity!" << endl;
    } else {
        cout << "The noise fades away... for now." << endl;
    }
}

// Game Functions
void searchForParts(Astronaut& astronaut) {
    cout << "\nYou search the wreckage for spaceship parts..." << endl;
    delay(2);

    int success = rand() % 2; // 50% chance of finding a part
    if (success) {
        cout << "You find a crucial part for the spaceship!" << endl;
        astronaut.gatherResources(20);
    } else {
        cout << "You find nothing useful but hear footsteps nearby..." << endl;
        alienEncounter(astronaut);
    }
}

void exploreDarkCave(Astronaut& astronaut) {
    cout << "\nYou venture into a dark, eerie cave..." << endl;
    delay(2);

    int event = rand() % 3;
    if (event == 0) {
        cout << "You find glowing crystals! They might be useful." << endl;
        astronaut.gatherResources(30);
    } else if (event == 1) {
        cout << "You slip on a wet rock and injure yourself!" << endl;
        astronaut.takeDamage(15);
    } else {
        cout << "The walls start to move. You feel like you're being watched..." << endl;
        alienEncounter(astronaut);
    }
}

void repairSpaceship(Astronaut& astronaut) {
    cout << "\nYou work on repairing the spaceship..." << endl;
    delay(2);

    if (astronaut.resources >= 100) {
        cout << "You successfully repair the spaceship!" << endl;
    } else {
        cout << "You don't have enough parts to complete the repair." << endl;
    }
}

// Main Function
int main() {
    srand(time(0));

    string astronautName;
    cout << "Welcome to the Nightmare Planet!" << endl;
    cout << "Enter your name, brave astronaut: ";
    cin >> astronautName;

    Astronaut astronaut(astronautName);

    cout << "\nYou have crash-landed on a hostile alien planet. Strange noises echo around you, and danger lurks in every shadow."
         << "\nYour mission is to repair your spaceship and escape before you lose your health or sanity.\n";

    while (astronaut.isAlive() && astronaut.sanity > 0) {
        astronaut.displayStatus();

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Search the wreckage for spaceship parts\n"
             << "2. Explore the dark cave nearby\n"
             << "3. Work on repairing the spaceship\n"
             << "4. Rest and regain composure\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                searchForParts(astronaut);
                break;

            case 2:
                exploreDarkCave(astronaut);
                break;

            case 3:
                if (astronaut.resources >= 100) {
                    repairSpaceship(astronaut);
                    cout << "\nCongratulations, " << astronautName << "! You successfully repaired the spaceship and escaped the Nightmare Planet!" << endl;
                    return 0;
                } else {
                    cout << "\nYou don't have enough resources to repair the spaceship yet." << endl;
                }
                break;

            case 4:
                cout << "\nYou take a moment to rest, regaining some sanity and health..." << endl;
                astronaut.sanity += 20;
                astronaut.health += 10;
                if (astronaut.sanity > 100) astronaut.sanity = 100;
                if (astronaut.health > 100) astronaut.health = 100;
                break;

            default:
                cout << "\nInvalid choice. Try again." << endl;
        }

        if (!astronaut.isAlive()) {
            cout << "\nYou have succumbed to the horrors of the Nightmare Planet. Mission failed." << endl;
            return 0;
        }

        if (astronaut.sanity <= 0) {
            cout << "\nYou have lost your sanity and become a part of the Nightmare Planet's horrors. Mission failed." << endl;
            return 0;
        }
    }

    return 0;
}
