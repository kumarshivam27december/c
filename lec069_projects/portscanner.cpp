// portscanner.cpp
// A simple TCP port scanner in one file.
// Compile: g++ portscanner.cpp -o portscanner
// Usage:   ./portscanner <host> <start_port> <end_port>
//
// Example: ./portscanner 127.0.0.1 20 100

#include <iostream>
#include <string>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstring>

using namespace std;

bool is_port_open(const string& host, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return false;

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    // Convert hostname/IP string
    if (inet_pton(AF_INET, host.c_str(), &addr.sin_addr) <= 0) {
        // Try DNS lookup
        hostent* he = gethostbyname(host.c_str());
        if (!he) { close(sock); return false; }
        memcpy(&addr.sin_addr, he->h_addr, he->h_length);
    }

    // Set timeout (1s)
    timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    bool open = (connect(sock, (sockaddr*)&addr, sizeof(addr)) == 0);
    close(sock);
    return open;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <host> <start_port> <end_port>\n";
        return 1;
    }

    string host = argv[1];
    int start_port = stoi(argv[2]);
    int end_port   = stoi(argv[3]);

    cout << "Scanning host " << host << " from port "
         << start_port << " to " << end_port << "...\n";

    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(host, port)) {
            cout << "[OPEN]   Port " << port << "\n";
        } else {
            cout << "[CLOSED] Port " << port << "\n";
        }
    }
    return 0;
}
