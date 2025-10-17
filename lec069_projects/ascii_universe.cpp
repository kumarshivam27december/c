// ascii_universe.cpp
// Terminal Universe Simulator — watch stars move and merge (single-file C++)
// Compile: g++ ascii_universe.cpp -o ascii_universe -std=c++17 -O2
// Run: ./ascii_universe

#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Star {
    double x, y;
    double vx, vy;
    double mass;
};

int main() {
    srand(time(0));
    const int W = 60, H = 20;
    const double G = 0.02;  // gravity constant
    vector<Star> stars;

    // create random stars
    for (int i = 0; i < 12; i++) {
        stars.push_back({rand()%W, rand()%H, (rand()%100-50)/100.0, (rand()%100-50)/100.0, 1.0});
    }

    while (true) {
        // physics update
        for (size_t i=0;i<stars.size();i++){
            for (size_t j=i+1;j<stars.size();j++){
                double dx = stars[j].x - stars[i].x;
                double dy = stars[j].y - stars[i].y;
                double dist = sqrt(dx*dx + dy*dy) + 0.1;
                double force = G * stars[i].mass * stars[j].mass / (dist*dist);
                double fx = force * dx / dist;
                double fy = force * dy / dist;
                stars[i].vx += fx / stars[i].mass;
                stars[i].vy += fy / stars[i].mass;
                stars[j].vx -= fx / stars[j].mass;
                stars[j].vy -= fy / stars[j].mass;

                // merge if too close
                if (dist < 0.5) {
                    stars[i].mass += stars[j].mass;
                    stars.erase(stars.begin()+j);
                    j--;
                }
            }
        }

        // position update
        for (auto &s : stars) {
            s.x += s.vx;
            s.y += s.vy;
            if (s.x < 0 || s.x >= W) s.vx *= -1;
            if (s.y < 0 || s.y >= H) s.vy *= -1;
        }

        // draw universe
        vector<string> grid(H, string(W, ' '));
        for (auto &s : stars) {
            int xi = (int)s.x, yi = (int)s.y;
            if (xi>=0 && xi<W && yi>=0 && yi<H)
                grid[yi][xi] = (s.mass > 2) ? 'O' : '*';
        }

        // clear screen
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "=== ASCII Universe ===\n";
        for (auto &row : grid) cout << row << "\n";
        cout << "Stars: " << stars.size() << "   (They merge when close!)\n";

        this_thread::sleep_for(chrono::milliseconds(150));
    }
}
