#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Rocket Class
class Rocket {
public:
    int fuel;
    int health;
    bool onPlanet;

    Rocket() {
        fuel = 100;  // Initial fuel level
        health = 100; // Rocket's health
        onPlanet = false;
    }

    void consumeFuel(int amount) {
        fuel -= amount;
        if (fuel < 0) fuel = 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isOperational() {
        return fuel > 0 && health > 0;
    }

    void refuel(int amount) {
        fuel += amount;
        if (fuel > 100) fuel = 100;
    }

    void repair(int amount) {
        health += amount;
        if (health > 100) health = 100;
    }
};

// Planet Class
class Planet {
public:
    string name;
    bool explored;

    Planet(string planetName) {
        name = planetName;
        explored = false;
    }

    void explore() {
        if (!explored) {
            cout << "You explore " << name << " and find rare minerals and alien artifacts!" << endl;
            explored = true;
        } else {
            cout << "You have already explored this part of the planet." << endl;
        }
    }
};

// Function Prototypes
void launchRocket(Rocket& rocket);
void encounterAsteroidField(Rocket& rocket);
void landOnPlanet(Rocket& rocket, Planet& planet);
void alienEncounter(Rocket& rocket);
void gameOver();

// Main Function
int main() {
    srand(time(0));

    // Game setup
    Rocket rocket;
    Planet planet("Planet X");
    string playerName;

    cout << "Welcome to the Intergalactic Adventure!" << endl;
    cout << "Enter your name, brave astronaut: ";
    cin >> playerName;

    cout << "\nHello, " << playerName << "! Your mission is to travel to " << planet.name 
         << ", explore it, collect samples, and return safely to Earth." << endl;

    while (rocket.isOperational() && !rocket.onPlanet) {
        cout << "\n--- Rocket Status ---" << endl;
        cout << "Fuel: " << rocket.fuel << "% | Health: " << rocket.health << "%" << endl;

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Launch the rocket\n2. Navigate an asteroid field\n3. Land on Planet X\n4. Quit Mission" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                launchRocket(rocket);
                break;
            case 2:
                encounterAsteroidField(rocket);
                break;
            case 3:
                landOnPlanet(rocket, planet);
                break;
            case 4:
                cout << "Mission aborted! Returning to Earth." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }

        if (rocket.fuel <= 0 || rocket.health <= 0) {
            gameOver();
            return 0;
        }
    }

    if (rocket.onPlanet) {
        cout << "\nYou have successfully landed on " << planet.name << "!" << endl;

        while (!planet.explored) {
            cout << "\nWhat would you like to do?" << endl;
            cout << "1. Explore the planet\n2. Encounter aliens\n3. Refuel rocket\n4. Repair rocket\n5. Return to Earth" << endl;
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    planet.explore();
                    break;
                case 2:
                    alienEncounter(rocket);
                    break;
                case 3:
                    rocket.refuel(20);
                    cout << "Rocket refueled!" << endl;
                    break;
                case 4:
                    rocket.repair(20);
                    cout << "Rocket repaired!" << endl;
                    break;
                case 5:
                    cout << "Mission accomplished! Returning to Earth." << endl;
                    return 0;
                default:
                    cout << "Invalid choice. Try again!" << endl;
            }

            if (rocket.fuel <= 0 || rocket.health <= 0) {
                gameOver();
                return 0;
            }
        }
    }

    cout << "Congratulations, " << playerName << "! You completed the mission successfully!" << endl;
    return 0;
}

// Function Definitions
void launchRocket(Rocket& rocket) {
    cout << "Launching the rocket..." << endl;
    rocket.consumeFuel(10);
    cout << "Rocket consumed 10% fuel during the launch." << endl;
}

void encounterAsteroidField(Rocket& rocket) {
    cout << "You encounter an asteroid field!" << endl;
    int damage = rand() % 20 + 10;  // Random damage between 10 and 30
    rocket.takeDamage(damage);
    cout << "Rocket took " << damage << "% damage!" << endl;
}

void landOnPlanet(Rocket& rocket, Planet& planet) {
    if (rocket.fuel < 20) {
        cout << "Not enough fuel to land on the planet! Refuel first." << endl;
    } else {
        cout << "Attempting to land on " << planet.name << "..." << endl;
        rocket.consumeFuel(20);
        rocket.onPlanet = true;
        cout << "Landing successful! Fuel used: 20%." << endl;
    }
}

void alienEncounter(Rocket& rocket) {
    cout << "You encounter a hostile alien!" << endl;
    int damage = rand() % 15 + 5;  // Random damage between 5 and 20
    rocket.takeDamage(damage);
    cout << "Rocket took " << damage << "% damage from the alien attack!" << endl;
}

void gameOver() {
    cout << "\nGame Over! Your rocket is no longer operational." << endl;
}
