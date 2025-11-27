// ascii_ocean.cpp
// Real-time ASCII Ocean Simulation (single-file C++)
// Compile: g++ ascii_ocean.cpp -o ascii_ocean -std=c++17
// Run: ./ascii_ocean  (Ctrl+C to exit)

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

int main() {
    const int W = 80;   // width
    const int H = 25;   // height
    float t = 0.0f;     // time

    // Characters representing wave heights
    const string chars = " .~-^*#%@";

    cout << "\033[?25l"; // hide cursor

    while (true) {
        cout << "\033[H"; // move to top-left

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {

                // Wave equation combining multiple sine waves
                float v =
                    sin((x * 0.12) + t) * 0.6 +
                    sin((x * 0.07) + (t * 1.7)) * 0.3 +
                    sin((y * 0.15) + (t * 0.8)) * 0.4;

                // Normalize to 0..1
                float n = (v + 1.3f) / 2.6f;
                if (n < 0) n = 0;
                if (n > 1) n = 1;

                int idx = n * (chars.size() - 1);
                cout << chars[idx];
            }
            cout << "\n";
        }

        t += 0.10f;
        this_thread::sleep_for(chrono::milliseconds(60)); // smooth animation
    }

    cout << "\033[?25h"; // show cursor
    return 0;
}
