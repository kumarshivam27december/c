// file_transfer.cpp
// Minimal TCP file transfer (client/server) in one file.
// Compile: g++ file_transfer.cpp -o file_transfer
//
// Usage:
//   ./file_transfer server   -> runs server (listens on 9090)
//   ./file_transfer client   -> runs client, sends "send.txt" to server

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

void run_server() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9090);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); close(server_fd); return;
    }
    listen(server_fd, 1);
    cout << "Server listening on port 9090...\n";

    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0) { perror("accept"); close(server_fd); return; }
    cout << "Client connected.\n";

    ofstream out("received.txt", ios::binary);
    char buf[1024];
    int n;
    while ((n = recv(client_fd, buf, sizeof(buf), 0)) > 0) {
        out.write(buf, n);
    }
    cout << "File received -> saved as 'received.txt'\n";

    out.close();
    close(client_fd);
    close(server_fd);
}

void run_client() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9090);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    if (connect(sock, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect"); close(sock); return;
    }
    cout << "Connected to server.\n";

    ifstream in("send.txt", ios::binary);
    if (!in) { cerr << "send.txt not found!\n"; close(sock); return; }

    char buf[1024];
    while (in.read(buf, sizeof(buf)) || in.gcount() > 0) {
        send(sock, buf, in.gcount(), 0);
    }
    cout << "File sent.\n";

    in.close();
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
    else cerr << "Unknown mode: use server|client\n";
    return 0;
}
