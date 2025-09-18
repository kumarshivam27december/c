// net_latency_plot.cpp
// Unique Network Latency Visualizer (ASCII graph ping tool)
// Compile: g++ net_latency_plot.cpp -o net_latency_plot
// Run: ./net_latency_plot <ip> <port>

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: ./net_latency_plot <ip> <port>\n";
        return 1;
    }

    string ip = argv[1];
    int port = stoi(argv[2]);

    vector<int> latencies;

    for (int i = 0; i < 20; i++) { // 20 pings
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serv{};
        serv.sin_family = AF_INET;
        serv.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &serv.sin_addr);

        auto start = high_resolution_clock::now();
        int res = connect(sock, (sockaddr*)&serv, sizeof(serv));
        auto end = high_resolution_clock::now();
        close(sock);

        int ms = res == 0 ? duration_cast<milliseconds>(end - start).count() : -1;
        latencies.push_back(ms);

        // Print ASCII graph
        cout << "[" << i+1 << "] ";
        if (ms >= 0) {
            cout << ms << " ms ";
            for (int j = 0; j < ms/2 && j < 50; j++) cout << "#"; // bar graph
        } else {
            cout << "Timeout (X)";
        }
        cout << "\n";

        this_thread::sleep_for(500ms);
    }

    cout << "\n--- Latency Report ---\n";
    int sum = 0, count = 0;
    for (int ms : latencies) {
        if (ms >= 0) { sum += ms; count++; }
    }
    if (count > 0)
        cout << "Average latency: " << (sum / count) << " ms\n";
    else
        cout << "All attempts failed.\n";

    return 0;
}
