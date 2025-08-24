// udp_pingpong.cpp
// Simple UDP Ping-Pong server & client in one file.
// Compile: g++ udp_pingpong.cpp -o udp_pingpong
//
// Usage:
//   ./udp_pingpong server   -> starts UDP server on port 9091
//   ./udp_pingpong client   -> sends "ping" to server and waits for "pong"

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

void run_server() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) { perror("socket"); return; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9091);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); close(sock); return;
    }
    cout << "UDP Server listening on port 9091...\n";

    char buf[1024];
    sockaddr_in client_addr{};
    socklen_t len = sizeof(client_addr);

    while (true) {
        int n = recvfrom(sock, buf, sizeof(buf)-1, 0,
                         (sockaddr*)&client_addr, &len);
        if (n > 0) {
            buf[n] = '\0';
            cout << "Received: " << buf << "\n";
            string reply = "pong";
            sendto(sock, reply.c_str(), reply.size(), 0,
                   (sockaddr*)&client_addr, len);
        }
    }
    close(sock);
}

void run_client() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) { perror("socket"); return; }

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(9091);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    string msg = "ping";
    sendto(sock, msg.c_str(), msg.size(), 0,
           (sockaddr*)&server, sizeof(server));
    cout << "Sent: " << msg << "\n";

    char buf[1024];
    socklen_t len = sizeof(server);
    int n = recvfrom(sock, buf, sizeof(buf)-1, 0,
                     (sockaddr*)&server, &len);
    if (n > 0) {
        buf[n] = '\0';
        cout << "Received from server: " << buf << "\n";
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
    else cerr << "Unknown mode. Use 'server' or 'client'.\n";
    return 0;
}
