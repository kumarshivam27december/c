// mini_dns_resolver.cpp
// A tiny DNS resolver in C++ (single file).
// Compile: g++ mini_dns_resolver.cpp -o mini_dns_resolver
// Run: ./mini_dns_resolver example.com

#include <iostream>
#include <string>
#include <vector>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>

using namespace std;

struct DNS_HEADER {
    unsigned short id;
    unsigned short flags;
    unsigned short q_count;
    unsigned short ans_count;
    unsigned short auth_count;
    unsigned short add_count;
};

struct QUESTION {
    unsigned short qtype;
    unsigned short qclass;
};

void build_dns_query(char *buf, const string &hostname, int &len) {
    DNS_HEADER *dns = (DNS_HEADER*)buf;
    dns->id = htons(getpid());
    dns->flags = htons(0x0100); // recursion desired
    dns->q_count = htons(1);
    dns->ans_count = 0;
    dns->auth_count = 0;
    dns->add_count = 0;

    char *qname = buf + sizeof(DNS_HEADER);
    string host = hostname + ".";
    size_t pos = 0, last = 0;
    while ((pos = host.find('.', last)) != string::npos) {
        *qname++ = pos - last;
        memcpy(qname, host.c_str() + last, pos - last);
        qname += pos - last;
        last = pos + 1;
    }
    *qname++ = 0;

    QUESTION *qinfo = (QUESTION*)qname;
    qinfo->qtype = htons(1);   // A record
    qinfo->qclass = htons(1);  // IN (Internet)

    len = (char*)(qinfo + 1) - buf;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <hostname>\n";
        return 1;
    }

    string hostname = argv[1];
    char buf[65536];
    int query_len;

    build_dns_query(buf, hostname, query_len);

    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) { perror("socket"); return 1; }

    sockaddr_in dest{};
    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    inet_pton(AF_INET, "8.8.8.8", &dest.sin_addr); // Google DNS

    sendto(sock, buf, query_len, 0, (sockaddr*)&dest, sizeof(dest));

    socklen_t len = sizeof(dest);
    int n = recvfrom(sock, buf, sizeof(buf), 0, (sockaddr*)&dest, &len);
    if (n < 0) { perror("recvfrom"); return 1; }

    DNS_HEADER *dns = (DNS_HEADER*)buf;
    char *reader = buf + query_len;

    // Skip question section
    for (int i = 0; i < ntohs(dns->q_count); i++) {
        while (*reader != 0) reader++;
        reader += 5;
    }

    // Parse answers
    for (int i = 0; i < ntohs(dns->ans_count); i++) {
        reader += 2; // name pointer
        unsigned short type = ntohs(*(unsigned short*)reader); reader += 2;
        reader += 2; // class
        reader += 4; // ttl
        unsigned short data_len = ntohs(*(unsigned short*)reader); reader += 2;

        if (type == 1 && data_len == 4) { // IPv4
            in_addr addr;
            memcpy(&addr, reader, 4);
            cout << hostname << " -> " << inet_ntoa(addr) << endl;
        }
        reader += data_len;
    }

    close(sock);
    return 0;
}
