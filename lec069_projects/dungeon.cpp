#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>
#include <string>

using namespace std;

// Graph using adjacency list
class Dungeon {
    map<string, vector<pair<string, int>>> graph;
public:
    void addRoom(const string& room) {
        graph[room] = vector<pair<string, int>>();
    }
    void connectRooms(const string& room1, const string& room2, int weight) {
        graph[room1].push_back({room2, weight});
        graph[room2].push_back({room1, weight}); // Undirected graph
    }
    // Dijkstra's algorithm to find shortest path
    vector<string> findShortestPath(const string& start, const string& end) {
        map<string, int> dist;
        map<string, string> prev;
        for (auto& node : graph) dist[node.first] = numeric_limits<int>::max();
        dist[start] = 0;

        auto cmp = [&](const pair<int, string>& a, const pair<int, string>& b) { return a.first > b.first; };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        pq.push({0, start});

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (u == end) break;
            for (auto& [v, weight] : graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<string> path;
        for (string at = end; at != ""; at = prev[at]) path.push_back(at);
        reverse(path.begin(), path.end());
        return path;
    }
    void displayRooms() {
        cout << "\nDungeon Map:\n";
        for (auto& [room, edges] : graph) {
            cout << room << " connects to: ";
            for (auto& [adj, w] : edges) cout << adj << " (danger level " << w << "), ";
            cout << "\n";
        }
    }
};

int main() {
    Dungeon dungeon;
    // Create rooms
    dungeon.addRoom("Entrance");
    dungeon.addRoom("Hall");
    dungeon.addRoom("Chamber");
    dungeon.addRoom("Armory");
    dungeon.addRoom("Treasure Room");

    // Connect rooms (with "danger levels" as weights)
    dungeon.connectRooms("Entrance", "Hall", 2);
    dungeon.connectRooms("Hall", "Chamber", 3);
    dungeon.connectRooms("Chamber", "Armory", 4);
    dungeon.connectRooms("Armory", "Treasure Room", 1);
    dungeon.connectRooms("Hall", "Armory", 2); // shortcut

    cout << "Welcome to the Dungeon Adventure Game!\n";
    dungeon.displayRooms();

    string currentRoom = "Entrance";
    string command;

    while (true) {
        cout << "\nYou are in: " << currentRoom << "\nWhat do you want to do? (move/check path/exit): ";
        cin >> command;

        if (command == "move") {
            cout << "Where do you want to go? ";
            string nextRoom;
            cin >> nextRoom;
            bool found = false;
            for (auto& [adj, _] : dungeon.findShortestPath(currentRoom, nextRoom)) {
                if (adj == nextRoom) found = true;
            }
            if (found) {
                currentRoom = nextRoom;
                cout << "You moved to " << currentRoom << ".\n";
                if (currentRoom == "Treasure Room") {
                    cout << "Congratulations! You found the treasure! 🏆\n";
                    break;
                }
            } else {
                cout << "You can't go there directly!\n";
            }
        }
        else if (command == "check") {
            cout << "Enter destination to find safest path: ";
            string destination;
            cin >> destination;
            auto path = dungeon.findShortestPath(currentRoom, destination);
            if (path.size() > 1) {
                cout << "Safest path: ";
                for (auto& room : path) cout << room << " -> ";
                cout << "END\n";
            } else cout << "No path found!\n";
        }
        else if (command == "exit") {
            cout << "Exiting game. Bye!\n";
            break;
        }
        else cout << "Unknown command.\n";
    }

    return 0;
}
