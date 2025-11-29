// ascii_gravity_well.cpp
// Real-time ASCII Gravity Well (Black Hole) Simulation
// Compile: g++ ascii_gravity_well.cpp -o gravity -std=c++17
// Run: ./gravity   (Ctrl+C to exit)

#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    const int W = 80;
    const int H = 30;

    float t = 0.0f;

    cout << "\033[?25l"; // hide cursor

    while (true) {
        cout << "\033[H"; // move cursor to top-left

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                
                // convert to center-based coordinates
                float cx = x - W/2.0f;
                float cy = y - H/2.0f;

                // rotate space slowly
                float angle = t * 0.3f;
                float rx = cx * cos(angle) - cy * sin(angle);
                float ry = cx * sin(angle) + cy * cos(angle);

                float dist = sqrt(rx*rx + ry*ry);

                // gravity distortion
                float warp = sin(dist * 0.3f - t) * 0.5f;

                // convert warp to ASCII
                const string chars = " .:-=+*#%@";

                int idx = fabs(warp) * (chars.size() - 1);
                if (idx < 0) idx = 0;
                if (idx >= (int)chars.size()) idx = chars.size() - 1;

                cout << chars[idx];
            }
            cout << "\n";
        }

        t += 0.10f;
        this_thread::sleep_for(chrono::milliseconds(40));
    }

    cout << "\033[?25h"; // show cursor
    return 0;
}
