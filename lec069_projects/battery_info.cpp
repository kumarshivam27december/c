// battery_info.cpp
// Cross-platform Battery & Power Status Checker
// Compile: g++ battery_info.cpp -o battery_info
// Windows: g++ battery_info.cpp -o battery_info -lws2_32

#include <iostream>
#include <string>
using namespace std;

#ifdef _WIN32
#include <windows.h>
void checkBattery() {
    SYSTEM_POWER_STATUS status;
    if (GetSystemPowerStatus(&status)) {
        cout << "AC Line Status : " 
             << ((status.ACLineStatus==1) ? "Plugged In" : "On Battery") << endl;
        cout << "Battery Life % : " << (int)status.BatteryLifePercent << "%" << endl;
        cout << "Battery Flag   : " << (int)status.BatteryFlag << endl;
        cout << "Battery Life Time (s): " << status.BatteryLifeTime << endl;
    } else {
        cout << "Failed to get battery info.\n";
    }
}
#else
#include <fstream>
#include <unistd.h>
void checkBattery() {
    string base = "/sys/class/power_supply/BAT0/";
    string line;

    // Status (Charging/Discharging)
    ifstream status(base + "status");
    if (status.is_open()) {
        getline(status, line);
        cout << "Battery Status : " << line << endl;
        status.close();
    }

    // Capacity (%)
    ifstream capacity(base + "capacity");
    if (capacity.is_open()) {
        getline(capacity, line);
        cout << "Battery Capacity : " << line << "%" << endl;
        capacity.close();
    }

    // Power supply presence
    ifstream present(base + "present");
    if (present.is_open()) {
        getline(present, line);
        cout << "Battery Present : " << (line=="1" ? "Yes" : "No") << endl;
        present.close();
    }
}
#endif

int main() {
    cout << "=== Battery & Power Info ===\n";
    checkBattery();
    return 0;
}
