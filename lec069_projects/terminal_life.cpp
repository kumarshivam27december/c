// terminal_life.cpp
// A single-file evolving ASCII creature simulator
// Compile: g++ terminal_life.cpp -o terminal_life -std=c++17
// Run: ./terminal_life

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h> // for _kbhit() and _getch() on Windows
using namespace std;

struct Creature {
    int energy = 50;
    int mood = 50;
    string face = "(·_·)";
    int age = 0;
};

void drawCreature(const Creature& c) {
    cout << "\033[2J\033[H"; // clear screen
    cout << "=== Terminal Life ===\n\n";
    cout << "  " << c.face << "\n";
    cout << "  Energy: " << c.energy << "   Mood: " << c.mood << "   Age: " << c.age << "\n\n";

    if (c.mood > 70) cout << "It hums happily.\n";
    else if (c.mood < 30) cout << "It looks sad...\n";
    else cout << "It seems calm.\n";

    cout << "\nActions: [F]eed  [T]alk  [Q]uit\n";
}

void updateCreature(Creature& c) {
    // natural changes
    c.energy -= 1;
    if (c.energy < 0) c.energy = 0;
    if (c.energy < 20) c.mood -= 2;
    if (c.energy > 70) c.mood += 1;
    if (c.mood > 100) c.mood = 100;
    if (c.mood < 0) c.mood = 0;
    c.age++;

    // change face based on mood
    if (c.mood > 70) c.face = "(^_^)";
    else if (c.mood < 30) c.face = "(T_T)";
    else c.face = "(·_·)";
}

int main() {
    srand(time(0));
    Creature pet;

    cout << "Creating life...\n";
    this_thread::sleep_for(1s);

    while (true) {
        drawCreature(pet);

        // user input check
        if (_kbhit()) {
            char c = _getch();
            c = tolower(c);
            if (c == 'q') {
                cout << "\nIt waves goodbye...\n";
                break;
            }
            else if (c == 'f') {
                pet.energy += 15;
                if (pet.energy > 100) pet.energy = 100;
                pet.mood += 5;
                cout << "\nYou fed it some code cookies 🍪\n";
                this_thread::sleep_for(500ms);
            }
            else if (c == 't') {
                vector<string> replies = {
                    "It chirps: '01001000 01101001!'",
                    "It stares curiously at you.",
                    "It says: 'The compiler is my god.'",
                    "It hums a digital tune...",
                    "It whispers: 'I think, therefore I am.'"
                };
                cout << "\n" << replies[rand()%replies.size()] << "\n";
                pet.mood += rand()%10 - 3;
                this_thread::sleep_for(1s);
            }
        }

        updateCreature(pet);
        if (pet.energy <= 0) {
            cout << "\nIt fades away into bits and bytes...\n";
            break;
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "\n--- End of Simulation ---\n";
    return 0;
}
