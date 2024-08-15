#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient {
public:
    string name;
    int age;
    string disease;
    string contact;

    Patient(string n, int a, string d, string c) : name(n), age(a), disease(d), contact(c) {}
};

class HospitalManagementSystem {
private:
    vector<Patient> patients;

public:
    void addPatient() {
        string name;
        int age;
        string disease;
        string contact;

        cout << "Enter patient name: ";
        getline(cin, name);
        cout << "Enter patient age: ";
        cin >> age;
        cin.ignore();  // Clear newline character left in the buffer
        cout << "Enter patient disease: ";
        getline(cin, disease);
        cout << "Enter patient contact: ";
        getline(cin, contact);

        patients.emplace_back(name, age, disease, contact);
        cout << "Patient added successfully!" << endl;
    }

    void displayPatients() {
        if (patients.empty()) {
            cout << "No patients to display." << endl;
            return;
        }

        cout << "Patient List:" << endl;
        for (size_t i = 0; i < patients.size(); ++i) {
            cout << "Patient " << i + 1 << ":" << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Contact: " << patients[i].contact << endl;
            cout << "----------------------" << endl;
        }
    }

    void menu() {
        int choice;
        do {
            cout << "Hospital Management System Menu" << endl;
            cout << "1. Add Patient" << endl;
            cout << "2. Display Patients" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();  // Clear newline character left in the buffer

            switch (choice) {
                case 1:
                    addPatient();
                    break;
                case 2:
                    displayPatients();
                    break;
                case 3:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 3);
    }
};

int main() {
    HospitalManagementSystem hms;
    hms.menu();
    return 0;
}
