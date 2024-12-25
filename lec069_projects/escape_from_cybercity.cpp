#include <iostream>
#include <string>

using namespace std;

// Function to print a divider
void printDivider() {
    cout << "\n========================================\n";
}

// Introduction to the game
void intro() {
    printDivider();
    cout << "The year is 2147. CyberCity, a neon-lit metropolis, is controlled by a tyrannical AI called Overmind.\n";
    cout << "You are a skilled hacker who has stolen critical data that can shut Overmind down.\n";
    cout << "The AI's drones are hunting you, and your mission is to escape CyberCity alive.\n";
    printDivider();
    cout << "1. Take the subway tunnels\n";
    cout << "2. Hijack a hover car\n";
    cout << "3. Blend in with the crowd in Neon Square\n";
}

// Subway tunnel scenario
void subwayTunnels() {
    printDivider();
    cout << "You sprint into the dark subway tunnels, hearing the hum of drones behind you.\n";
    cout << "As you move deeper, you find a maintenance hatch and a speeding train approaching.\n";
    cout << "1. Jump onto the train\n";
    cout << "2. Enter the maintenance hatch\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You jump onto the train, evading the drones for now.\n";
        cout << "But the train leads to a checkpoint where you're captured.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You enter the hatch and navigate the city's old sewers.\n";
        cout << "After hours, you find a hidden resistance base and hand over the data.\n";
        cout << "Congratulations! You've successfully escaped CyberCity.\n";
    }
}

// Hover car scenario
void hoverCar() {
    printDivider();
    cout << "You hotwire a hover car and zoom into the neon-lit streets of CyberCity.\n";
    cout << "Drones swarm around you, trying to disable the vehicle.\n";
    cout << "1. Fly into a narrow alley to lose them\n";
    cout << "2. Engage the car's weapon systems and fight back\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You maneuver skillfully into the alley, but the car gets stuck.\n";
        cout << "The drones catch you, and you're captured.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You activate the car's weapons and shoot down the drones.\n";
        cout << "With the path clear, you escape CyberCity and deliver the stolen data to the resistance.\n";
        cout << "Congratulations! You've successfully escaped CyberCity.\n";
    }
}

// Neon Square scenario
void neonSquare() {
    printDivider();
    cout << "You blend into the crowd in Neon Square, surrounded by holograms and vendors.\n";
    cout << "A resistance contact is supposed to meet you here.\n";
    cout << "1. Wait patiently and blend in\n";
    cout << "2. Try to contact the resistance using your communicator\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You wait too long, and the drones locate you in the crowd.\n";
        cout << "You're captured by Overmind's enforcers.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You contact the resistance and they guide you to a safe house nearby.\n";
        cout << "From there, they extract you from CyberCity, and the stolen data helps shut down Overmind.\n";
        cout << "Congratulations! You've successfully escaped CyberCity.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'Escape from CyberCity'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        subwayTunnels();
    } else if (choice == 2) {
        hoverCar();
    } else if (choice == 3) {
        neonSquare();
    } else {
        cout << "Invalid choice. Overmind's drones find and capture you.\n";
        cout << "Game Over.\n";
    }

    return 0;
}
