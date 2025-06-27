#include <bits/stdc++.h>
using namespace std;

class vehicle {
public:
    string running;
};

class Brake {
public:
    string brakeType;
};

class DiscBrake : public Brake {
public:
    string discBrakeType;
};

class DrumBrake : public Brake {
public:
    string drumBrakeType;
};

class Engine {
public:
    string enginetype;
};

class oneLitreEngine : public Engine {
public:
    string oneLitreEngineType;
};

class fiveLitreEngine : public Engine {
public:
    string fiveLitreEngineType;
};

class DriveType {
public:
    string driveType;
};

class leftHandDrive : public DriveType {
public:
    string leftHandDriveType;
};

class rightHandDrive : public DriveType {
public:
    string rightHandDriveType;
};

class car : public vehicle {
private:
    static car* instance; // static instance pointer

    // Private constructor
    car(int chesisno, string color, string model, Brake brakeType, Engine enginetype, DriveType driveType) {
        this->chesisno = chesisno;
        this->color = color;
        this->model = model;
        this->brakeType = brakeType;
        this->enginetype = enginetype;
        this->driveType = driveType;
    }

public:
    int chesisno;
    string color;
    string model;
    Brake brakeType;
    Engine enginetype;
    DriveType driveType;

    // Static method to access the singleton instance
    static car* getInstance(int chesisno, string color, string model, Brake brakeType, Engine enginetype, DriveType driveType) {
        if (instance == nullptr) {
            instance = new car(chesisno, color, model, brakeType, enginetype, driveType);
        }
        return instance;
    }
};

// Initialize static member
car* car::instance = nullptr;

int main() {
    DiscBrake discBrake;
    discBrake.brakeType = "Disc Brake";
    discBrake.discBrakeType = "Ventilated Disc Brake";

    oneLitreEngine oneLitre;
    oneLitre.enginetype = "Petrol Engine";

    leftHandDrive leftHand;
    leftHand.driveType = "Left Hand Drive";

    // Creating a Singleton Car instance
    car* bmw5 = car::getInstance(12345, "Blue", "BMW 5 Series", discBrake, oneLitre, leftHand);

    cout << "Car Model: " << bmw5->model << endl;
    cout << "Chassis No: " << bmw5->chesisno << endl;
    cout << "Color: " << bmw5->color << endl;
    cout << "Brake Type: " << bmw5->brakeType.brakeType << endl;
    cout << "Engine Type: " << bmw5->enginetype.enginetype << endl;
    cout << "Drive Type: " << bmw5->driveType.driveType << endl;

    return 0;
}
