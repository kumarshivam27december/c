// system_pulse.cpp
// A single-file live CPU usage visualizer
// Compile: g++ system_pulse.cpp -o system_pulse -std=c++17
// Run: ./system_pulse
// Exit: Ctrl+C

#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Get CPU usage from /proc/stat (Linux)
float getCPUUsage() {
#ifdef _WIN32
    // Windows fallback: random usage for demo
    return rand() % 100;
#else
    static long long lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle;
    float percent;
    FILE* file = fopen("/proc/stat", "r");
    if (!file) return 0.0;

    long long user, nice, sys, idle, iowait, irq, softirq, steal;
    fscanf(file, "cpu  %lld %lld %lld %lld %lld %lld %lld %lld",
           &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal);
    fclose(file);

    long long totalUser = user + nice;
    long long totalSys = sys + irq + softirq;
    long long totalIdle = idle + iowait;
    long long total = totalUser + totalSys + totalIdle + steal;

    static bool first = true;
    if (first) {
        first = false;
        lastTotalUser = totalUser;
        lastTotalSys = totalSys;
        lastTotalIdle = totalIdle;
        return 0.0;
    }

    long long diffUser = totalUser - lastTotalUser;
    long long diffSys = totalSys - lastTotalSys;
    long long diffIdle = totalIdle - lastTotalIdle;
    long long diffTotal = diffUser + diffSys + diffIdle;

    percent = (diffUser + diffSys) * 100.0 / diffTotal;

    lastTotalUser = totalUser;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;
    return percent;
#endif
}

int main() {
    cout << "\033[2J\033[H"; // clear terminal
    cout << "⚙️  System Pulse Monitor (Ctrl+C to stop)\n";

    while (true) {
        float usage = getCPUUsage();
        int bars = static_cast<int>(usage / 2);
        cout << "\033[H"; // move to top
        cout << "CPU Usage: " << (int)usage << "%\n";
        cout << "[";
        for (int i = 0; i < 50; ++i)
            cout << (i < bars ? "#" : " ");
        cout << "]\n";

        // Pulse animation effect
        int pulse = (bars % 10);
        cout << "Pulse: ";
        for (int i = 0; i < pulse; ++i) cout << "♥";
        cout << "\n";

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
