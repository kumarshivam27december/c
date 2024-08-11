#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;
const int NUM_MINES = 10;

// Enum to represent the state of each cell
enum CellState {
    COVERED,
    UNCOVERED,
    FLAGGED
};

// Enum to represent the content of each cell
enum CellContent {
    EMPTY,
    MINE
};

// Function prototypes
void initializeBoard(vector<vector<CellState>>& stateBoard, vector<vector<CellContent>>& contentBoard);
void placeMines(vector<vector<CellContent>>& contentBoard);
void printBoard(const vector<vector<CellState>>& stateBoard, const vector<vector<CellContent>>& contentBoard);
bool isMine(const vector<vector<CellContent>>& contentBoard, int x, int y);
int countAdjacentMines(const vector<vector<CellContent>>& contentBoard, int x, int y);
void uncoverCell(vector<vector<CellState>>& stateBoard, vector<vector<CellContent>>& contentBoard, int x, int y);
void flagCell(vector<vector<CellState>>& stateBoard, int x, int y);
bool isGameOver(const vector<vector<CellState>>& stateBoard, const vector<vector<CellContent>>& contentBoard);
bool isWin(const vector<vector<CellState>>& stateBoard, const vector<vector<CellContent>>& contentBoard);

int main() {
    vector<vector<CellState>> stateBoard(HEIGHT, vector<CellState>(WIDTH, COVERED));
    vector<vector<CellContent>> contentBoard(HEIGHT, vector<CellContent>(WIDTH, EMPTY));

    initializeBoard(stateBoard, contentBoard);
    
    bool gameOver = false;
    bool win = false;

    while (!gameOver && !win) {
        printBoard(stateBoard, contentBoard);

        cout << "Enter your move (x y) or (x y f to flag): ";
        int x, y;
        char action = ' ';
        cin >> x >> y;
        if (cin.peek() == ' ') {
            cin >> action;
        }

        if (action == 'f') {
            flagCell(stateBoard, x, y);
        } else {
            uncoverCell(stateBoard, contentBoard, x, y);
        }

        gameOver = isGameOver(stateBoard, contentBoard);
        win = isWin(stateBoard, contentBoard);
    }

    if (gameOver) {
        cout << "Game Over!" << endl;
    } else if (win) {
        cout << "You Win!" << endl;
    }

    printBoard(stateBoard, contentBoard); // Show final state of the board

    return 0;
}

void initializeBoard(vector<vector<CellState>>& stateBoard, vector<vector<CellContent>>& contentBoard) {
    srand(time(0));
    placeMines(contentBoard);
}

void placeMines(vector<vector<CellContent>>& contentBoard) {
    int placedMines = 0;
    while (placedMines < NUM_MINES) {
        int x = rand() % HEIGHT;
        int y = rand() % WIDTH;
        if (contentBoard[x][y] != MINE) {
            contentBoard[x][y] = MINE;
            placedMines++;
        }
    }
}

void printBoard(const vector<vector<CellState>>& stateBoard, const vector<vector<CellContent>>& contentBoard) {
    for (int y = 0; y < WIDTH; ++y) {
        cout << "  " << y;
    }
    cout << endl;

    for (int x = 0; x < HEIGHT; ++x) {
        cout << x << " ";
        for (int y = 0; y < WIDTH; ++y) {
            if (stateBoard[x][y] == COVERED) {
                cout << ". ";
            } else if (stateBoard[x][y] == FLAGGED) {
                cout << "F ";
            } else {
                if (contentBoard[x][y] == MINE) {
                    cout << "* ";
                } else {
                    int adjMines = countAdjacentMines(contentBoard, x, y);
                    cout << adjMines << " ";
                }
            }
        }
        cout << endl;
    }
}

bool isMine(const vector<vector<CellContent>>& contentBoard, int x, int y) {
    return contentBoard[x][y] == MINE;
}

int countAdjacentMines(const vector<vector<CellContent>>& contentBoard, int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH && isMine(contentBoard, nx, ny)) {
                ++count;
            }
        }
    }
    return count;
}

void uncoverCell(vector<vector<CellState>>& stateBoard, vector<vector<CellContent>>& contentBoard, int x, int y) {
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH) return;
    if (stateBoard[x][y] != COVERED) return;

    stateBoard[x][y] = UNCOVERED;

    if (isMine(contentBoard, x, y)) {
        return; // Hit a mine; game over
    }

    int adjMines = countAdjacentMines(contentBoard, x, y);
    if (adjMines == 0) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                uncoverCell(stateBoard, contentBoard, x + dx, y + dy);
            }
        }
    }
}

void flagCell(vector<vector<CellState>>& stateBoard, int x, int y) {
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH) return;
    if (stateBoard[x][y] == COVERED) {
        stateBoard[x][y] = FLAGGED;
    } else if (stateBoard[x][y] == FLAGGED) {
        stateBoard[x][y] = COVERED;
    }
}

bool isGameOver(const vector<vector<CellState>>& stateBoard, const vector<vector<CellContent>>& contentBoard) {
    for (int x = 0; x < HEIGHT; ++x) {
        for (int y = 0; y < WIDTH; ++y) {
            if (stateBoard[x][y] == UNCOVERED && isMine(contentBoard, x, y)) {
                return true;
            }
        }
    }
    return false;
}

bool isWin(const vector<vector<CellState>>& stateBoard, const vector<vector<CellContent>>& contentBoard) {
    for (int x = 0; x < HEIGHT; ++x) {
        for (int y = 0; y < WIDTH; ++y) {
            if (stateBoard[x][y] == COVERED && contentBoard[x][y] != MINE) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    // Constants
    const int WIDTH = 10;
    const int HEIGHT = 10;
    const int NUM_MINES = 10;

    // Initialize the game board
    vector<vector<CellState>> stateBoard(HEIGHT, vector<CellState>(WIDTH, COVERED));
    vector<vector<CellContent>> contentBoard(HEIGHT, vector<CellContent>(WIDTH, EMPTY));
    initializeBoard(stateBoard, contentBoard);

    bool gameOver = false;
    bool win = false;

    while (!gameOver && !win) {
        printBoard(stateBoard, contentBoard);

        cout << "Enter your move (x y) or (x y f to flag): ";
        int x, y;
        char action = ' ';
        cin >> x >> y;
        if (cin.peek() == ' ') {
            cin >> action;
        }

        if (action == 'f') {
            flagCell(stateBoard, x, y);
        } else {
            uncoverCell(stateBoard, contentBoard, x, y);
        }

        gameOver = isGameOver(stateBoard, contentBoard);
        win = isWin(stateBoard, contentBoard);
    }

    if (gameOver) {
        cout << "Game Over!" << endl;
    } else if (win) {
        cout << "You Win!" << endl;
    }

    printBoard(stateBoard, contentBoard); // Show final state of the board

    return 0;
}


