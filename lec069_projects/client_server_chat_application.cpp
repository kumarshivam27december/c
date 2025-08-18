// chat.cpp
// A very simple TCP chat program (server or client) in one file.
// Compile: g++ chat.cpp -o chat
// Run server: ./chat server
// Run client: ./chat client

#include <iostream>
#include <string>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

void recv_messages(int sock) {
    char buf[1024];
    while (true) {
        int n = recv(sock, buf, sizeof(buf)-1, 0);
        if (n <= 0) {
            cout << "Connection closed.\n";
            break;
        }
        buf[n] = '\0';
        cout << "\n[Peer]: " << buf << "\n> " << flush;
    }
}

int run_server() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return 1; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); return 1;
    }

    if (listen(server_fd, 1) < 0) {
        perror("listen"); return 1;
    }
    cout << "Server listening on port 8080...\n";

    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0) { perror("accept"); return 1; }
    cout << "Client connected!\n";

    thread t(recv_messages, client_fd);
    string msg;
    while (true) {
        cout << "> ";
        getline(cin, msg);
        if (msg == "exit") break;
        send(client_fd, msg.c_str(), msg.size(), 0);
    }
    close(client_fd);
    close(server_fd);
    return 0;
}

int run_client() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    if (connect(sock, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect"); return 1;
    }
    cout << "Connected to server!\n";

    thread t(recv_messages, sock);
    string msg;
    while (true) {
        cout << "> ";
        getline(cin, msg);
        if (msg == "exit") break;
        send(sock, msg.c_str(), msg.size(), 0);
    }
    close(sock);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " server|client\n";
        return 1;
    }
    string mode = argv[1];
    if (mode == "server") return run_server();
    else if (mode == "client") return run_client();
    else {
        cerr << "Unknown mode. Use 'server' or 'client'.\n";
        return 1;
    }
}
