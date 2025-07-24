#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <memory>
using namespace std;

// Vehicle
enum class VehicleType { BIKE, CAR, TRUCK };

class Vehicle {
public:
    string licensePlate;
    VehicleType type;

    Vehicle(string licensePlate, VehicleType type) : licensePlate(licensePlate), type(type) {}
};

//  Parking Slot 
enum class SlotType { BIKE, CAR, TRUCK };

class ParkingSlot {
    int slotId;
    SlotType type;
    bool occupied;
    shared_ptr<Vehicle> vehicle;

public:
    ParkingSlot(int id, SlotType type) : slotId(id), type(type), occupied(false) {}

    bool isAvailable() const { return !occupied; }
    SlotType getSlotType() const { return type; }
    int getSlotId() const { return slotId; }

    void parkVehicle(shared_ptr<Vehicle> v) {
        vehicle = v;
        occupied = true;
    }

    void unparkVehicle() {
        vehicle = nullptr;
        occupied = false;
    }

    shared_ptr<Vehicle> getParkedVehicle() const { return vehicle; }
};

//  Parking Floor 
class ParkingFloor {
    int floorNumber;
    vector<shared_ptr<ParkingSlot>> slots;

public:
    ParkingFloor(int number, int bikeSlots, int carSlots, int truckSlots) : floorNumber(number) {
        int id = 1;
        for (int i = 0; i < bikeSlots; i++) slots.push_back(make_shared<ParkingSlot>(id++, SlotType::BIKE));
        for (int i = 0; i < carSlots; i++) slots.push_back(make_shared<ParkingSlot>(id++, SlotType::CAR));
        for (int i = 0; i < truckSlots; i++) slots.push_back(make_shared<ParkingSlot>(id++, SlotType::TRUCK));
    }

    shared_ptr<ParkingSlot> getAvailableSlot(VehicleType vType) {
        SlotType desiredType = (vType == VehicleType::BIKE) ? SlotType::BIKE :
                               (vType == VehicleType::CAR) ? SlotType::CAR : SlotType::TRUCK;

        for (auto &slot : slots) {
            if (slot->getSlotType() == desiredType && slot->isAvailable())
                return slot;
        }
        return nullptr;
    }

    int getFloorNumber() const { return floorNumber; }
};

//  Ticket 
class Ticket {
public:
    string ticketId;
    time_t entryTime;
    shared_ptr<Vehicle> vehicle;
    int floorNumber;
    int slotId;

    Ticket(string id, shared_ptr<Vehicle> v, int floor, int slot)
        : ticketId(id), entryTime(time(nullptr)), vehicle(v), floorNumber(floor), slotId(slot) {}
};

//  Parking Lot 
class ParkingLot {
    string lotId;
    vector<shared_ptr<ParkingFloor>> floors;
    unordered_map<string, shared_ptr<Ticket>> activeTickets;

public:
    ParkingLot(string id, int numberOfFloors, int bikeSlots, int carSlots, int truckSlots) : lotId(id) {
        for (int i = 0; i < numberOfFloors; i++) {
            floors.push_back(make_shared<ParkingFloor>(i + 1, bikeSlots, carSlots, truckSlots));
        }
    }

    shared_ptr<Ticket> parkVehicle(shared_ptr<Vehicle> vehicle) {
        for (auto &floor : floors) {
            auto slot = floor->getAvailableSlot(vehicle->type);
            if (slot) {
                slot->parkVehicle(vehicle);
                string ticketId = "T" + vehicle->licensePlate + to_string(time(nullptr));
                auto ticket = make_shared<Ticket>(ticketId, vehicle, floor->getFloorNumber(), slot->getSlotId());
                activeTickets[ticketId] = ticket;
                cout << "Ticket ID: " << ticketId << " issued for vehicle: " << vehicle->licensePlate << endl;
                return ticket;
            }
        }
        cout << "No available slot for vehicle: " << vehicle->licensePlate << endl;
        return nullptr;
    }

    void unparkVehicle(string ticketId) {
        if (activeTickets.find(ticketId) == activeTickets.end()) {
            cout << "Invalid Ticket ID!" << endl;
            return;
        }

        auto ticket = activeTickets[ticketId];
        auto floor = floors[ticket->floorNumber - 1];

        for (auto &slot : floor->getAvailableSlot(ticket->vehicle->type)->getParkedVehicle()) {
            if (slot->getSlotId() == ticket->slotId) {
                slot->unparkVehicle();
                break;
            }
        }

        time_t exitTime = time(nullptr);
        double duration = difftime(exitTime, ticket->entryTime) / 60.0; // in minutes
        cout << "Vehicle " << ticket->vehicle->licensePlate << " unparked. Duration: " << duration << " mins." << endl;
        activeTickets.erase(ticketId);
    }

    void displayStatus() {
        for (auto &floor : floors) {
            cout << "Floor " << floor->getFloorNumber() << " status:\n";
        }
    }
};

//  Entry & Exit Gates 
class EntryGate {
public:
    shared_ptr<Ticket> processVehicle(shared_ptr<ParkingLot> lot, shared_ptr<Vehicle> vehicle) {
        return lot->parkVehicle(vehicle);
    }
};

class ExitGate {
public:
    void processExit(shared_ptr<ParkingLot> lot, string ticketId) {
        lot->unparkVehicle(ticketId);
    }
};

//  MAIN 
int main() {
    auto lot = make_shared<ParkingLot>("LOT1", 2, 2, 2, 1); // 2 floors, 2 slots each type
    EntryGate entry;
    ExitGate exit;

    auto car1 = make_shared<Vehicle>("KA01AB1234", VehicleType::CAR);
    auto bike1 = make_shared<Vehicle>("KA02XY9876", VehicleType::BIKE);

    auto ticket1 = entry.processVehicle(lot, car1);
    auto ticket2 = entry.processVehicle(lot, bike1);

    // simulate exit
    if (ticket1) exit.processExit(lot, ticket1->ticketId);
}
