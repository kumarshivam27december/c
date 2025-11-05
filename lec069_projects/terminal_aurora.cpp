// terminal_aurora.cpp
// A living ASCII aurora effect in your terminal
// Compile: g++ terminal_aurora.cpp -o terminal_aurora -std=c++17
// Run: ./terminal_aurora
// Exit: Ctrl + C

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

#ifdef _WIN32
#include <windows.h>
#endif

// Helper to set ANSI colors (works on Linux/macOS; on Windows, enable VT100 mode)
void enableANSI() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING
    SetConsoleMode(hOut, dwMode);
#endif
}

// Generate a color gradient ANSI code
string colorGradient(int x, int y, int frame) {
    int r = (int)(sin((x + frame) * 0.05) * 127 + 128);
    int g = (int)(sin((y + frame) * 0.07 + 2) * 127 + 128);
    int b = (int)(sin((x + y + frame) * 0.04 + 4) * 127 + 128);
    return "\033[48;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m ";
}

int main() {
    enableANSI();

    const int width = 80;
    const int height = 24;

    cout << "\033[2J"; // clear
    cout << "\033[?25l"; // hide cursor

    for (int frame = 0;; frame++) {
        cout << "\033[H"; // move cursor to top-left
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cout << colorGradient(x, y, frame);
            }
            cout << "\033[0m\n";
        }
        this_thread::sleep_for(chrono::milliseconds(80));
    }

    cout << "\033[?25h"; // show cursor again
    return 0;
}
