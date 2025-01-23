#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Astronaut Class
class Astronaut {
public:
    string name;
    int health;
    int energy;
    int resources;

    Astronaut(string astronautName) {
        name = astronautName;
        health = 100;     // Initial health
        energy = 100;     // Initial energy
        resources = 50;   // Initial resources
    }

    void useResources(int amount) {
        resources -= amount;
        if (resources < 0) resources = 0;
    }

    void restoreHealth(int amount) {
        health += amount;
        if (health > 100) health = 100;
    }

    void consumeEnergy(int amount) {
        energy -= amount;
        if (energy < 0) energy = 0;
    }

    void gatherResources(int amount) {
        resources += amount;
    }

    bool isAlive() {
        return health > 0;
    }

    void displayStatus() {
        cout << "\n--- Astronaut Status ---" << endl;
        cout << "Health: " << health << "% | Energy: " << energy << "% | Resources: " << resources << endl;
    }
};

// Venus Restoration Class
class Venus {
public:
    int atmosphereLevel;
    int waterSupplyLevel;
    int disasterRisk;

    Venus() {
        atmosphereLevel = 0;  // Progress toward restoring the atmosphere
        waterSupplyLevel = 0; // Progress toward creating a water supply
        disasterRisk = 20;    // Initial disaster risk
    }

    void improveAtmosphere(int amount) {
        atmosphereLevel += amount;
        if (atmosphereLevel > 100) atmosphereLevel = 100;
    }

    void improveWaterSupply(int amount) {
        waterSupplyLevel += amount;
        if (waterSupplyLevel > 100) waterSupplyLevel = 100;
    }

    bool isRestored() {
        return atmosphereLevel == 100 && waterSupplyLevel == 100;
    }

    void triggerDisaster(Astronaut& astronaut) {
        int disasterChance = rand() % 100;
        if (disasterChance < disasterRisk) {
            cout << "\nA solar storm strikes! You take damage and lose resources!" << endl;
            astronaut.health -= 20;
            astronaut.useResources(10);
        }
    }

    void displayProgress() {
        cout << "\n--- Venus Restoration Progress ---" << endl;
        cout << "Atmosphere Level: " << atmosphereLevel << "% | Water Supply Level: " << waterSupplyLevel << "%" << endl;
    }
};

// Main Game Function
int main() {
    srand(time(0));

    string astronautName;
    cout << "Welcome to the Venus Restoration Mission!" << endl;
    cout << "Enter your name, brave astronaut: ";
    cin >> astronautName;

    Astronaut astronaut(astronautName);
    Venus venus;

    cout << "\nHello, " << astronautName << "! Your mission is to restore Venus by building its atmosphere and water supply. "
         << "You must survive harsh conditions and manage your resources wisely.\n";

    while (astronaut.isAlive() && !venus.isRestored()) {
        astronaut.displayStatus();
        venus.displayProgress();

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Work on restoring the atmosphere (Costs 10 resources, 15 energy)\n"
             << "2. Work on creating the water supply (Costs 15 resources, 20 energy)\n"
             << "3. Gather resources\n"
             << "4. Rest to regain energy\n"
             << "5. Check the mission progress\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                if (astronaut.resources >= 10 && astronaut.energy >= 15) {
                    cout << "\nYou work on atmospheric generators..." << endl;
                    astronaut.useResources(10);
                    astronaut.consumeEnergy(15);
                    venus.improveAtmosphere(10);
                    venus.triggerDisaster(astronaut);
                } else {
                    cout << "\nNot enough resources or energy to continue!" << endl;
                }
                break;

            case 2:
                if (astronaut.resources >= 15 && astronaut.energy >= 20) {
                    cout << "\nYou work on the water supply system..." << endl;
                    astronaut.useResources(15);
                    astronaut.consumeEnergy(20);
                    venus.improveWaterSupply(10);
                    venus.triggerDisaster(astronaut);
                } else {
                    cout << "\nNot enough resources or energy to continue!" << endl;
                }
                break;

            case 3:
                cout << "\nYou venture into the harsh environment to gather resources..." << endl;
                astronaut.gatherResources(20);
                astronaut.consumeEnergy(10);
                venus.triggerDisaster(astronaut);
                break;

            case 4:
                cout << "\nYou rest and regain energy..." << endl;
                astronaut.energy += 25;
                if (astronaut.energy > 100) astronaut.energy = 100;
                break;

            case 5:
                cout << "\nCurrent Mission Progress:" << endl;
                venus.displayProgress();
                break;

            default:
                cout << "\nInvalid choice. Try again!" << endl;
        }

        if (!astronaut.isAlive()) {
            cout << "\nYou have succumbed to the harsh conditions of Venus. Mission failed." << endl;
            return 0;
        }
    }

    if (venus.isRestored()) {
        cout << "\nCongratulations, Commander " << astronautName << "! You successfully restored Venus!" << endl;
        cout << "The planet is now habitable for future colonization. Mission accomplished!" << endl;
    }

    return 0;
}
