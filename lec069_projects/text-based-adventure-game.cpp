#include <iostream>
#include <string>

using namespace std;

class Room {
public:
    string description;
    Room* north;
    Room* south;
    Room* east;
    Room* west;

    Room(string desc) : description(desc), north(nullptr), south(nullptr), east(nullptr), west(nullptr) {}
};

class Game {
private:
    Room* currentRoom;

public:
    Game() {
        // Create rooms
        Room* room1 = new Room("You are in a dark, damp room. There is a door to the north.");
        Room* room2 = new Room("You are in a bright room with a treasure chest in the corner. There is a door to the south.");
        Room* room3 = new Room("You are in a room with a large statue. There is a door to the east.");
        Room* room4 = new Room("You are in a library with shelves of ancient books. There is a door to the west.");

        // Set room connections
        room1->north = room2;
        room2->south = room1;
        room1->east = room3;
        room3->west = room1;
        room2->east = room4;
        room4->west = room2;

        currentRoom = room1;
    }

    ~Game() {
        // Clean up dynamically allocated rooms
        delete currentRoom;
    }

    void lookAround() {
        cout << currentRoom->description << endl;
    }

    void move(string direction) {
        if (direction == "north") {
            if (currentRoom->north != nullptr) {
                currentRoom = currentRoom->north;
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (direction == "south") {
            if (currentRoom->south != nullptr) {
                currentRoom = currentRoom->south;
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (direction == "east") {
            if (currentRoom->east != nullptr) {
                currentRoom = currentRoom->east;
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (direction == "west") {
            if (currentRoom->west != nullptr) {
                currentRoom = currentRoom->west;
            } else {
                cout << "You can't go that way." << endl;
            }
        } else {
            cout << "Invalid direction." << endl;
        }
    }

    void start() {
        string command;
        cout << "Welcome to the dungeon! You can move north, south, east, or west. Type 'look' to look around or 'quit' to exit." << endl;

        while (true) {
            cout << "> ";
            getline(cin, command);

            if (command == "look") {
                lookAround();
            } else if (command == "quit") {
                cout << "Thanks for playing!" << endl;
                break;
            } else if (command == "north" || command == "south" || command == "east" || command == "west") {
                move(command);
            } else {
                cout << "Unknown command." << endl;
            }
        }
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}

