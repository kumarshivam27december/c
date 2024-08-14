#include <iostream>
#include <conio.h>  // For _getch() and _kbhit()
#include <windows.h>  // For Sleep()
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Define constants
const int WIDTH = 20;
const int HEIGHT = 10;
const char EMPTY = ' ';
const char SNAKE_HEAD = '@';
const char SNAKE_BODY = '#';
const char FRUIT = '*';

// Directions
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

// Define the Snake
struct Snake {
    vector<pair<int, int>> body;
    Direction dir;
};

// Initialize the game
void setup(Snake &snake, pair<int, int> &fruit) {
    snake.body.clear();
    snake.body.push_back({WIDTH / 2, HEIGHT / 2});
    snake.dir = STOP;
    fruit = {rand() % WIDTH, rand() % HEIGHT};
}

// Draw the game
void draw(const Snake &snake, const pair<int, int> &fruit) {
    system("cls");  // Clear screen (Windows specific, use "clear" for Unix)
    
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
                cout << '#';  // Walls
            else if (x == fruit.first && y == fruit.second)
                cout << FRUIT;  // Fruit
            else {
                bool printed = false;
                for (const auto &s : snake.body) {
                    if (s.first == x && s.second == y) {
                        cout << (s == snake.body.front() ? SNAKE_HEAD : SNAKE_BODY);
                        printed = true;
                        break;
                    }
                }
                if (!printed)
                    cout << EMPTY;
            }
        }
        cout << endl;
    }
}

// Update the snake's position
void update(Snake &snake, pair<int, int> &fruit, bool &gameOver) {
    pair<int, int> newHead = snake.body.front();
    switch (snake.dir) {
        case LEFT:  --newHead.first; break;
        case RIGHT: ++newHead.first; break;
        case UP:    --newHead.second; break;
        case DOWN:  ++newHead.second; break;
        default: break;
    }

    // Check for collisions
    if (newHead.first == 0 || newHead.first == WIDTH - 1 ||
        newHead.second == 0 || newHead.second == HEIGHT - 1) {
        gameOver = true;
        return;
    }

    for (const auto &s : snake.body) {
        if (s == newHead) {
            gameOver = true;
            return;
        }
    }

    snake.body.insert(snake.body.begin(), newHead);
    if (newHead == fruit) {
        fruit = {rand() % WIDTH, rand() % HEIGHT};
    } else {
        snake.body.pop_back();
    }
}

// Main game loop
int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed for random number generation

    Snake snake;
    pair<int, int> fruit;
    bool gameOver = false;
    char key = ' ';

    setup(snake, fruit);

    while (!gameOver) {
        if (_kbhit()) {
            key = _getch();
            switch (key) {
                case 'a': if (snake.dir != RIGHT) snake.dir = LEFT; break;
                case 'd': if (snake.dir != LEFT) snake.dir = RIGHT; break;
                case 'w': if (snake.dir != DOWN) snake.dir = UP; break;
                case 's': if (snake.dir != UP) snake.dir = DOWN; break;
                case 'x': gameOver = true; break;  // Quit game
            }
        }

        update(snake, fruit, gameOver);
        draw(snake, fruit);
        Sleep(100);  // Sleep for 100 milliseconds
    }

    cout << "Game Over!" << endl;
    return 0;
}
