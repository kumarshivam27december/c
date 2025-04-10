#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

const int WIDTH = 80;
const int HEIGHT = 25;
const int NUM_BALLS = 10;
const float GRAVITY = 0.3f;
const float BOUNCE_DAMPING = 0.8f;

struct Ball {
    float x, y;
    float vy;
};

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void drawScreen(const std::vector<Ball>& balls) {
    char screen[HEIGHT][WIDTH];

    // Fill with spaces
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            screen[i][j] = ' ';

    // Draw balls
    for (const auto& b : balls) {
        int px = static_cast<int>(b.x);
        int py = static_cast<int>(b.y);

        if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
            screen[py][px] = 'O';
    }

    // Render
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
            std::cout << screen[i][j];
        std::cout << '\n';
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<Ball> balls(NUM_BALLS);

    // Init balls with random horizontal position and zero velocity
    for (auto& b : balls) {
        b.x = std::rand() % WIDTH;
        b.y = 0;
        b.vy = 0;
    }

    // Main simulation loop
    for (int frame = 0; frame < 300; ++frame) {
        clearScreen();

        for (auto& b : balls) {
            // Apply gravity
            b.vy += GRAVITY;
            b.y += b.vy;

            // Bounce if hitting the floor
            if (b.y >= HEIGHT - 1) {
                b.y = HEIGHT - 1;
                b.vy *= -BOUNCE_DAMPING;

                // Simulate energy loss
                if (std::abs(b.vy) < 0.5f) {
                    b.vy = 0;
                }
            }
        }

        drawScreen(balls);
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }

    return 0;
}
