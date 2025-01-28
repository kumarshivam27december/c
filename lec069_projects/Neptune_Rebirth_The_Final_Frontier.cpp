#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

void delay(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

// Astronaut Class
class Astronaut {
public:
    string name;
    int health;
    int morale;
    int energy;

    Astronaut(string astronautName) {
        name = astronautName;
        health = 100;
        morale = 100;
        energy = 100;
    }

    void loseHealth(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    void loseMorale(int amount) {
        morale -= amount;
        if (morale < 0) morale = 0;
    }

    void loseEnergy(int amount) {
        energy -= amount;
        if (energy < 0) energy = 0;
    }

    void rest() {
        energy += 30;
        if (energy > 100) energy = 100;
        morale += 10;
    }

    void displayStatus() {
        cout << "\n--- Astronaut Status ---" << endl;
        cout << "Health: " << health << "% | Morale: " << morale << "% | Energy: " << energy << "%" << endl;
    }

    bool isAlive() {
        return health > 0;
    }
};

// Terraforming and Exploration Functions
void buildHabitat(Astronaut& astronaut) {
    cout << "\nYou work on constructing the habitat dome..." << endl;
    delay(2);

    if (astronaut.energy >= 40) {
        cout << "You successfully complete part of the habitat. Progress made!" << endl;
        astronaut.energy -= 40;
    } else {
        cout << "You’re too exhausted to work effectively. Take some rest first." << endl;
        astronaut.loseHealth(10);
    }
}

void exploreSurface(Astronaut& astronaut) {
    cout << "\nYou venture out into Neptune's frozen landscape..." << endl;
    delay(2);

    int event = rand() % 3;
    if (event == 0) {
        cout << "You discover a rare resource that will aid the mission!" << endl;
        astronaut.morale += 20;
    } else if (event == 1) {
        cout << "A sudden storm hits, damaging your suit and draining your energy!" << endl;
        astronaut.loseHealth(15);
        astronaut.loseEnergy(20);
    } else {
        cout << "You encounter strange, glowing crystals that emit warmth. They're beautiful, but unsettling." << endl;
        astronaut.loseMorale(10);
    }
}

void repairEquipment(Astronaut& astronaut) {
    cout << "\nYou begin repairing critical mission equipment..." << endl;
    delay(2);

    if (astronaut.energy >= 30) {
        cout << "You successfully repair the equipment, ensuring the mission can continue!" << endl;
        astronaut.energy -= 30;
    } else {
        cout << "You don't have enough energy to focus on repairs." << endl;
        astronaut.loseHealth(10);
    }
}

// Main Game
int main() {
    srand(time(0));

    string astronautName;
    cout << "Welcome to *Neptune Rebirth: The Final Frontier*!" << endl;
    cout << "Enter your name, brave astronaut: ";
    cin >> astronautName;

    Astronaut astronaut(astronautName);

    cout << "\nYou’ve landed on Neptune as part of humanity’s most ambitious mission: to terraform the planet and make it habitable for future generations.\n"
         << "Your mission is to balance survival and progress, ensuring the colony can thrive amidst Neptune's challenges.\n";

    while (astronaut.isAlive()) {
        astronaut.displayStatus();

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Build habitat structures\n"
             << "2. Explore Neptune's surface\n"
             << "3. Repair mission equipment\n"
             << "4. Rest to regain energy\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                buildHabitat(astronaut);
                break;

            case 2:
                exploreSurface(astronaut);
                break;

            case 3:
                repairEquipment(astronaut);
                break;

            case 4:
                cout << "\nYou take a break to recover your strength and morale..." << endl;
                astronaut.rest();
                break;

            default:
                cout << "\nInvalid choice. Try again." << endl;
        }

        if (astronaut.health <= 0) {
            cout << "\nYou succumb to Neptune's harsh conditions. Mission failed." << endl;
            return 0;
        }
    }

    cout << "\nCongratulations, " << astronaut.name << "! You have successfully terraformed Neptune and ensured humanity’s survival beyond Earth. The mission is a triumph!\n";
    return 0;
}
