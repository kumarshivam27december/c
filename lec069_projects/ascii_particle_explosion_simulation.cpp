#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

const int WIDTH = 80;
const int HEIGHT = 25;
const int NUM_PARTICLES = 100;
const float PI = 3.14159265f;

struct Particle {
    float x, y;
    float vx, vy;
};

void clearScreen() {
    // Clear screen using ANSI escape codes
    std::cout << "\033[2J\033[1;1H";
}

void drawScreen(const std::vector<Particle>& particles) {
    char screen[HEIGHT][WIDTH];

    // Fill screen with empty spaces
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            screen[i][j] = ' ';

    for (const auto& p : particles) {
        int px = static_cast<int>(p.x);
        int py = static_cast<int>(p.y);

        if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
            screen[py][px] = '*';
    }

    // Print screen
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
            std::cout << screen[i][j];
        std::cout << '\n';
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<Particle> particles(NUM_PARTICLES);

    // Initialize particles from the center
    float centerX = WIDTH / 2.0f;
    float centerY = HEIGHT / 2.0f;

    for (auto& p : particles) {
        float angle = static_cast<float>(std::rand()) / RAND_MAX * 2 * PI;
        float speed = static_cast<float>(std::rand()) / RAND_MAX * 1.5f + 0.5f;

        p.x = centerX;
        p.y = centerY;
        p.vx = std::cos(angle) * speed;
        p.vy = std::sin(angle) * speed;
    }

    // Simulation loop
    for (int frame = 0; frame < 100; ++frame) {
        clearScreen();

        // Update particles
        for (auto& p : particles) {
            p.x += p.vx;
            p.y += p.vy;
        }

        drawScreen(particles);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
