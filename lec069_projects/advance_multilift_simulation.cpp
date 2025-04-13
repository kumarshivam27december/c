#include <iostream>
#include <queue>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

class Lift {
    int id;
    int currentFloor;
    queue<int> requests;
    bool busy;

public:
    Lift(int id, int startFloor = 0) : id(id), currentFloor(startFloor), busy(false) {}

    int getCurrentFloor() const {
        return currentFloor;
    }

    bool isBusy() const {
        return busy;
    }

    void addRequest(int floor) {
        requests.push(floor);
    }

    void processRequests() {
        busy = true;
        while (!requests.empty()) {
            int target = requests.front();
            requests.pop();

            cout << "[Lift " << id << "] Moving from " << currentFloor << " to " << target << endl;

            while (currentFloor != target) {
                this_thread::sleep_for(chrono::milliseconds(300));
                currentFloor += (target > currentFloor) ? 1 : -1;
                cout << "[Lift " << id << "] Floor: " << currentFloor << endl;
            }

            cout << "[Lift " << id << "] Arrived at Floor " << currentFloor << endl;
        }
        busy = false;
    }

    int distanceTo(int floor) const {
        return abs(currentFloor - floor);
    }
};

int chooseBestLift(vector<Lift>& lifts, int requestedFloor) {
    int bestLift = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < lifts.size(); ++i) {
        if (!lifts[i].isBusy()) {
            int dist = lifts[i].distanceTo(requestedFloor);
            if (dist < minDistance) {
                minDistance = dist;
                bestLift = i;
            }
        }
    }

    return bestLift;
}

int main() {
    const int totalLifts = 3;
    const int totalFloors = 10;
    vector<Lift> lifts;

    for (int i = 0; i < totalLifts; ++i)
        lifts.push_back(Lift(i));

    while (true) {
        int floor;
        cout << "\nEnter floor to call lift (-1 to exit): ";
        cin >> floor;
        if (floor == -1) break;

        if (floor < 0 || floor >= totalFloors) {
            cout << "Invalid floor!\n";
            continue;
        }

        int liftIndex = chooseBestLift(lifts, floor);
        if (liftIndex == -1) {
            cout << "All lifts are busy. Please wait...\n";
            continue;
        }

        cout << "Lift " << liftIndex << " is coming to Floor " << floor << "...\n";
        lifts[liftIndex].addRequest(floor);

        // Run lift in a new thread
        thread([&lifts, liftIndex]() {
            lifts[liftIndex].processRequests();
        }).detach();
    }

    cout << "Simulation ended.\n";
    return 0;
}
