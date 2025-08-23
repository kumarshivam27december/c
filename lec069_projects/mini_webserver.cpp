// mini_webserver.cpp
// A very simple HTTP server in one file.
// Compile: g++ mini_webserver.cpp -o mini_webserver
// Run: ./mini_webserver
// Then open http://127.0.0.1:8080 in your browser.

#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return 1; }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); return 1;
    }
    if (listen(server_fd, 5) < 0) {
        perror("listen"); return 1;
    }

    cout << "Mini Web Server running on http://127.0.0.1:8080\n";

    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd < 0) { perror("accept"); continue; }

        char buffer[1024];
        int n = recv(client_fd, buffer, sizeof(buffer)-1, 0);
        if (n > 0) {
            buffer[n] = '\0';
            cout << "Request:\n" << buffer << "\n";
        }

        string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n\r\n"
            "<html><body><h1>Hello from Mini C++ Web Server!</h1>"
            "<p>This is a simple networking project in a single file.</p>"
            "</body></html>";

        send(client_fd, response.c_str(), response.size(), 0);
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
