// mini_chat.cpp
// Simple TCP Chat (can run as server or client)
// Compile: g++ mini_chat.cpp -o mini_chat
// Run as server: ./mini_chat server <port>
// Run as client: ./mini_chat client <ip> <port>

#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

void handle_recv(int sock) {
    char buffer[1024];
    while (true) {
        ssize_t n = recv(sock, buffer, sizeof(buffer)-1, 0);
        if (n <= 0) break;
        buffer[n] = '\0';
        cout << "\n[Msg] " << buffer << "\n> " << flush;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage:\n  Server: ./mini_chat server <port>\n  Client: ./mini_chat client <ip> <port>\n";
        return 1;
    }

    string mode = argv[1];
    int port = stoi(argv[(mode == "server") ? 2 : 3]);

    if (mode == "server") {
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);

        bind(server_fd, (sockaddr*)&addr, sizeof(addr));
        listen(server_fd, 5);
        cout << "Chat server running on port " << port << endl;

        int client_fd = accept(server_fd, nullptr, nullptr);
        cout << "Client connected!\n";

        thread t(handle_recv, client_fd);
        string msg;
        while (getline(cin, msg)) send(client_fd, msg.c_str(), msg.size(), 0);
        t.join();
        close(client_fd);
        close(server_fd);
    } 
    else if (mode == "client") {
        string ip = argv[2];
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serv{};
        serv.sin_family = AF_INET;
        serv.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &serv.sin_addr);

        if (connect(sock, (sockaddr*)&serv, sizeof(serv)) < 0) {
            perror("connect");
            return 1;
        }

        cout << "Connected to chat!\n";
        thread t(handle_recv, sock);
        string msg;
        while (getline(cin, msg)) send(sock, msg.c_str(), msg.size(), 0);
        t.join();
        close(sock);
    }

    return 0;
}
