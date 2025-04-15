#include <iostream>
#include <set>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

enum Direction { IDLE, UP, DOWN };

class Lift {
    int id;
    int currentFloor;
    Direction direction;
    set<int> requestQueue;

public:
    Lift(int id) : id(id), currentFloor(0), direction(IDLE) {}

    void addRequest(int floor) {
        requestQueue.insert(floor);
    }

    Direction getDirection() const {
        return direction;
    }

    int getCurrentFloor() const {
        return currentFloor;
    }

    bool hasRequests() const {
        return !requestQueue.empty();
    }

    void move() {
        if (!hasRequests()) {
            direction = IDLE;
            return;
        }

        int target = *requestQueue.begin();

        direction = (target > currentFloor) ? UP : (target < currentFloor ? DOWN : IDLE);

        if (direction == UP) currentFloor++;
        else if (direction == DOWN) currentFloor--;

        cout << "[Lift " << id << "] Floor: " << currentFloor << " (Target: " << target << ")\n";

        if (currentFloor == target) {
            cout << "[Lift " << id << "] Arrived at Floor " << target << "\n";
            requestQueue.erase(target);
        }
    }
};

int main() {
    const int totalLifts = 2;
    const int totalFloors = 10;
    vector<Lift> lifts;

    for (int i = 0; i < totalLifts; ++i)
        lifts.push_back(Lift(i));

    cout << "Lift System Simulation Started\n";

    thread simulationThread([&]() {
        while (true) {
            for (auto& lift : lifts) {
                if (lift.hasRequests()) {
                    lift.move();
                }
            }
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    });

    while (true) {
        int floor;
        cout << "\nEnter floor to request lift (-1 to exit): ";
        cin >> floor;
        if (floor == -1) break;

        if (floor < 0 || floor >= totalFloors) {
            cout << "Invalid floor number.\n";
            continue;
        }

        // Assign to lift with shortest queue
        int bestLift = 0;
        size_t minRequests = lifts[0].hasRequests() ? 1 : 0;

        for (int i = 1; i < lifts.size(); ++i) {
            if (lifts[i].hasRequests() && minRequests == 0) continue;
            bestLift = i;
            break;
        }

        lifts[bestLift].addRequest(floor);
        cout << "Request assigned to Lift " << bestLift << ".\n";
    }

    cout << "Simulation stopping...\n";
    simulationThread.detach(); // or join() if you want to wait
    return 0;
}
