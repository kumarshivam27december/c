// magnet_field.cpp
// Real-time ASCII Magnetic Field Simulation (single file C++)
// Compile: g++ magnet_field.cpp -o magnet_field -std=c++17
// Run: ./magnet_field  (Ctrl + C to exit)

#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

struct Magnet {
    float x, y;   // position
    float charge; // + or -
};

int main() {
    const int W = 90;
    const int H = 35;
    float t = 0.0;

    // Two magnets moving around
    vector<Magnet> mags = {
        { -15.0f, 0.0f, +1.0f },
        { +15.0f, 0.0f, -1.0f }
    };

    cout << "\033[?25l"; // hide cursor

    while (true) {
        cout << "\033[H";

        // Make magnets move in circular orbits
        mags[0].x = 20 * cos(t * 0.8);
        mags[0].y = 10 * sin(t * 0.6);

        mags[1].x = 20 * cos(t * 0.6 + 3.14);
        mags[1].y = 10 * sin(t * 0.9);

        for (int y = -H/2; y < H/2; y++) {
            for (int x = -W/2; x < W/2; x++) {

                float fx = 0, fy = 0;

                // Sum magnetic influence from each magnet
                for (auto &m : mags) {
                    float dx = x - m.x;
                    float dy = y - m.y;
                    float dist = sqrt(dx*dx + dy*dy) + 0.001;

                    // Field direction
                    float force = m.charge / (dist * dist);

                    fx += force * (dx / dist);
                    fy += force * (dy / dist);
                }

                // map vector angle to ASCII
                float angle = atan2(fy, fx);
                char c;

                if (angle > 2.5) c = '<';
                else if (angle > 1.0) c = '^';
                else if (angle > -1.0) c = '>';
                else if (angle > -2.5) c = 'v';
                else c = '<';

                cout << c;
            }
            cout << "\n";
        }

        t += 0.05;
        this_thread::sleep_for(chrono::milliseconds(60));
    }

    return 0;
}
