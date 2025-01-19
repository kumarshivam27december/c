#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
public:
    string name;
    int health;
    int inventory;

    Player(string playerName) {
        name = playerName;
        health = 100;
        inventory = 0;
    }

    void displayStats() {
        cout << "Player: " << name << " | Health: " << health << " | Inventory: " << inventory << endl;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    void heal(int healthPoints) {
        health += healthPoints;
        if (health > 100) health = 100;
    }

    void addInventory(int item) {
        inventory += item;
    }
};

class Zombie {
public:
    int damage;

    Zombie() {
        damage = rand() % 20 + 10;  // Zombies deal 10 to 30 damage
    }

    int attack() {
        return damage;
    }
};

class Friend {
public:
    string name;
    bool isAlive;

    Friend(string friendName) {
        name = friendName;
        isAlive = true;
    }

    void help(Player& player) {
        if (isAlive) {
            player.heal(20);
            cout << name << " helped you with healing!" << endl;
        }
    }
};

void encounterZombie(Player& player, Zombie& zombie) {
    cout << "A zombie appears! It attacks you!" << endl;
    player.takeDamage(zombie.attack());
    cout << "You lost " << zombie.attack() << " health!" << endl;
}

void findTreasure(Player& player) {
    cout << "You found a treasure chest!" << endl;
    int loot = rand() % 5 + 1;  // Random loot between 1 and 5 items
    player.addInventory(loot);
    cout << "You gained " << loot << " items!" << endl;
}

void gameIntro(Player& player) {
    cout << "Welcome to the Zombie Treasure Hunt!" << endl;
    cout << "Your mission: Survive, make friends, and find the hidden treasure!" << endl;
}

void gameOver(Player& player) {
    cout << "Game Over! " << player.name << " has perished." << endl;
}

int main() {
    srand(time(0));

    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    Player player(playerName);
    Zombie zombie;
    Friend friend1("Alex");

    gameIntro(player);

    while (player.health > 0) {
        player.displayStats();
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Fight Zombies\n2. Search for Treasure\n3. Talk to Alex\n4. Quit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                encounterZombie(player, zombie);
                break;

            case 2:
                findTreasure(player);
                break;

            case 3:
                friend1.help(player);
                break;

            case 4:
                cout << "You quit the adventure!" << endl;
                return 0;

            default:
                cout << "Invalid choice, try again!" << endl;
        }

        if (player.health <= 0) {
            gameOver(player);
            return 0;
        }
    }

    return 0;
}
