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
    cout << "You are a scientist who has invented a time machine. While testing it, you accidentally traveled back to the year 1850.\n";
    cout << "The timeline is fragile, and even a small mistake could lead to catastrophic consequences for the future.\n";
    cout << "Your mission is to find a way back to your time without altering history.\n";
    printDivider();
    cout << "1. Seek help from a local blacksmith\n";
    cout << "2. Attempt to repair the time machine yourself\n";
    cout << "3. Blend into the society and wait for a better opportunity\n";
}

// Path: Blacksmith
void blacksmithPath() {
    printDivider();
    cout << "You visit a local blacksmith and show him some parts of your time machine.\n";
    cout << "The blacksmith is fascinated and agrees to help, but he asks many questions about the strange technology.\n";
    cout << "1. Explain the time machine in detail\n";
    cout << "2. Keep the explanation vague and focus on repairs\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The blacksmith becomes obsessed with the technology and tries to recreate it, causing irreversible changes to history.\n";
        cout << "Game Over.\n";
    } else {
        cout << "The blacksmith helps you repair the time machine without fully understanding it.\n";
        cout << "You successfully travel back to your time.\n";
        cout << "Congratulations! You preserved the timeline.\n";
    }
}

// Path: Repairing the machine
void repairMachine() {
    printDivider();
    cout << "You decide to repair the time machine yourself. The parts are damaged, and you need replacement materials.\n";
    cout << "1. Scavenge materials from an abandoned barn nearby\n";
    cout << "2. Disassemble local tools and machinery for parts\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You find some useful materials in the barn and repair the time machine.\n";
        cout << "However, while testing it, the machine malfunctions and creates a paradox, trapping you in 1850 forever.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You carefully disassemble local tools without drawing attention. The repairs are successful.\n";
        cout << "You return to your time, ensuring no historical changes.\n";
        cout << "Congratulations! You preserved the timeline.\n";
    }
}

// Path: Blending in
void blendIn() {
    printDivider();
    cout << "You decide to blend into society and wait for a better opportunity to fix the machine.\n";
    cout << "While waiting, you meet a historian who is curious about your knowledge of future events.\n";
    cout << "1. Share vague details about future inventions\n";
    cout << "2. Pretend to be an ordinary traveler with no special knowledge\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "The historian becomes suspicious and reports you to the authorities.\n";
        cout << "You are arrested, and the time machine is confiscated.\n";
        cout << "Game Over.\n";
    } else {
        cout << "You maintain your cover and eventually find an opportunity to fix the machine.\n";
        cout << "You return to your time without altering history.\n";
        cout << "Congratulations! You preserved the timeline.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'The Time Traveler's Paradox'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        blacksmithPath();
    } else if (choice == 2) {
        repairMachine();
    } else if (choice == 3) {
        blendIn();
    } else {
        cout << "Invalid choice. Your indecision causes the timeline to unravel.\n";
        cout << "Game Over.\n";
    }

    return 0;
}

