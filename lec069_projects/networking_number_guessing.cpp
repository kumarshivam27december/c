// guess_game.cpp
// Simple TCP number guessing game (server + client) in one file.
// Compile: g++ guess_game.cpp -o guess_game
//
// Usage:
//   ./guess_game server   -> server listens on port 7070
//   ./guess_game client   -> client connects and plays

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;
const int PORT = 7070;

void run_server() {
    srand(time(0));
    int secret = rand() % 100 + 1; // 1–100
    cout << "Server started. Secret number chosen.\n";

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) { perror("bind"); return; }
    if (listen(server_fd, 1) < 0) { perror("listen"); return; }

    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0) { perror("accept"); return; }
    cout << "Client connected! Game begins.\n";

    char buf[128];
    while (true) {
        int n = recv(client_fd, buf, sizeof(buf)-1, 0);
        if (n <= 0) break;
        buf[n] = '\0';
        int guess = atoi(buf);
        string reply;
        if (guess < secret) reply = "Too Low\n";
        else if (guess > secret) reply = "Too High\n";
        else { reply = "Correct!\n"; send(client_fd, reply.c_str(), reply.size(), 0); break; }
        send(client_fd, reply.c_str(), reply.size(), 0);
    }
    close(client_fd);
    close(server_fd);
    cout << "Game over. Server exiting.\n";
}

void run_client() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    if (connect(sock, (sockaddr*)&addr, sizeof(addr)) < 0) { perror("connect"); return; }

    cout << "Connected! Guess the number (1–100).\n";
    string input;
    char buf[128];

    while (true) {
        cout << "Enter guess: ";
        getline(cin, input);
        send(sock, input.c_str(), input.size(), 0);
        int n = recv(sock, buf, sizeof(buf)-1, 0);
        if (n <= 0) break;
        buf[n] = '\0';
        cout << "Server: " << buf;
        if (string(buf).find("Correct") != string::npos) break;
    }
    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " server|client\n";
        return 1;
    }
    string mode = argv[1];
    if (mode == "server") run_server();
    else if (mode == "client") run_client();
    else cerr << "Unknown mode. Use server|client\n";
    return 0;
}
