#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks[3]; // marks in 3 subjects
    float average;
    char grade;

    void calculateGrade() {
        average = (marks[0] + marks[1] + marks[2]) / 3.0;
        if (average >= 90) grade = 'A';
        else if (average >= 75) grade = 'B';
        else if (average >= 60) grade = 'C';
        else if (average >= 40) grade = 'D';
        else grade = 'F';
    }

public:
    void inputDetails() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter marks in 3 subjects:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
        cin.ignore(); // clear input buffer
        calculateGrade();
        cout << "Student data saved.\n";
    }

    void displayReport() {
        cout << "\n--- Report Card ---\n";
        cout << "Name      : " << name << "\n";
        cout << "Roll No.  : " << rollNo << "\n";
        for (int i = 0; i < 3; ++i)
            cout << "Marks " << i + 1 << ": " << marks[i] << "\n";
        cout << "Average   : " << average << "\n";
        cout << "Grade     : " << grade << "\n";
    }
};

int main() {
    Student student;
    int choice;

    while (true) {
        cout << "\n--- Student Report Card System ---\n";
        cout << "1. Enter Student Data\n2. Show Report Card\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1: student.inputDetails(); break;
            case 2: student.displayReport(); break;
            case 3: cout << "Exiting..."; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
