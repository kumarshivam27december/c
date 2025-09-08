// mini_ping.cpp
// A minimal "ping" implementation in C++ (Linux only, needs root for raw sockets)
// Compile: g++ mini_ping.cpp -o mini_ping
// Run: sudo ./mini_ping 8.8.8.8

#include <iostream>
#include <chrono>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>

using namespace std;

unsigned short checksum(void *b, int len) {
    unsigned short *buf = (unsigned short*)b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: sudo " << argv[0] << " <ip>\n";
        return 1;
    }

    string target_ip = argv[1];
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) { perror("socket"); return 1; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, target_ip.c_str(), &addr.sin_addr);

    char packet[64];
    icmphdr *icmp = (icmphdr*)packet;
    memset(packet, 0, sizeof(packet));

    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->un.echo.id = getpid() & 0xFFFF;
    icmp->un.echo.sequence = 1;
    icmp->checksum = checksum(packet, sizeof(packet));

    auto start = chrono::high_resolution_clock::now();
    if (sendto(sock, packet, sizeof(packet), 0, (sockaddr*)&addr, sizeof(addr)) <= 0) {
        perror("sendto");
        return 1;
    }

    socklen_t len = sizeof(addr);
    if (recvfrom(sock, packet, sizeof(packet), 0, (sockaddr*)&addr, &len) <= 0) {
        perror("recvfrom");
        return 1;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;

    cout << "Reply from " << target_ip << " in " << elapsed.count() << " ms" << endl;

    close(sock);
    return 0;
}
