#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;
int rollDice() {
    return rand() % 6 + 1;
}

int applySnakeOrLadder(int pos, map<int, int>& snakes, map<int, int>& ladders) {
    if (snakes.count(pos)) {
        cout << "Snake! Down from " << pos << " to " << snakes[pos] << endl;
        return snakes[pos];
    }
    if (ladders.count(pos)) {
        cout << "Ladder! Up from " << pos << " to " << ladders[pos] << endl;
        return ladders[pos];
    }
    return pos;
}

int main() {
    srand(time(0)); 

    int player1Pos = 0;
    int player2Pos = 0;
    int winner = -1;
    int turn = 1; //for player 1 and turn 2 for player 2



    map<int, int> snakes = {
        {99, 21}, {95, 75}, {70, 55}, {52, 42}
    };
    map<int, int> ladders = {
        {3, 22}, {5, 8}, {20, 38}, {36, 57}
    };


    while (winner == -1) {
        cout << "\nPlayer " << turn << "'s turn..." << endl;
        int dice = rollDice();
        cout << "Rolled: " << dice << endl;

        if (turn == 1) {
            if (player1Pos + dice <= 100) {
                player1Pos += dice;
                player1Pos = applySnakeOrLadder(player1Pos, snakes, ladders);
                cout << "player 1 is now at: " << player1Pos << endl;
            } else {
                cout << "player 1 needs exact roll to reach 100." << endl;
            }

            if (player1Pos == 100) {
                winner = 1;
                break;
            }

            if (dice != 6) turn = 2; 
            else cout << "player 1 gets another turn because of the 6 he got !" << endl;
        }

        else {
            if (player2Pos + dice <= 100) {
                player2Pos += dice;
                player2Pos = applySnakeOrLadder(player2Pos, snakes, ladders);
                cout << "player 2 is now at: " << player2Pos << endl;
            } else {
                cout << "player 2 needs exact roll to reach 100." << endl;
            }

            if (player2Pos == 100) {
                winner = 2;
                break;
            }

            if (dice != 6) turn = 1; 
            else cout << "player 2 gets another turn because of the 6 he got!" << endl;
        }
    }

    string name;
    name = (winner==1)?"abhay":"shivam";
    cout << "\n  " << name << " wins the game!" << endl;
    return 0;
}