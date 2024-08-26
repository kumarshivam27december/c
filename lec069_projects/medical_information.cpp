#include <iostream>
#include <vector>
#include <string>

// Define a class to represent a patient
class Patient {
public:
    Patient(const std::string& name, int age, const std::string& medicalHistory)
        : name(name), age(age), medicalHistory(medicalHistory) {}

    void displayPatientInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Medical History: " << medicalHistory << std::endl;
    }

private:
    std::string name;
    int age;
    std::string medicalHistory;
};

// Define a class to represent the medical information system
class MedicalInformationSystem {
public:
    void addPatient(const std::string& name, int age, const std::string& medicalHistory) {
        patients.push_back(Patient(name, age, medicalHistory));
    }

    void displayAllPatients() const {
        if (patients.empty()) {
            std::cout << "No patients available." << std::endl;
            return;
        }

        for (const auto& patient : patients) {
            patient.displayPatientInfo();
            std::cout << "-------------------" << std::endl;
        }
    }

private:
    std::vector<Patient> patients;
};

int main() {
    MedicalInformationSystem system;

    // Adding some patients
    system.addPatient("John Doe", 30, "No known allergies.");
    system.addPatient("Jane Smith", 45, "Diabetes Type 2.");

    // Display all patients
    std::cout << "Patient Information:" << std::endl;
    system.displayAllPatients();

    return 0;
}
