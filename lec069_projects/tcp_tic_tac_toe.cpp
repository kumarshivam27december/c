// tic_tac_toe_net.cpp
// Multiplayer Tic-Tac-Toe over TCP
// Compile: g++ tic_tac_toe_net.cpp -o tic_tac_toe
// Run server: ./tic_tac_toe server <port>
// Run client: ./tic_tac_toe client <ip> <port>

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

char board[3][3];
int currentPlayer = 0; // 0 = X, 1 = O

void initBoard() {
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) board[i][j] = ' ';
}

void printBoard() {
    cout << "\n";
    for (int i=0;i<3;i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i<2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char mark) {
    for (int i=0;i<3;i++)
        if (board[i][0]==mark && board[i][1]==mark && board[i][2]==mark) return true;
    for (int j=0;j<3;j++)
        if (board[0][j]==mark && board[1][j]==mark && board[2][j]==mark) return true;
    if (board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) return true;
    if (board[0][2]==mark && board[1][1]==mark && board[2][0]==mark) return true;
    return false;
}

bool boardFull() {
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (board[i][j]==' ') return false;
    return true;
}

void serverMode(int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 2);

    cout << "Waiting for 2 players..." << endl;
    int player1 = accept(server_fd, nullptr, nullptr);
    int player2 = accept(server_fd, nullptr, nullptr);

    cout << "Two players connected! Starting game.\n";
    initBoard();

    int players[2] = {player1, player2};
    char marks[2] = {'X', 'O'};

    while (true) {
        int p = currentPlayer;
        int sock = players[p];
        char mark = marks[p];

        string boardState;
        for (int i=0;i<3;i++) for (int j=0;j<3;j++) boardState.push_back(board[i][j]);
        send(sock, boardState.c_str(), boardState.size(), 0);

        char move[2];
        recv(sock, move, sizeof(move), 0);
        int r = move[0]-'0';
        int c = move[1]-'0';

        if (board[r][c]==' ') {
            board[r][c]=mark;
            if (checkWin(mark)) {
                string msg = "Player ";
                msg.push_back(mark);
                msg += " wins!\n";
                for (int i=0;i<2;i++) send(players[i], msg.c_str(), msg.size(), 0);
                break;
            } else if (boardFull()) {
                string msg = "It's a draw!\n";
                for (int i=0;i<2;i++) send(players[i], msg.c_str(), msg.size(), 0);
                break;
            }
            currentPlayer = 1-p;
        }
    }

    close(player1);
    close(player2);
    close(server_fd);
}

void clientMode(string ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serv{};
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serv.sin_addr);

    if (connect(sock, (sockaddr*)&serv, sizeof(serv)) < 0) {
        perror("connect");
        return;
    }

    cout << "Connected! Wait for your turn...\n";

    while (true) {
        char boardState[9];
        int n = recv(sock, boardState, sizeof(boardState), 0);
        if (n <= 0) break;

        for (int i=0;i<3;i++) for (int j=0;j<3;j++) board[i][j] = boardState[i*3+j];
        printBoard();

        cout << "Enter move (row col, 0-based): ";
        int r,c;
        cin >> r >> c;
        char move[2] = {(char)('0'+r),(char)('0'+c)};
        send(sock, move, sizeof(move), 0);

        char msg[128];
        n = recv(sock, msg, sizeof(msg)-1, MSG_DONTWAIT);
        if (n > 0) {
            msg[n]='\0';
            cout << msg << endl;
            break;
        }
    }
    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage:\n  Server: ./tic_tac_toe server <port>\n  Client: ./tic_tac_toe client <ip> <port>\n";
        return 1;
    }

    string mode = argv[1];
    if (mode=="server") {
        int port = stoi(argv[2]);
        serverMode(port);
    } else if (mode=="client") {
        if (argc < 4) {
            cerr << "Client Usage: ./tic_tac_toe client <ip> <port>\n";
            return 1;
        }
        string ip = argv[2];
        int port = stoi(argv[3]);
        clientMode(ip, port);
    }
    return 0;
}
