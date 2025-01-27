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
    int oxygen;
    int health;
    int energy;

    Astronaut(string astronautName) {
        name = astronautName;
        oxygen = 100;
        health = 100;
        energy = 100;
    }

    void useOxygen(int amount) {
        oxygen -= amount;
        if (oxygen < 0) oxygen = 0;
    }

    void loseHealth(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    void loseEnergy(int amount) {
        energy -= amount;
        if (energy < 0) energy = 0;
    }

    void rest() {
        energy += 30;
        if (energy > 100) energy = 100;
        oxygen -= 10;
    }

    void displayStatus() {
        cout << "\n--- Astronaut Status ---" << endl;
        cout << "Oxygen: " << oxygen << "% | Health: " << health << "% | Energy: " << energy << "%" << endl;
    }

    bool isAlive() {
        return health > 0 && oxygen > 0;
    }
};

// Exploration Events
void exploreColony(Astronaut& astronaut) {
    cout << "\nYou step into the abandoned lunar colony..." << endl;
    delay(2);

    int event = rand() % 3;
    if (event == 0) {
        cout << "You find a cache of oxygen tanks and recharge your supply!" << endl;
        astronaut.oxygen += 20;
        if (astronaut.oxygen > 100) astronaut.oxygen = 100;
    } else if (event == 1) {
        cout << "The floor collapses beneath you, and you injure yourself!" << endl;
        astronaut.loseHealth(20);
    } else {
        cout << "You hear a strange, low-frequency sound. You feel uneasy..." << endl;
        astronaut.loseEnergy(15);
    }
}

void investigateSignal(Astronaut& astronaut) {
    cout << "\nYou follow a mysterious signal to the outskirts of the colony..." << endl;
    delay(2);

    int event = rand() % 3;
    if (event == 0) {
        cout << "You find an alien artifact emitting the signal. It's strangely warm to the touch." << endl;
        astronaut.loseEnergy(10);
    } else if (event == 1) {
        cout << "An ancient lunar rover activates suddenly and collides with you!" << endl;
        astronaut.loseHealth(15);
    } else {
        cout << "The signal leads to an empty room. Was it just interference?" << endl;
    }
}

void repairLander(Astronaut& astronaut) {
    cout << "\nYou work on repairing your lunar lander..." << endl;
    delay(2);

    if (astronaut.energy >= 50) {
        cout << "You successfully make progress on the repairs!" << endl;
        astronaut.energy -= 50;
    } else {
        cout << "You're too exhausted to make any significant repairs." << endl;
        astronaut.loseHealth(10);
    }
}

// Main Game
int main() {
    srand(time(0));

    string astronautName;
    cout << "Welcome to *Lunar Odyssey: The Forgotten Colony*!" << endl;
    cout << "Enter your name, brave astronaut: ";
    cin >> astronautName;

    Astronaut astronaut(astronautName);

    cout << "\nYou’ve landed on the Moon as part of a mission to investigate the abandoned lunar colony. However, something doesn’t feel right...\n"
         << "Your mission is to gather enough resources to repair your lander and escape the Moon while uncovering its hidden mysteries.\n";

    while (astronaut.isAlive()) {
        astronaut.displayStatus();

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Explore the abandoned colony\n"
             << "2. Investigate a mysterious signal\n"
             << "3. Work on repairing the lunar lander\n"
             << "4. Rest to regain energy\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                exploreColony(astronaut);
                break;

            case 2:
                investigateSignal(astronaut);
                break;

            case 3:
                repairLander(astronaut);
                if (astronaut.energy <= 0) {
                    cout << "\nCongratulations, " << astronaut.name << "! You have repaired your lander and escaped the Moon, but its mysteries remain unsolved.\n";
                    return 0;
                }
                break;

            case 4:
                cout << "\nYou take a break to regain your strength..." << endl;
                astronaut.rest();
                break;

            default:
                cout << "\nInvalid choice. Try again." << endl;
        }

        if (!astronaut.isAlive()) {
            cout << "\nYou succumb to the harsh conditions of the Moon. Mission failed." << endl;
            return 0;
        }
    }

    return 0;
}

