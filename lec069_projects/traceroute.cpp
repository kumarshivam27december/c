// mini_traceroute.cpp
// A simple traceroute implementation in C++
// Compile: g++ mini_traceroute.cpp -o mini_traceroute
// Run (need root for raw sockets): sudo ./mini_traceroute <hostname or IP>

#include <iostream>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <cstring>
#include <netdb.h>
#include <sys/time.h>

using namespace std;

unsigned short checksum(void *b, int len) {
    unsigned short *buf = (unsigned short*)b;
    unsigned int sum=0;
    unsigned short result;

    for(sum=0; len>1; len-=2)
        sum += *buf++;
    if(len==1)
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <hostname/IP>\n";
        return 1;
    }

    // Resolve hostname
    hostent *host = gethostbyname(argv[1]);
    if (!host) {
        cerr << "Unknown host " << argv[1] << endl;
        return 1;
    }
    string target_ip = inet_ntoa(*(struct in_addr*)host->h_addr);
    cout << "Tracing route to " << argv[1] << " [" << target_ip << "]...\n";

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) { perror("socket"); return 1; }

    sockaddr_in dest{};
    dest.sin_family = AF_INET;
    dest.sin_addr = *(in_addr*)host->h_addr;

    const int MAX_HOPS = 30;
    for (int ttl = 1; ttl <= MAX_HOPS; ttl++) {
        // Set TTL
        setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));

        // ICMP Echo request
        char packet[64];
        memset(packet, 0, sizeof(packet));
        icmphdr *icmp = (icmphdr*)packet;
        icmp->type = ICMP_ECHO;
        icmp->un.echo.id = getpid();
        icmp->un.echo.sequence = ttl;
        icmp->checksum = checksum(packet, sizeof(packet));

        timeval start, end;
        gettimeofday(&start, nullptr);

        sendto(sock, packet, sizeof(packet), 0, (sockaddr*)&dest, sizeof(dest));

        // Receive reply
        sockaddr_in reply_addr{};
        socklen_t addrlen = sizeof(reply_addr);
        char buffer[1024];
        int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (sockaddr*)&reply_addr, &addrlen);

        gettimeofday(&end, nullptr);

        double elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
        elapsed += (end.tv_usec - start.tv_usec) / 1000.0;

        if (bytes > 0) {
            cout << ttl << "  " << inet_ntoa(reply_addr.sin_addr) 
                 << "  " << elapsed << " ms" << endl;
            if (reply_addr.sin_addr.s_addr == dest.sin_addr.s_addr) {
                cout << "Reached destination!\n";
                break;
            }
        } else {
            cout << ttl << "  *\n";
        }
    }

    close(sock);
    return 0;
}
