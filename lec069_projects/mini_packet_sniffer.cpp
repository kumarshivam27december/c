// mini_sniffer.cpp
// Minimal packet sniffer in C++ (Linux only, needs root)
// Compile: g++ mini_sniffer.cpp -o mini_sniffer
// Run: sudo ./mini_sniffer

#include <iostream>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    char buffer[65536];
    sockaddr_in src_addr{};
    socklen_t addr_len = sizeof(src_addr);

    cout << "Starting packet sniffer... (Ctrl+C to stop)\n";

    while (true) {
        ssize_t data_size = recvfrom(sock, buffer, sizeof(buffer), 0,
                                     (sockaddr*)&src_addr, &addr_len);
        if (data_size < 0) {
            perror("recvfrom");
            return 1;
        }

        iphdr *ip = (iphdr*)buffer;
        sockaddr_in src, dest;
        src.sin_addr.s_addr = ip->saddr;
        dest.sin_addr.s_addr = ip->daddr;

        cout << "IP Packet: " << inet_ntoa(src.sin_addr)
             << " -> " << inet_ntoa(dest.sin_addr)
             << " | Protocol: " << (int)ip->protocol << endl;

        if (ip->protocol == IPPROTO_TCP) {
            tcphdr *tcp = (tcphdr*)(buffer + ip->ihl*4);
            cout << "   TCP " << ntohs(tcp->source) << " -> " << ntohs(tcp->dest) << endl;
        } 
        else if (ip->protocol == IPPROTO_UDP) {
            udphdr *udp = (udphdr*)(buffer + ip->ihl*4);
            cout << "   UDP " << ntohs(udp->source) << " -> " << ntohs(udp->dest) << endl;
        }
    }

    close(sock);
    return 0;
}
