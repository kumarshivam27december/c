#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

// Station class
class Station {
    string name;
public:
    Station(const string& name) : name(name) {}
    string getName() const { return name; }
};

// Monorail Train class
class Monorail {
    vector<Station> route;
    int currentStation;

public:
    Monorail(const vector<string>& stationNames) {
        for (const auto& name : stationNames) {
            route.emplace_back(name);
        }
        currentStation = 0;
    }

    void startRide() {
        cout << "Starting monorail journey...\n";
        for (size_t i = 0; i < route.size(); ++i) {
            currentStation = i;
            arriveAtStation();
            std::this_thread::sleep_for(1s); // Simulate time between stations
        }
        cout << "Monorail has completed the journey.\n";
    }

    void arriveAtStation() {
        cout << "Arrived at: " << route[currentStation].getName() << endl;
    }
};

// Main function
int main() {
    vector<string> stations = {"Central", "Museum", "Park", "Riverfront", "Tech Hub"};

    Monorail monorail(stations);
    monorail.startRide();

    return 0;
}
