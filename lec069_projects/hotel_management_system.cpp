#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Room {
public:
    int roomNumber;
    bool isAvailable;

    Room(int num) : roomNumber(num), isAvailable(true) {}

    void book() {
        isAvailable = false;
    }

    void vacate() {
        isAvailable = true;
    }

    void display() const {
        cout << "Room " << roomNumber << " is " << (isAvailable ? "Available" : "Booked") << endl;
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel(int numRooms) {
        for (int i = 1; i <= numRooms; ++i) {
            rooms.push_back(Room(i));
        }
    }

    void bookRoom(int roomNumber) {
        for (auto &room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (room.isAvailable) {
                    room.book();
                    cout << "Room " << roomNumber << " has been booked successfully." << endl;
                    return;
                } else {
                    cout << "Room " << roomNumber << " is already booked." << endl;
                    return;
                }
            }
        }
        cout << "Room " << roomNumber << " does not exist." << endl;
    }

    void vacateRoom(int roomNumber) {
        for (auto &room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (!room.isAvailable) {
                    room.vacate();
                    cout << "Room " << roomNumber << " has been vacated successfully." << endl;
                    return;
                } else {
                    cout << "Room " << roomNumber << " is not booked." << endl;
                    return;
                }
            }
        }
        cout << "Room " << roomNumber << " does not exist." << endl;
    }

    void displayRoomStatus() const {
        for (const auto &room : rooms) {
            room.display();
        }
    }
};

int main() {
    Hotel hotel(10); // Initialize a hotel with 10 rooms
    int choice, roomNumber;

    while (true) {
        cout << "\nHotel Management System" << endl;
        cout << "1. Book Room" << endl;
        cout << "2. Vacate Room" << endl;
        cout << "3. Display Room Status" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter room number to book: ";
                cin >> roomNumber;
                hotel.bookRoom(roomNumber);
                break;
            case 2:
                cout << "Enter room number to vacate: ";
                cin >> roomNumber;
                hotel.vacateRoom(roomNumber);
                break;
            case 3:
                hotel.displayRoomStatus();
                break;
            case 4:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }
}
