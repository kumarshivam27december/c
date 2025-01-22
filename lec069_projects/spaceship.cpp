#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Spaceship Class
class Spaceship {
public:
    int fuel;
    int oxygen;
    int health;

    Spaceship() {
        fuel = 100;
        oxygen = 100;
        health = 100;
    }

    void consumeFuel(int amount) {
        fuel -= amount;
        if (fuel < 0) fuel = 0;
    }

    void consumeOxygen(int amount) {
        oxygen -= amount;
        if (oxygen < 0) oxygen = 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    void refuel(int amount) {
        fuel += amount;
        if (fuel > 100) fuel = 100;
    }

    void replenishOxygen(int amount) {
        oxygen += amount;
        if (oxygen > 100) oxygen = 100;
    }

    bool isOperational() {
        return fuel > 0 && oxygen > 0 && health > 0;
    }

    void displayStatus() {
        cout << "Spaceship Status - Fuel: " << fuel << "%, Oxygen: " << oxygen 
             << "%, Health: " << health << "%" << endl;
    }
};

// Planet Class
class Planet {
public:
    string name;
    string description;
    bool visited;

    Planet(string planetName, string planetDescription) {
        name = planetName;
        description = planetDescription;
        visited = false;
    }

    void explore() {
        if (!visited) {
            cout << "Exploring " << name << ": " << description << endl;
            visited = true;
        } else {
            cout << "You have already explored " << name << "." << endl;
        }
    }
};

// Puzzle Function
bool solvePuzzle() {
    cout << "You encounter a puzzle! Solve this riddle to continue:\n";
    cout << "I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?" << endl;
    cout << "1. Echo\n2. Shadow\n3. Fire\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Correct! You solved the puzzle." << endl;
        return true;
    } else {
        cout << "Wrong answer! You failed the puzzle and take damage." << endl;
        return false;
    }
}

// Alien Encounter
void alienEncounter(Spaceship& ship) {
    cout << "You encounter hostile aliens!" << endl;
    int damage = rand() % 20 + 10;  // Damage between 10 and 30
    ship.takeDamage(damage);
    cout << "Your spaceship takes " << damage << "% damage!" << endl;
}

// Main Function
int main() {
    srand(time(0));

    // Game setup
    Spaceship spaceship;
    vector<Planet> planets = {
        Planet("Planet Aurora", "A mysterious planet covered in glowing crystals."),
        Planet("Planet Inferno", "A fiery planet with volcanic eruptions."),
        Planet("Planet Oceania", "A water-covered planet teeming with life.")
    };

    cout << "Welcome to the Galactic Explorer Mission!" << endl;
    cout << "Your goal: Visit three planets, collect resources, and return safely to Earth.\n";

    string playerName;
    cout << "Enter your name, Commander: ";
    cin >> playerName;

    cout << "\nGood luck, Commander " << playerName << "! Your journey begins now.\n";

    for (auto& planet : planets) {
        if (!spaceship.isOperational()) {
            cout << "Your spaceship is no longer operational. Mission failed." << endl;
            return 0;
        }

        spaceship.displayStatus();
        cout << "\nWould you like to travel to " << planet.name << "? (1 for Yes, 2 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Traveling to " << planet.name << "..." << endl;
            spaceship.consumeFuel(20);
            spaceship.consumeOxygen(15);

            if (spaceship.isOperational()) {
                planet.explore();
                cout << "What would you like to do?\n1. Solve a puzzle\n2. Search for resources\n3. Avoid challenges\n";
                cin >> choice;

                switch (choice) {
                    case 1:
                        if (!solvePuzzle()) {
                            spaceship.takeDamage(10);
                        }
                        break;
                    case 2:
                        cout << "You search for resources and find fuel and oxygen!" << endl;
                        spaceship.refuel(20);
                        spaceship.replenishOxygen(20);
                        break;
                    case 3:
                        cout << "You avoid challenges and conserve resources." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Nothing happens." << endl;
                        break;
                }
            } else {
                cout << "Your spaceship ran out of resources during the journey." << endl;
                return 0;
            }
        } else {
            cout << "You decide to skip " << planet.name << "." << endl;
        }
    }

    cout << "\nYou have successfully visited all the planets and are returning to Earth!" << endl;
    spaceship.displayStatus();

    if (spaceship.isOperational()) {
        cout << "Congratulations, Commander " << playerName << "! You completed the mission successfully!" << endl;
    } else {
        cout << "Your spaceship couldn't complete the journey. Mission failed." << endl;
    }

    return 0;
}
