// net_speed_test.cpp
// Cross-platform Network Speed Tester (Client & Server in one file)
// Compile: g++ net_speed_test.cpp -o net_speed_test -pthread
// Run server: ./net_speed_test server <port>
// Run client: ./net_speed_test client <ip> <port>

#include <iostream>
#include <thread>
#include <chrono>
#include <cstring>
#include <vector>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif
using namespace std;
using namespace chrono;

void server(int port) {
#ifdef _WIN32
    WSADATA wsa; WSAStartup(MAKEWORD(2,2), &wsa);
#endif
    int s = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{}; addr.sin_family = AF_INET; addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    bind(s, (sockaddr*)&addr, sizeof(addr));
    listen(s, 1);
    cout << "Server listening on port " << port << "...\n";
    int client = accept(s, nullptr, nullptr);

    vector<char> buffer(1024 * 1024); // 1 MB buffer
    size_t total = 0;
    auto start = steady_clock::now();

    while (true) {
        int n = recv(client, buffer.data(), buffer.size(), 0);
        if (n <= 0) break;
        total += n;
        if (total > 50 * 1024 * 1024) break; // stop at 50MB
    }
    auto end = steady_clock::now();
    double sec = duration<double>(end - start).count();
    double mbps = (total * 8.0 / 1e6) / sec;

    cout << "Received " << total / (1024 * 1024) << " MB in " << sec << " s\n";
    cout << "Speed: " << mbps << " Mbps\n";

#ifdef _WIN32
    closesocket(s); WSACleanup();
#else
    close(s);
#endif
}

void client(string ip, int port) {
#ifdef _WIN32
    WSADATA wsa; WSAStartup(MAKEWORD(2,2), &wsa);
#endif
    int s = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serv{}; serv.sin_family = AF_INET; serv.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serv.sin_addr);

    if (connect(s, (sockaddr*)&serv, sizeof(serv)) < 0) {
        cerr << "Connection failed.\n";
        return;
    }

    vector<char> buffer(1024 * 1024, 'A'); // 1 MB dummy data
    cout << "Sending 50 MB of data...\n";
    size_t total = 0;
    auto start = steady_clock::now();
    for (int i = 0; i < 50; i++) {
        int n = send(s, buffer.data(), buffer.size(), 0);
        if (n <= 0) break;
        total += n;
    }
    auto end = steady_clock::now();
    double sec = duration<double>(end - start).count();
    double mbps = (total * 8.0 / 1e6) / sec;

    cout << "Sent " << total / (1024 * 1024) << " MB in " << sec << " s\n";
    cout << "Upload Speed: " << mbps << " Mbps\n";

#ifdef _WIN32
    closesocket(s); WSACleanup();
#else
    close(s);
#endif
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage:\n";
        cout << "  Server: ./net_speed_test server <port>\n";
        cout << "  Client: ./net_speed_test client <ip> <port>\n";
        return 1;
    }

    string mode = argv[1];
    if (mode == "server") server(stoi(argv[2]));
    else if (mode == "client" && argc >= 4) client(argv[2], stoi(argv[3]));
    else cerr << "Invalid arguments.\n";
    return 0;
}
