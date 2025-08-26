// udp_broadcast_chat.cpp
// Simple UDP broadcast chat in one file.
// Everyone running this program on the same LAN + port can chat.
// Compile: g++ udp_broadcast_chat.cpp -o udp_broadcast_chat -pthread
// Run: ./udp_broadcast_chat

#include <iostream>
#include <thread>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

const int PORT = 9092;
const char* BROADCAST_IP = "255.255.255.255";

void receive_messages(int sock) {
    char buf[1024];
    sockaddr_in sender{};
    socklen_t len = sizeof(sender);

    while (true) {
        int n = recvfrom(sock, buf, sizeof(buf)-1, 0, (sockaddr*)&sender, &len);
        if (n > 0) {
            buf[n] = '\0';
            cout << "\n[Msg] " << buf << "\n> " << flush;
        }
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    // Enable broadcast
    int yes = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(yes)) < 0) {
        perror("setsockopt"); close(sock); return 1;
    }

    // Bind to receive messages
    sockaddr_in recv_addr{};
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_port = htons(PORT);
    recv_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (sockaddr*)&recv_addr, sizeof(recv_addr)) < 0) {
        perror("bind"); close(sock); return 1;
    }

    // Prepare broadcast address
    sockaddr_in bcast{};
    bcast.sin_family = AF_INET;
    bcast.sin_port = htons(PORT);
    inet_pton(AF_INET, BROADCAST_IP, &bcast.sin_addr);

    cout << "UDP Broadcast Chat running on port " << PORT << "\n";
    cout << "Type messages and press Enter. (Ctrl+C to quit)\n";

    // Start receive thread
    thread t(receive_messages, sock);

    // Send messages
    string msg;
    while (true) {
        cout << "> ";
        getline(cin, msg);
        if (msg == "exit") break;
        sendto(sock, msg.c_str(), msg.size(), 0, (sockaddr*)&bcast, sizeof(bcast));
    }

    close(sock);
    return 0;
}

