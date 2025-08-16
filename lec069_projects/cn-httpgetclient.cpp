// simple_http_client.cpp
// A minimal HTTP/1.1 GET client in a single C++ file.
// Demonstrates: DNS resolution (getaddrinfo), TCP connect, send/recv with timeouts.
// Works on Linux/macOS. (No TLS/HTTPS — plain HTTP only.)

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cerrno>
#include <chrono>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

static void die(const std::string& msg) {
    std::cerr << "[error] " << msg << " (errno=" << errno << " : " << std::strerror(errno) << ")\n";
    std::exit(EXIT_FAILURE);
}

static int connect_with_timeout(const struct addrinfo* ai, int timeout_ms) {
    int sock = ::socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    if (sock < 0) return -1;

    // Set send/recv timeouts so we don’t hang forever.
    timeval tv;
    tv.tv_sec = timeout_ms / 1000;
    tv.tv_usec = (timeout_ms % 1000) * 1000;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) { ::close(sock); return -1; }
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) < 0) { ::close(sock); return -1; }

    if (::connect(sock, ai->ai_addr, ai->ai_addrlen) == 0) {
        return sock; // connected
    }
    ::close(sock);
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: " << argv[0] << " <host> <path> [port]\n"
                  << "Example: " << argv[0] << " example.com /\n";
        return 1;
    }

    std::string host = argv[1];
    std::string path = argv[2];
    std::string port = (argc == 4) ? argv[3] : "80";

    // Resolve host name.
    addrinfo hints{};
    hints.ai_family   = AF_UNSPEC;     // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;   // TCP
    hints.ai_flags    = AI_ADDRCONFIG; // Prefer address families that are configured

    addrinfo* res = nullptr;
    int rc = ::getaddrinfo(host.c_str(), port.c_str(), &hints, &res);
    if (rc != 0) {
        std::cerr << "[error] getaddrinfo: " << gai_strerror(rc) << "\n";
        return 2;
    }

    // Try addresses until one connects.
    const int TIMEOUT_MS = 5000;
    int sock = -1;
    for (addrinfo* ai = res; ai != nullptr; ai = ai->ai_next) {
        sock = connect_with_timeout(ai, TIMEOUT_MS);
        if (sock >= 0) break;
    }
    if (sock < 0) {
        std::cerr << "[error] Unable to connect to " << host << ":" << port << "\n";
        ::freeaddrinfo(res);
        return 3;
    }

    // Build minimal HTTP/1.1 GET request.
    std::string request;
    request += "GET " + (path.empty() ? std::string("/") : path) + " HTTP/1.1\r\n";
    request += "Host: " + host + "\r\n";
    request += "User-Agent: simple-http-client/1.0\r\n";
    request += "Accept: */*\r\n";
    request += "Connection: close\r\n";
    request += "\r\n";

    // Send request.
    size_t sent = 0;
    while (sent < request.size()) {
        ssize_t n = ::send(sock, request.data() + sent, request.size() - sent, 0);
        if (n < 0) {
            die("send failed");
        }
        sent += static_cast<size_t>(n);
    }

    // Receive response and print to stdout.
    std::vector<char> buf(8192);
    for (;;) {
        ssize_t n = ::recv(sock, buf.data(), buf.size(), 0);
        if (n > 0) {
            std::cout.write(buf.data(), n);
        } else if (n == 0) {
            break; // connection closed
        } else {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                std::cerr << "\n[warn] recv timeout reached.\n";
                break;
            }
            die("recv failed");
        }
    }

    ::close(sock);
    ::freeaddrinfo(res);
    return 0;
}
