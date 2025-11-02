// echomind.cpp
// EchoMind — A terminal that remembers your words
// Compile: g++ echomind.cpp -o echomind -std=c++17
// Run: ./echomind

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

string distort(string s) {
    // Randomly change, delete, or shuffle letters to create "memory echoes"
    for (char &c : s) {
        if (rand()%15 == 0) c = (rand()%2) ? toupper(c) : tolower(c);
        if (rand()%25 == 0) c = '.';
    }
    if (s.size() > 5 && rand()%3 == 0)
        random_shuffle(s.begin(), s.end());
    return s;
}

int main() {
    srand(time(0));
    vector<string> memory;
    string input;

    cout << "=== EchoMind ===\n";
    cout << "Type something... (type 'exit' to quit)\n\n";

    int tick = 0;
    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "exit") break;
        if (input.empty()) continue;

        memory.push_back(input);

        // Sometimes respond immediately
        if (rand()%3 == 0) {
            string echo = distort(memory[rand()%memory.size()]);
            cout << "\nEchoMind whispers: \"" << echo << "\"\n\n";
        }

        // Wait a bit and maybe reply randomly
        for (int i=0; i<3; i++) {
            this_thread::sleep_for(chrono::milliseconds(500));
            if (rand()%8 == 0 && !memory.empty()) {
                string echo = distort(memory[rand()%memory.size()]);
                cout << "\n... " << echo << "\n";
            }
        }

        tick++;
        // As time passes, it “remembers” more
        if (tick % 5 == 0 && !memory.empty()) {
            cout << "\nEchoMind recalls something you said long ago:\n";
            cout << "» \"" << distort(memory[rand()%memory.size()]) << "\"\n\n";
        }
    }

    cout << "\nEchoMind fades into silence.\n";
    return 0;
}
