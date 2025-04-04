#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Lift {
    int currentFloor;
    int totalFloors;

public:
    Lift(int floors) {
        currentFloor = 0;
        totalFloors = floors;
    }

    void goToFloor(int targetFloor) {
        if (targetFloor < 0 || targetFloor >= totalFloors) {
            cout << "Invalid floor! Please choose between 0 and " << totalFloors - 1 << ".\n";
            return;
        }

        cout << "Lift moving from Floor " << currentFloor << " to Floor " << targetFloor << "...\n";

        while (currentFloor != targetFloor) {
            this_thread::sleep_for(chrono::milliseconds(500));
            if (targetFloor > currentFloor) currentFloor++;
            else currentFloor--;
            cout << "Reached Floor: " << currentFloor << endl;
        }

        cout << "Lift arrived at Floor " << currentFloor << "!\n";
    }
};

int main() {
    Lift myLift(5); // Lift with 5 floors: 0 to 4
    int floor;

    while (true) {
        cout << "\nEnter floor number (0-4) or -1 to exit: ";
        cin >> floor;

        if (floor == -1) break;

        myLift.goToFloor(floor);
    }

    cout << "Lift simulation ended.\n";
    return 0;
}
