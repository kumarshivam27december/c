// mini_ftp.cpp
// Simple File Transfer over TCP (single file project)
// Compile: g++ mini_ftp.cpp -o mini_ftp
// Run server: ./mini_ftp server <port>
// Run client: ./mini_ftp client <ip> <port> <upload/download> <filename>

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

void handle_client(int client_fd) {
    char mode[16], filename[256];
    recv(client_fd, mode, sizeof(mode), 0);
    recv(client_fd, filename, sizeof(filename), 0);

    if (string(mode) == "upload") {
        ofstream fout(filename, ios::binary);
        char buffer[1024];
        ssize_t n;
        while ((n = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
            fout.write(buffer, n);
        }
        fout.close();
        cout << "File '" << filename << "' uploaded successfully.\n";
    } else if (string(mode) == "download") {
        ifstream fin(filename, ios::binary);
        if (!fin) {
            cerr << "File not found: " << filename << endl;
            close(client_fd);
            return;
        }
        char buffer[1024];
        while (fin.read(buffer, sizeof(buffer)) || fin.gcount()) {
            send(client_fd, buffer, fin.gcount(), 0);
        }
        fin.close();
        cout << "File '" << filename << "' sent successfully.\n";
    }
    close(client_fd);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage:\n"
             << "  Server: ./mini_ftp server <port>\n"
             << "  Client: ./mini_ftp client <ip> <port> <upload/download> <filename>\n";
        return 1;
    }

    string mode = argv[1];
    int port = stoi(argv[(mode == "server") ? 2 : 3]);

    if (mode == "server") {
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);

        bind(server_fd, (sockaddr*)&addr, sizeof(addr));
        listen(server_fd, 5);
        cout << "File server running on port " << port << endl;

        while (true) {
            int client_fd = accept(server_fd, nullptr, nullptr);
            thread(handle_client, client_fd).detach();
        }
        close(server_fd);
    } 
    else if (mode == "client") {
        if (argc < 6) {
            cerr << "Client Usage: ./mini_ftp client <ip> <port> <upload/download> <filename>\n";
            return 1;
        }

        string ip = argv[2];
        string action = argv[4];
        string filename = argv[5];

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serv{};
        serv.sin_family = AF_INET;
        serv.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &serv.sin_addr);

        if (connect(sock, (sockaddr*)&serv, sizeof(serv)) < 0) {
            perror("connect");
            return 1;
        }

        // Send mode + filename
        send(sock, action.c_str(), action.size()+1, 0);
        send(sock, filename.c_str(), filename.size()+1, 0);

        if (action == "upload") {
            ifstream fin(filename, ios::binary);
            if (!fin) { cerr << "File not found!\n"; return 1; }
            char buffer[1024];
            while (fin.read(buffer, sizeof(buffer)) || fin.gcount()) {
                send(sock, buffer, fin.gcount(), 0);
            }
            fin.close();
            cout << "File uploaded.\n";
        } else if (action == "download") {
            ofstream fout(filename, ios::binary);
            char buffer[1024];
            ssize_t n;
            while ((n = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
                fout.write(buffer, n);
            }
            fout.close();
            cout << "File downloaded.\n";
        }
        close(sock);
    }

    return 0;
}
