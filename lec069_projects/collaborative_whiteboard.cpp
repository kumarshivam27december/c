// net_whiteboard.cpp
// Unique Collaborative ASCII Whiteboard over TCP
// Compile: g++ net_whiteboard.cpp -o net_whiteboard -pthread
// Run server: ./net_whiteboard server <port>
// Run client: ./net_whiteboard client <ip> <port>

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

char board[10][20];       // 10x20 ASCII whiteboard
mutex boardMutex;
vector<int> clients;      // list of connected clients
mutex clientsMutex;

void printBoardToClient(int client_fd) {
    string msg = "\n--- Whiteboard ---\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) msg.push_back(board[i][j]);
        msg.push_back('\n');
    }
    msg += "Type: <row> <col> <char>\n";
    send(client_fd, msg.c_str(), msg.size(), 0);
}

void broadcastBoard() {
    lock_guard<mutex> lock(clientsMutex);
    string msg = "\n--- Whiteboard Updated ---\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) msg.push_back(board[i][j]);
        msg.push_back('\n');
    }
    for (int fd : clients) {
        send(fd, msg.c_str(), msg.size(), 0);
    }
}

void handleClient(int client_fd) {
    {
        lock_guard<mutex> lock(clientsMutex);
        clients.push_back(client_fd);
    }

    printBoardToClient(client_fd);

    char buffer[1024];
    while (true) {
        int n = recv(client_fd, buffer, 1023, 0);
        if (n <= 0) break;
        buffer[n] = '\0';

        int r, c;
        char ch;
        if (sscanf(buffer, "%d %d %c", &r, &c, &ch) == 3) {
            if (r >= 0 && r < 10 && c >= 0 && c < 20) {
                lock_guard<mutex> lock(boardMutex);
                board[r][c] = ch;
                broadcastBoard();
            }
        }
    }
    close(client_fd);
    {
        lock_guard<mutex> lock(clientsMutex);
        clients.erase(remove(clients.begin(), clients.end(), client_fd), clients.end());
    }
}

void serverMode(int port) {
    // init board with dots
    for (int i = 0; i < 10; i++) for (int j = 0; j < 20; j++) board[i][j] = '.';

    int srv = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(srv, (sockaddr*)&addr, sizeof(addr));
    listen(srv, 5);

    cout << "Whiteboard server running on port " << port << "...\n";
    while (true) {
        int client_fd = accept(srv, nullptr, nullptr);
        thread(handleClient, client_fd).detach();
    }
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

    thread([&]() {
        char buf[2048];
        while (true) {
            int n = recv(sock, buf, 2047, 0);
            if (n <= 0) break;
            buf[n] = '\0';
            cout << buf << endl;
        }
    }).detach();

    string input;
    while (getline(cin, input)) {
        send(sock, input.c_str(), input.size(), 0);
    }
    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage:\n  Server: ./net_whiteboard server <port>\n"
             << "  Client: ./net_whiteboard client <ip> <port>\n";
        return 1;
    }

    string mode = argv[1];
    if (mode == "server") serverMode(stoi(argv[2]));
    else if (mode == "client") clientMode(argv[2], stoi(argv[3]));
    return 0;
}
