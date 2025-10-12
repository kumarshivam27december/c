// typing_music_visualizer.cpp
// A unique C++ single-file "music visualizer" based on typing rhythm
// Compile: g++ typing_music_visualizer.cpp -o typing_music_visualizer -std=c++17
// Run: ./typing_music_visualizer

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cstdlib>
#include <conio.h> // for Windows
using namespace std;
using namespace chrono;

int main() {
    cout << "=== Typing Music Visualizer ===\n";
    cout << "Type any keys... (press ESC to exit)\n\n";

    vector<int> beats;
    auto last = steady_clock::now();

    while (true) {
        if (_kbhit()) { // wait for key
            char c = _getch();
            if (c == 27) break; // ESC key to exit

            auto now = steady_clock::now();
            auto diff = duration_cast<milliseconds>(now - last).count();
            last = now;

            if (diff > 2000) diff = 2000; // cap idle gap
            int strength = max(1, 20 - (int)(diff / 100)); // faster typing = bigger bar
            beats.push_back(strength);
            if (beats.size() > 40) beats.erase(beats.begin());

            system("cls"); // clear terminal (Windows)
            cout << "Typing Rhythm Visualizer (ESC to exit)\n";
            cout << "--------------------------------------\n";

            // Draw beat bars
            for (int s : beats) {
                for (int i = 0; i < s; i++) cout << "#";
                cout << "\n";
            }

            cout << "\nSpeed: " << (2000 - diff) / 20 << " BPM-ish\n";
        }
        this_thread::sleep_for(10ms);
    }

    cout << "\nGoodbye! You made your own rhythm 🎵\n";
    return 0;
}
