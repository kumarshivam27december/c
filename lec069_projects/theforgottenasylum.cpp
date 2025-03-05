#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// --- Graph Representation (Rooms as Nodes) ---
class AsylumGraph {
public:
    map<string, vector<pair<string, int>>> adjList; // Room -> (Connected Room, Fear Level)

    void addEdge(string u, string v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void displayMap() {
        cout << "\n🏚️ MAP OF ASYLUM 🏚️\n";
        for (auto &room : adjList) {
            cout << "🔹 " << room.first << " connects to: ";
            for (auto &neighbor : room.second)
                cout << neighbor.first << " (Fear: " << neighbor.second << "), ";
            cout << "\n";
        }
    }

    // --- Dijkstra’s Algorithm to Find Shortest Escape Route ---
    void findEscapePath(string start, string exit) {
        map<string, int> distance;
        map<string, string> parent;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

        for (auto &room : adjList) distance[room.first] = numeric_limits<int>::max();
        distance[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            string current = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            if (current == exit) break;

            for (auto &neighbor : adjList[current]) {
                int newDist = currDist + neighbor.second;
                if (newDist < distance[neighbor.first]) {
                    distance[neighbor.first] = newDist;
                    parent[neighbor.first] = current;
                    pq.push({newDist, neighbor.first});
                }
            }
        }

        // --- Print Shortest Path ---
        if (distance[exit] == numeric_limits<int>::max()) {
            cout << "\n🚪 No escape found! The darkness consumes you... 🩸\n";
        } else {
            cout << "\n🔦 Shortest Escape Path: ";
            string step = exit;
            vector<string> path;
            while (step != start) {
                path.push_back(step);
                step = parent[step];
            }
            path.push_back(start);
            for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << (i == 0 ? "\n" : " ➝ ");
            cout << "🏃💨 You escaped with " << distance[exit] << " Fear Level!\n";
        }
    }
};

// --- Game Class ---
class HorrorGame {
private:
    AsylumGraph asylum;
    string currentRoom;
    string exitRoom;
public:
    HorrorGame() {
        // --- Define the asylum layout ---
        asylum.addEdge("Entrance", "Hallway", 2);
        asylum.addEdge("Hallway", "Storage Room", 3);
        asylum.addEdge("Hallway", "Main Ward", 4);
        asylum.addEdge("Main Ward", "Basement", 6);
        asylum.addEdge("Main Ward", "Operating Room", 5);
        asylum.addEdge("Storage Room", "Morgue", 7);
        asylum.addEdge("Operating Room", "Exit", 2);
        asylum.addEdge("Basement", "Exit", 10);

        currentRoom = "Entrance";
        exitRoom = "Exit";

        cout << "\n🎃 Welcome to **The Forgotten Asylum** 🎃\n";
        cout << "Find your way out before it's too late... 🩸\n";
    }

    void play() {
        string command;
        srand(time(0));

        while (true) {
            cout << "\n📍 You are in: " << currentRoom << "\n";
            cout << "Available paths: ";
            for (auto &path : asylum.adjList[currentRoom]) 
                cout << path.first << " (Fear: " << path.second << ") ";
            cout << "\n";

            if (currentRoom == exitRoom) {
                cout << "🏆 You found the exit and escaped! 🎉\n";
                break;
            }

            // Random Horror Event
            if (rand() % 4 == 0) {
                cout << "😱 A ghostly whisper fills the air... 'Leave... before it's too late...' 🩸\n";
            }

            // Get user choice
            cout << "Enter the next room (or 'map' to see asylum layout, 'escape' to find shortest path, 'quit' to exit): ";
            cin >> command;

            if (command == "quit") {
                cout << "🩸 The asylum swallows you whole... Game Over. 🩸\n";
                break;
            } else if (command == "map") {
                asylum.displayMap();
            } else if (command == "escape") {
                asylum.findEscapePath(currentRoom, exitRoom);
            } else {
                bool validMove = false;
                for (auto &path : asylum.adjList[currentRoom]) {
                    if (path.first == command) {
                        currentRoom = command;
                        validMove = true;
                        break;
                    }
                }
                if (!validMove) cout << "❌ Invalid room! Choose from available paths.\n";
            }
        }
    }
};

// --- Main Function ---
int main() {
    HorrorGame game;
    game.play();
    return 0;
}
