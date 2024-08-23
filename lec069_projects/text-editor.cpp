#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void displayMenu() {
    cout << "Text Editor Menu:\n";
    cout << "1. Create New File\n";
    cout << "2. Open Existing File\n";
    cout << "3. Save File\n";
    cout << "4. Edit File\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void createNewFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error creating file!" << endl;
        return;
    }
    cout << "New file created: " << filename << endl;
}

void openFile(const string& filename, string& content) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    content.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    cout << "File opened: " << filename << endl;
}

void saveFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file) {
        cout << "Error saving file!" << endl;
        return;
    }
    file << content;
    cout << "File saved: " << filename << endl;
}

void editFile(string& content) {
    cout << "Enter new content (type 'END' on a new line to finish):" << endl;
    content.clear();
    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        content += line + "\n";
    }
}

int main() {
    string filename, content;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Ignore leftover newline character

        switch (choice) {
            case 1:
                cout << "Enter new file name: ";
                getline(cin, filename);
                createNewFile(filename);
                break;

            case 2:
                cout << "Enter file name to open: ";
                getline(cin, filename);
                openFile(filename, content);
                cout << "File content:\n" << content << endl;
                break;

            case 3:
                if (filename.empty()) {
                    cout << "No file to save. Open or create a file first." << endl;
                } else {
                    saveFile(filename, content);
                }
                break;

            case 4:
                editFile(content);
                cout << "Current content:\n" << content << endl;
                break;

            case 5:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
