// p2p_file_transfer.cpp
// Simple peer-to-peer file transfer in C++ (single file).
// Compile: g++ p2p_file_transfer.cpp -o p2p_file_transfer
//
// Usage:
//   ./p2p_file_transfer server <port> <file_to_share>
//   ./p2p_file_transfer client <ip> <port> <save_as>
//
// Example:
//   ./p2p_file_transfer server 5000 myfile.txt
//   ./p2p_file_transfer client 127.0.0.1 5000 copy.txt

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

void run_server(int port, const string& filename) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) { perror("bind"); return; }
    listen(server_fd, 1);

    cout << "Server ready. Sharing file: " << filename << " on port " << port << endl;

    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0) { perror("accept"); return; }

    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "File not found!\n";
        close(client_fd);
        return;
    }

    char buffer[1024];
    while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
        send(client_fd, buffer, file.gcount(), 0);
    }

    cout << "File sent successfully.\n";
    file.close();
    close(client_fd);
    close(server_fd);
}

void run_client(const string& ip, int port, const string& save_as) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return; }

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &server.sin_addr);

    if (connect(sock, (sockaddr*)&server, sizeof(server)) < 0) { perror("connect"); return; }

    ofstream out(save_as, ios::binary);
    char buffer[1024];
    int n;
    while ((n = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        out.write(buffer, n);
    }

    cout << "File received and saved as " << save_as << endl;
    out.close();
    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage:\n"
             << "  Server: " << argv[0] << " server <port> <file>\n"
             << "  Client: " << argv[0] << " client <ip> <port> <save_as>\n";
        return 1;
    }

    string mode = argv[1];
    if (mode == "server" && argc == 4) {
        run_server(stoi(argv[2]), argv[3]);
    } else if (mode == "client" && argc == 5) {
        run_client(argv[2], stoi(argv[3]), argv[4]);
    } else {
        cerr << "Invalid usage.\n";
        return 1;
    }
    return 0;
}
