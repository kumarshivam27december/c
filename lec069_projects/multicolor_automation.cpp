// multicolor_automaton.cpp
// Multicolor Cellular Automaton (Rainbow Life)
// Single-file C++
// Compile: g++ multicolor_automaton.cpp -o rainbow -std=c++17
// Run: ./rainbow   (Ctrl+C to exit)

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

struct Cell {
    int r, g, b; // color components
};

int clamp(int x, int lo, int hi) {
    return max(lo, min(hi, x));
}

int main() {
    const int W = 90;
    const int H = 35;

    vector<vector<Cell>> grid(H, vector<Cell>(W));
    vector<vector<Cell>> next(H, vector<Cell>(W));

    // Random initialization
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++) {
            grid[y][x].r = rand() % 256;
            grid[y][x].g = rand() % 256;
            grid[y][x].b = rand() % 256;
        }

    cout << "\033[?25l"; // hide cursor

    while (true) {
        cout << "\033[H";

        // Draw
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                Cell &c = grid[y][x];
                cout << "\033[48;2;" << c.r << ";" << c.g << ";" << c.b << "m ";
            }
            cout << "\033[0m\n";
        }

        // Update rules (Smooth color diffusion)
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {

                int sumR = 0, sumG = 0, sumB = 0;
                int count = 0;

                // neighbors
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int ny = y + dy;
                        int nx = x + dx;

                        if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                            sumR += grid[ny][nx].r;
                            sumG += grid[ny][nx].g;
                            sumB += grid[ny][nx].b;
                            count++;
                        }
                    }
                }

                // average neighbors = color blending
                int avgR = sumR / count;
                int avgG = sumG / count;
                int avgB = sumB / count;

                // Apply slight shift (color evolution)
                next[y][x].r = clamp(avgR + rand()%7 - 3, 0, 255);
                next[y][x].g = clamp(avgG + rand()%7 - 3, 0, 255);
                next[y][x].b = clamp(avgB + rand()%7 - 3, 0, 255);
            }
        }

        grid = next;
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }

    cout << "\033[?25h"; // show cursor (never reached)
}
