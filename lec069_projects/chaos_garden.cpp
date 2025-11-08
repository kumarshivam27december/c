// chaos_garden.cpp
// Watch a fractal fern grow from mathematical chaos (single-file C++)
// Compile: g++ chaos_garden.cpp -o chaos_garden -std=c++17
// Run: ./chaos_garden
// Exit with Ctrl+C

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    const int width = 80, height = 40;
    const double scaleX = 6.0, scaleY = 10.0;

    vector<string> screen(height, string(width, ' '));
    double x = 0.0, y = 0.0;

    cout << "\033[2J\033[H"; // clear screen

    while (true) {
        int r = rand() % 100;
        double nextX, nextY;

        if (r < 1) { // stem
            nextX = 0.0;
            nextY = 0.16 * y;
        } else if (r < 86) { // successively smaller leaflets
            nextX = 0.85 * x + 0.04 * y;
            nextY = -0.04 * x + 0.85 * y + 1.6;
        } else if (r < 93) { // left leaflet
            nextX = 0.20 * x - 0.26 * y;
            nextY = 0.23 * x + 0.22 * y + 1.6;
        } else { // right leaflet
            nextX = -0.15 * x + 0.28 * y;
            nextY = 0.26 * x + 0.24 * y + 0.44;
        }

        x = nextX;
        y = nextY;

        int px = (int)(width / 2 + x * scaleX);
        int py = (int)(height - y * scaleY);

        if (px >= 0 && px < width && py >= 0 && py < height)
            screen[py][px] = '*';

        // display every few points
        static int counter = 0;
        if (++counter % 100 == 0) {
            cout << "\033[H";
            for (auto &row : screen) cout << row << "\n";
            cout << "\n🌿 Growing ChaosGarden... (Ctrl+C to stop)\n";
            this_thread::sleep_for(chrono::milliseconds(40));
        }
    }
}
