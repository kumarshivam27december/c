// wormhole.cpp
// Fly through a real-time ASCII wormhole (single-file C++)
// Compile: g++ wormhole.cpp -o wormhole -std=c++17
// Run: ./wormhole   (Ctrl + C to exit)

#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    const int W = 90;
    const int H = 35;
    float t = 0.0;

    cout << "\033[?25l"; // hide cursor

    while (true) {
        cout << "\033[H"; // move to top

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {

                // Convert screen coords to centered coordinates
                float cx = (x - W/2.0f);
                float cy = (y - H/2.0f);

                // radial distance
                float dist = sqrt(cx*cx + cy*cy);

                // simulate “warp speed” depth
                float depth = sin(dist * 0.1 - t * 5.0);

                // brightness mapping
                const string shades = " .:-=+*#%@";
                int idx = (depth + 1.0f) * (shades.size() / 2.0f);
                if (idx < 0) idx = 0;
                if (idx >= (int)shades.size()) idx = shades.size() - 1;

                cout << shades[idx];
            }
            cout << "\n";
        }

        t += 0.03f;
        this_thread::sleep_for(chrono::milliseconds(40));
    }

    cout << "\033[?25h"; // show cursor
    return 0;
}
