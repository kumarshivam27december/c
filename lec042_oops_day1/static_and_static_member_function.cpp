#include <bits/stdc++.h>
using namespace std;

class car {
public:
    static int totalcar;

    static double Mileage(float dist, int fuel) {
        return floor(dist / fuel);
    }

    car() {
        totalcar++;
    }
};

int car::totalcar = 0;

int main() {
    car car1;
    car car2;
    car car3;
    car car4;

    cout << "Total no of cars: " << car::totalcar << endl;

    return 0;
}
