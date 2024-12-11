#include <iostream>
#include <string>

using namespace std;

// Function to print a divider line for readability
void printDivider() {
    cout << "\n========================================\n";
}

// Introduction to the game
void intro() {
    printDivider();
    cout << "You are a brave warrior on a quest to find the legendary Lost Sword of Eldoria.\n";
    cout << "Your journey begins in the ancient Kingdom of Eldoria.\n";
    cout << "The sword is said to be hidden in the depths of the Forbidden Forest.\n";
    cout << "You stand at the forest's edge, ready to begin your quest.\n";
    printDivider();
    cout << "1. Enter the forest\n";
    cout << "2. Visit the nearby village to gather information\n";
}

// The village scenario
void villageScene() {
    printDivider();
    cout << "You head to the village and speak with the locals.\n";
    cout << "An old man tells you of a hidden cave where the sword might be kept.\n";
    cout << "He warns you about the cave's guardian, a fierce troll.\n";
    cout << "1. Thank the old man and go to the cave\n";
    cout << "2. Ignore the advice and enter the forest anyway\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You follow the old man's directions and find the cave.\n";
        cout << "The sound of snoring echoes from within. The troll is asleep!\n";
    } else {
        cout << "You decide to explore the forest on your own.\n";
        cout << "You quickly get lost and stumble into a pit trap.\n";
        cout << "Game Over.\n";
    }
}

// The forest scenario
void forestScene() {
    printDivider();
    cout << "You enter the dark forest. The trees seem to whisper as you pass.\n";
    cout << "Suddenly, you hear rustling in the bushes.\n";
    cout << "1. Investigate the noise\n";
    cout << "2. Ignore it and keep walking\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "A wild wolf jumps out! You draw your sword and fight.\n";
        cout << "You manage to scare the wolf away, but you're injured.\n";
    } else {
        cout << "You ignore the noise and keep walking.\n";
        cout << "A sense of unease follows you, but nothing happens.\n";
    }
}

// The cave scenario
void caveScene() {
    printDivider();
    cout << "You cautiously enter the cave. The troll is asleep by a pile of treasure.\n";
    cout << "You see the glint of the Lost Sword behind the troll.\n";
    cout << "1. Sneak past the troll and grab the sword\n";
    cout << "2. Try to fight the troll\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You tiptoe past the troll and carefully grab the sword.\n";
        cout << "As you turn to leave, the troll stirs but doesn't wake up.\n";
        cout << "You successfully escape with the Lost Sword!\n";
        cout << "Congratulations, you have completed your quest!\n";
    } else {
        cout << "You charge at the troll with a battle cry.\n";
        cout << "The troll wakes up, furious, and easily defeats you.\n";
        cout << "Game Over.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to 'Quest for the Lost Sword'!" << endl;
    intro();

    int choice;
    cin >> choice;

    if (choice == 1) {
        forestScene();
        caveScene();
    } else {
        villageScene();
        caveScene();
    }

    return 0;
}
