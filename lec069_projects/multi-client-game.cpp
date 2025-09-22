// net_maze_game.cpp
// Multiplayer Maze Explorer over TCP
// Compile: g++ net_maze_game.cpp -o net_maze_game -pthread
// Run server: ./net_maze_game server <port>
// Run client: ./net_maze_game client <ip> <port>

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

const int H = 10, W = 20;
char maze[H][W+1] = {
    "###################",
    "#.....#...........#",
    "#.###.#.#####.###.#",
    "#.#...#.....#.#...#",
    "#.#.#####.#.#.#.#.#",
    "#.#.......#...#.#.#",
    "#.#######.#####.#.#",
    "#.......#.......#.#",
    "#.#####.#######.#.#",
    "###################"
};

struct Player {
    int fd;
    int id;
    int x, y;
};
vector<Player> players;
mutex playersMutex;

void sendMazeToAll() {
    lock_guard<mutex> lock(playersMutex);
    string msg = "\n=== Maze ===\n";
    // copy maze
    vector<string> display(H);
    for (int i=0; i<H; i++) display[i] = maze[i];
    // put players
    for (auto &p : players) {
        if (p.x>=0 && p.x<H && p.y>=0 && p.y<W)
            display[p.x][p.y] = '0' + p.id; // P1 -> '1', etc.
    }
    for (int i=0; i<H; i++) msg += display[i] + "\n";
    msg += "Use W/A/S/D to move\n";

    for (auto &p : players) {
        send(p.fd, msg.c_str(), msg.size(), 0);
    }
}

void handleClient(Player player) {
    char buf[16];
    while (true) {
        int n = recv(player.fd, buf, 15, 0);
        if (n <= 0) break;
        buf[n] = '\0';
        char c = buf[0];
        int nx = player.x, ny = player.y;
        if (c=='w') nx--;
        else if (c=='s') nx++;
        else if (c=='a') ny--;
        else if (c=='d') ny++;

        if (maze[nx][ny] != '#') {
            lock_guard<mutex> lock(playersMutex);
            for (auto &p : players) {
                if (p.id == player.id) {
                    p.x = nx; p.y = ny;
                }
            }
        }
        sendMazeToAll();
    }
    close(player.fd);
    {
        lock_guard<mutex> lock(playersMutex);
        players.erase(remove_if(players.begin(), players.end(),
                                [&](auto &p){return p.id==player.id;}), players.end());
    }
    sendMazeToAll();
}

void serverMode(int port) {
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{}; addr.sin_family=AF_INET; addr.sin_port=htons(port); addr.sin_addr.s_addr=INADDR_ANY;
    bind(srv, (sockaddr*)&addr, sizeof(addr));
    listen(srv, 5);

    cout << "Maze server running on port " << port << "...\n";

    int idCounter = 1;
    while (true) {
        int client_fd = accept(srv, nullptr, nullptr);
        Player p{client_fd, idCounter++, 1, 1}; // spawn at (1,1)
        {
            lock_guard<mutex> lock(playersMutex);
            players.push_back(p);
        }
        thread(handleClient, p).detach();
        sendMazeToAll();
    }
}

void clientMode(string ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serv{}; serv.sin_family=AF_INET; serv.sin_port=htons(port);
    inet_pton(AF_INET, ip.c_str(), &serv.sin_addr);
    if (connect(sock, (sockaddr*)&serv, sizeof(serv)) < 0) {
        perror("connect");
        return;
    }

    thread([&]() {
        char buf[2048];
        while (true) {
            int n = recv(sock, buf, 2047, 0);
            if (n <= 0) break;
            buf[n] = '\0';
            cout << buf << endl;
        }
    }).detach();

    string input;
    while (getline(cin, input)) {
        if (!input.empty()) send(sock, input.c_str(), 1, 0);
    }
    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage:\n  Server: ./net_maze_game server <port>\n"
             << "  Client: ./net_maze_game client <ip> <port>\n";
        return 1;
    }
    string mode = argv[1];
    if (mode == "server") serverMode(stoi(argv[2]));
    else clientMode(argv[2], stoi(argv[3]));
    return 0;
}
