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
    int water;
    int energy;

    Astronaut(string astronautName) {
        name = astronautName;
        health = 100;
        water = 100;
        energy = 100;
    }

    void loseHealth(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    void loseWater(int amount) {
        water -= amount;
        if (water < 0) water = 0;
    }

    void loseEnergy(int amount) {
        energy -= amount;
        if (energy < 0) energy = 0;
    }

    void rest() {
        energy += 20;
        if (energy > 100) energy = 100;
        water -= 10;
    }

    void displayStatus() {
        cout << "\n--- Astronaut Status ---" << endl;
        cout << "Health: " << health << "% | Water: " << water << "% | Energy: " << energy << "%" << endl;
    }

    bool isAlive() {
        return health > 0 && water > 0;
    }
};

// Exploration and Events
void exploreSurface(Astronaut& astronaut) {
    cout << "\nYou venture out onto Mercury's molten surface..." << endl;
    delay(2);

    int event = rand() % 3;
    if (event == 0) {
        cout << "You discover a deposit of frozen water beneath the surface!" << endl;
        astronaut.water += 30;
        if (astronaut.water > 100) astronaut.water = 100;
    } else if (event == 1) {
        cout << "A sudden solar flare hits! Your suit's cooling system struggles to keep up." << endl;
        astronaut.loseHealth(20);
        astronaut.loseEnergy(15);
    } else {
        cout << "You stumble upon an ancient crater emitting strange energy signals. It's eerie but fascinating." << endl;
        astronaut.loseEnergy(10);
    }
}

void mineResources(Astronaut& astronaut) {
    cout << "\nYou begin mining Mercury's crust for essential materials..." << endl;
    delay(2);

    if (astronaut.energy >= 30) {
        cout << "You successfully extract valuable minerals to repair your ship!" << endl;
        astronaut.energy -= 30;
    } else {
        cout << "You're too exhausted to work efficiently. Rest before trying again." << endl;
        astronaut.loseHealth(10);
    }
}

void repairShip(Astronaut& astronaut, int& repairProgress) {
    cout << "\nYou work on repairing your ship's damaged systems..." << endl;
    delay(2);

    if (astronaut.energy >= 40 && astronaut.water >= 20) {
        cout << "You make significant progress on the repairs!" << endl;
        astronaut.energy -= 40;
        astronaut.water -= 20;
        repairProgress += 20;
    } else {
        cout << "You lack the resources or energy to continue repairs." << endl;
        astronaut.loseHealth(10);
    }
}

// Main Game
int main() {
    srand(time(0));

    string astronautName;
    cout << "Welcome to *Mercury Inferno: Survival in the Scorched Frontier*!" << endl;
    cout << "Enter your name, brave astronaut: ";
    cin >> astronautName;

    Astronaut astronaut(astronautName);
    int repairProgress = 0;

    cout << "\nYou’ve crash-landed on Mercury, the closest planet to the Sun. Your spacecraft is damaged, and the searing heat threatens your survival.\n"
         << "Your mission is to repair your ship, manage your resources, and escape before Mercury’s inferno claims your life.\n";

    while (astronaut.isAlive() && repairProgress < 100) {
        astronaut.displayStatus();

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Explore Mercury's surface\n"
             << "2. Mine resources for repairs\n"
             << "3. Repair your spacecraft\n"
             << "4. Rest to regain energy\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                exploreSurface(astronaut);
                break;

            case 2:
                mineResources(astronaut);
                break;

            case 3:
                repairShip(astronaut, repairProgress);
                cout << "Repair Progress: " << repairProgress << "%\n";
                break;

            case 4:
                cout << "\nYou take a break to recover your strength..." << endl;
                astronaut.rest();
                break;

            default:
                cout << "\nInvalid choice. Try again." << endl;
        }

        if (!astronaut.isAlive()) {
            cout << "\nYou succumb to Mercury's extreme conditions. Mission failed." << endl;
            return 0;
        }

        if (repairProgress >= 100) {
            cout << "\nCongratulations, " << astronaut.name << "! You’ve repaired your ship and escaped Mercury's inferno. Humanity celebrates your bravery and resilience!" << endl;
            return 0;
        }
    }

    return 0;
}
