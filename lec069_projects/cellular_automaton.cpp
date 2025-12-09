// cellular_automaton.cpp
// ASCII Cellular Automaton (Game of Life) Simulator - single-file C++
// Compile: g++ cellular_automaton.cpp -o automaton -std=c++17
// Run: ./automaton  (Ctrl+C to exit)

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

int main() {
    const int W = 90;
    const int H = 35;

    vector<vector<int>> grid(H, vector<int>(W, 0));
    vector<vector<int>> next(H, vector<int>(W, 0));

    // Randomize initial state
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            grid[y][x] = rand() % 5 == 0;  // 20% alive

    cout << "\033[?25l"; // hide cursor

    while (true) {
        cout << "\033[H"; // move cursor to top-left

        // Draw current generation
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                cout << (grid[y][x] ? "█" : " ");
            }
            cout << "\n";
        }

        // Compute next generation (Game of Life rules)
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {

                int alive = 0;

                // Check 8 neighbors
                for (int dy = -1; dy <= 1; dy++)
                    for (int dx = -1; dx <= 1; dx++)
                        if (!(dx == 0 && dy == 0)) {
                            int ny = y + dy, nx = x + dx;
                            if (nx >= 0 && nx < W && ny >= 0 && ny < H)
                                alive += grid[ny][nx];
                        }

                // Apply Conway's rules
                if (grid[y][x]) {
                    // Alive cell survives only with 2 or 3 neighbors
                    next[y][x] = (alive == 2 || alive == 3);
                } else {
                    // Dead cell becomes alive with exactly 3 neighbors
                    next[y][x] = (alive == 3);
                }
            }
        }

        // Copy next → grid
        grid = next;

        // Frame speed
        this_thread::sleep_for(chrono::milliseconds(70));
    }

    cout << "\033[?25h"; // show cursor (never reached)
    return 0;
}
