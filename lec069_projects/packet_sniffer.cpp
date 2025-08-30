// packet_sniffer.cpp
// A simple packet sniffer using raw sockets
// Compile: g++ packet_sniffer.cpp -o packet_sniffer
// Run (need root): sudo ./packet_sniffer

#include <iostream>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    cout << "Packet sniffer started... (Press Ctrl+C to stop)\n";

    char buffer[65536];
    while (true) {
        ssize_t data_size = recv(sock, buffer, sizeof(buffer), 0);
        if (data_size < 0) {
            perror("recv");
            break;
        }

        struct iphdr *ip = (struct iphdr*)buffer;
        struct tcphdr *tcp = (struct tcphdr*)(buffer + ip->ihl*4);

        struct in_addr src, dst;
        src.s_addr = ip->saddr;
        dst.s_addr = ip->daddr;

        cout << "TCP Packet: "
             << inet_ntoa(src) << ":" << ntohs(tcp->source)
             << " -> " 
             << inet_ntoa(dst) << ":" << ntohs(tcp->dest)
             << endl;
    }

    close(sock);
    return 0;
}
