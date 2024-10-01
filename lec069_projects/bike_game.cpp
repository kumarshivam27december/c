#include <iostream>
#include <conio.h> // for _kbhit() and _getch()
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <windows.h> // for Sleep()

using namespace std;

const int trackWidth = 20;
const int trackLength = 50;
int playerPos = trackWidth / 2;  // Player's position
int score = 0;                   // Distance traveled
int obstaclePosX = rand() % trackWidth; // Initial obstacle position

void drawTrack() {
    system("cls"); // Clear the console screen

    // Draw the track
    for (int i = 0; i < trackLength; ++i) {
        for (int j = 0; j < trackWidth; ++j) {
            if (i == trackLength - 1 && j == playerPos) {
                cout << "B"; // Player's bike
            } else if (i == score % trackLength && j == obstaclePosX) {
                cout << "O"; // Obstacle
            } else {
                cout << "-"; // Empty track
            }
        }
        cout << endl;
    }

    // Display the score
    cout << "Score: " << score << endl;
}

void updateObstacle() {
    obstaclePosX = rand() % trackWidth; // Randomize obstacle position
}

bool checkCollision() {
    return (playerPos == obstaclePosX && score % trackLength == trackLength - 1);
}

int main() {
    srand(time(0)); // Initialize random seed
    bool gameOver = false;

    while (!gameOver) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' && playerPos > 0) {
                --playerPos; // Move left
            } else if (ch == 'd' && playerPos < trackWidth - 1) {
                ++playerPos; // Move right
            }
        }

        drawTrack();
        Sleep(200); // Delay to slow down the game

        // Check for collision
        if (checkCollision()) {
            gameOver = true;
            cout << "Game Over! You hit an obstacle!" << endl;
        }

        // Update game state
        ++score;
        if (score % 10 == 0) { // Generate new obstacle every 10 steps
            updateObstacle();
        }
    }

    return 0;
}
