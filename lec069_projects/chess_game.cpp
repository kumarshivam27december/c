#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 8;

class ChessGame {
public:
    ChessGame() {
        // Initialize the board
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                board[i][j] = '.';
            }
        }
        // Set up pieces (simplified)
        board[0][0] = board[0][7] = 'R'; // Rooks
        board[0][1] = board[0][6] = 'N'; // Knights
        board[0][2] = board[0][5] = 'B'; // Bishops
        board[0][3] = 'Q'; // Queen
        board[0][4] = 'K'; // King
        for (int j = 0; j < BOARD_SIZE; ++j) board[1][j] = 'P'; // Pawns

        // AI turn flag
        isAITurn = false;
    }

    void play() {
        while (true) {
            printBoard();
            if (isAITurn) {
                aiMove();
            } else {
                playerMove();
            }
            isAITurn = !isAITurn; // Toggle turn
        }
    }

private:
    char board[BOARD_SIZE][BOARD_SIZE];
    bool isAITurn;

    void printBoard() {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void playerMove() {
        string move;
        cout << "Enter your move (e.g., e2 e4): ";
        cin >> move;
        // Simplified input handling (not robust)
        int startX = move[1] - '1';
        int startY = move[0] - 'a';
        int endX = move[4] - '1';
        int endY = move[3] - 'a';

        // Move the piece
        if (isValidMove(startX, startY, endX, endY)) {
            board[endX][endY] = board[startX][startY];
            board[startX][startY] = '.';
        } else {
            cout << "Invalid move! Try again." << endl;
            playerMove(); // Retry
        }
    }

    void aiMove() {
        vector<pair<int, int>> legalMoves;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] != '.' && islower(board[i][j])) { // AI plays as black
                    for (int x = 0; x < BOARD_SIZE; ++x) {
                        for (int y = 0; y < BOARD_SIZE; ++y) {
                            if (isValidMove(i, j, x, y)) {
                                legalMoves.emplace_back(i, j);
                            }
                        }
                    }
                }
            }
        }

        if (!legalMoves.empty()) {
            srand(time(0));
            auto move = legalMoves[rand() % legalMoves.size()];
            cout << "AI moves: " << (char)(move.second + 'a') << (move.first + 1) << " to ";
            // Just a random destination for simplicity
            int randomX = rand() % BOARD_SIZE;
            int randomY = rand() % BOARD_SIZE;
            cout << (char)(randomY + 'a') << (randomX + 1) << endl;

            board[randomX][randomY] = board[move.first][move.second];
            board[move.first][move.second] = '.';
        }
    }

    bool isValidMove(int startX, int startY, int endX, int endY) {
        // Basic bounds checking (not full chess rules)
        return startX >= 0 && startX < BOARD_SIZE && startY >= 0 && startY < BOARD_SIZE &&
               endX >= 0 && endX < BOARD_SIZE && endY >= 0 && endY < BOARD_SIZE &&
               (board[startX][startY] != '.' && board[endX][endY] == '.' || islower(board[endX][endY]));
    }
};

int main() {
    ChessGame game;
    game.play();
    return 0;
}
