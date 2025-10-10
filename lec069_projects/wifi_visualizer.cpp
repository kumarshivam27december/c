// wifi_visualizer.cpp
// Live Wi-Fi Signal Strength Visualizer (cross-platform, single file)
// Linux: reads /proc/net/wireless
// Windows: runs "netsh wlan show interfaces"
// Compile: g++ wifi_visualizer.cpp -o wifi_visualizer
// Run: ./wifi_visualizer

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#ifdef _WIN32
string getSignal() {
    FILE* pipe = _popen("netsh wlan show interfaces", "r");
    if (!pipe) return "";
    char buffer[256];
    string result;
    while (fgets(buffer, sizeof(buffer), pipe)) result += buffer;
    _pclose(pipe);

    size_t pos = result.find("Signal");
    if (pos != string::npos) {
        string sub = result.substr(pos);
        size_t percent = sub.find('%');
        if (percent != string::npos) {
            string num;
            for (int i = (int)percent - 1; i >= 0 && isdigit(sub[i]); i--)
                num = sub[i] + num;
            return num;
        }
    }
    return "0";
}
#else
string getSignal() {
    FILE* pipe = fopen("/proc/net/wireless", "r");
    if (!pipe) return "0";
    char line[256];
    int lineCount = 0;
    double level = 0;
    while (fgets(line, sizeof(line), pipe)) {
        lineCount++;
        if (lineCount > 2) { // skip headers
            char iface[20]; double status, quality;
            sscanf(line, "%s %*d %lf. %lf.", iface, &status, &quality);
            level = quality; break;
        }
    }
    fclose(pipe);
    if (level <= 0) return "0";
    int percent = (int)(level); // approximate
    return to_string(percent);
}
#endif

void drawBar(int percent) {
    int bars = percent / 5;
    cout << "[";
    for (int i = 0; i < 20; i++)
        cout << (i < bars ? "#" : " ");
    cout << "] " << percent << "%\n";
}

int main() {
    cout << "=== Live Wi-Fi Signal Visualizer ===\n";
    while (true) {
        string s = getSignal();
        int val = stoi(s);
        cout << "\033[2J\033[H"; // clear terminal
        cout << "Wi-Fi Signal Strength\n";
        drawBar(val);
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}
