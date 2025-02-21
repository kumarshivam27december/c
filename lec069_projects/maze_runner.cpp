#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

// Maze representation as a graph
map<string, vector<string>> maze = {
    {"Entrance", {"Hallway", "Trap1"}},
    {"Hallway", {"Room1", "Room2", "Exit"}},
    {"Room1", {"KeyRoom", "Trap2"}},
    {"Room2", {"Exit"}},
    {"Trap1", {}},
    {"Trap2", {}},
    {"KeyRoom", {"Hallway"}},
    {"Exit", {}}
};

// Player inventory (stack)
stack<string> inventory;

// Function to display available paths
void displayPaths(const string& location) {
    cout << "You are at " << location << ". Available paths:\n";
    for (auto& next : maze[location]) {
        cout << "-> " << next << "\n";
    }
}

// Function to add an item to inventory
void collectItem(const string& item) {
    inventory.push(item);
    cout << "You found a " << item << "! It's added to your inventory.\n";
}

// BFS function to check if escape is possible
bool canEscape(string start) {
    queue<string> q;
    map<string, bool> visited;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        string loc = q.front();
        q.pop();

        if (loc == "Exit") return true;

        for (auto& next : maze[loc]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

void playGame() {
    string currentLocation = "Entrance";
    queue<string> path;
    path.push(currentLocation);

    while (currentLocation != "Exit") {
        displayPaths(currentLocation);
        string choice;
        cin >> choice;

        if (maze.find(choice) != maze.end()) {
            if (choice == "Trap1" || choice == "Trap2") {
                cout << "Oh no! You fell into a trap. Game Over.\n";
                return;
            }

            currentLocation = choice;
            path.push(currentLocation);

            if (choice == "KeyRoom") collectItem("Key");

            if (choice == "Exit") {
                if (!inventory.empty() && inventory.top() == "Key") {
                    cout << "You used the Key to unlock the Exit! You escaped the maze!\n";
                    return;
                } else {
                    cout << "The exit is locked. Find the key first!\n";
                    currentLocation = "Hallway"; // Send back
                }
            }
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    cout << "Welcome to Maze Runner!\n";
    if (!canEscape("Entrance")) {
        cout << "There's no way to escape from this maze. Game setup is incorrect.\n";
        return 0;
    }
    playGame();
    return 0;
}
