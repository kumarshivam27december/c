// ant_colony.cpp
// ASCII Ant Colony Simulation (single-file C++)
// Emergent AI-like behavior using pheromone trails
// Compile: g++ ant_colony.cpp -o ants -std=c++17
// Run: ./ants   (Ctrl+C to exit)

#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

struct Ant {
    int x, y;
    int dx, dy; // movement direction
};

int main() {
    const int W = 90;
    const int H = 35;

    vector<vector<float>> pher(H, vector<float>(W, 0.0));
    vector<Ant> ants;

    // Initialize ants
    for (int i = 0; i < 60; i++) {
        ants.push_back({W/2, H/2, (rand()%3)-1, (rand()%3)-1});
    }

    // Random food source
    int foodX = rand() % W;
    int foodY = rand() % H;

    cout << "\033[?25l"; // hide cursor

    while (true) {
        // Pheromone evaporation
        for (int y = 0; y < H; y++)
            for (int x = 0; x < W; x++)
                pher[y][x] *= 0.97;  // fade over time

        // Ant behavior update
        for (auto &a : ants) {

            // Deposit pheromone where ant is
            pher[a.y][a.x] += 1.0;

            // Move toward gradient (simple swarm AI)
            int bestDx = a.dx;
            int bestDy = a.dy;
            float bestP = -1;

            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) continue;

                    int nx = a.x + dx;
                    int ny = a.y + dy;

                    if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;

                    float p = pher[ny][nx];

                    // Prefer stronger pheromones
                    if (p > bestP) {
                        bestP = p;
                        bestDx = dx;
                        bestDy = dy;
                    }
                }
            }

            // Move ant
            a.dx = bestDx;
            a.dy = bestDy;
            a.x += a.dx;
            a.y += a.dy;

            // Keep inside bounds
            if (a.x < 0) a.x = 0;
            if (a.x >= W) a.x = W-1;
            if (a.y < 0) a.y = 0;
            if (a.y >= H) a.y = H-1;
        }

        // Draw everything
        cout << "\033[H";
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {

                if (x == foodX && y == foodY) {
                    cout << "@"; // food
                    continue;
                }

                bool isAnt = false;
                for (auto &a : ants)
                    if (a.x == x && a.y == y) { isAnt = true; break; }

                if (isAnt)
                    cout << "a";
                else {
                    float p = pher[y][x];
                    const string shade = " .:-=+*#%@";
                    int idx = min((int)shade.size()-1, (int)(p));
                    cout << shade[idx];
                }
            }
            cout << "\n";
        }

        this_thread::sleep_for(std::chrono::milliseconds(70));
    }

    return 0;
}
