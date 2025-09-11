// guess_game.cpp
// Multiplayer Number Guessing Game (TCP)
// Compile: g++ guess_game.cpp -o guess_game
// Run server: ./guess_game server <port>
// Run client: ./guess_game client <ip> <port>

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int secretNumber;

void handle_client(int client_fd) {
    char buffer[1024];
    while (true) {
        ssize_t n = recv(client_fd, buffer, sizeof(buffer)-1, 0);
        if (n <= 0) break;
        buffer[n] = '\0';

        int guess = atoi(buffer);
        string response;
        if (guess > secretNumber) response = "Too High\n";
        else if (guess < secretNumber) response = "Too Low\n";
        else {
            response = "Correct! 🎉\n";
        }

        send(client_fd, response.c_str(), response.size(), 0);
    }
    close(client_fd);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage:\n  Server: ./guess_game server <port>\n  Client: ./guess_game client <ip> <port>\n";
        return 1;
    }

    string mode = argv[1];
    int port = stoi(argv[(mode == "server") ? 2 : 3]);

    if (mode == "server") {
        srand(time(0));
        secretNumber = rand() % 100 + 1;
        cout << "Secret number chosen (1-100). Waiting for players..." << endl;

        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);

        bind(server_fd, (sockaddr*)&addr, sizeof(addr));
        listen(server_fd, 5);

        while (true) {
            int client_fd = accept(server_fd, nullptr, nullptr);
            cout << "New player joined!" << endl;
            thread(handle_client, client_fd).detach();
        }
        close(server_fd);
    } 
    else if (mode == "client") {
        string ip = argv[2];
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serv{};
        serv.sin_family = AF_INET;
        serv.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &serv.sin_addr);

        if (connect(sock, (sockaddr*)&serv, sizeof(serv)) < 0) {
            perror("connect");
            return 1;
        }

        cout << "Connected! Guess a number (1-100):" << endl;
        string guess;
        char buffer[1024];
        while (getline(cin, guess)) {
            send(sock, guess.c_str(), guess.size(), 0);
            ssize_t n = recv(sock, buffer, sizeof(buffer)-1, 0);
            if (n <= 0) break;
            buffer[n] = '\0';
            cout << "Server: " << buffer;
            if (string(buffer).find("Correct") != string::npos) break;
        }
        close(sock);
    }

    return 0;
}
