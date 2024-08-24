#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ticket {
public:
    Ticket(int id, string eventName, int totalTickets)
        : id(id), eventName(eventName), totalTickets(totalTickets), bookedTickets(0) {}

    int getId() const { return id; }
    string getEventName() const { return eventName; }
    int getTotalTickets() const { return totalTickets; }
    int getBookedTickets() const { return bookedTickets; }
    int getAvailableTickets() const { return totalTickets - bookedTickets; }

    void bookTickets(int count) {
        if (count > getAvailableTickets()) {
            cout << "Not enough tickets available." << endl;
        } else {
            bookedTickets += count;
            cout << count << " tickets booked successfully." << endl;
        }
    }

    void cancelTickets(int count) {
        if (count > bookedTickets) {
            cout << "Cannot cancel more tickets than booked." << endl;
        } else {
            bookedTickets -= count;
            cout << count << " tickets cancelled successfully." << endl;
        }
    }

    void displayInfo() const {
        cout << "Event: " << eventName << endl;
        cout << "Total Tickets: " << totalTickets << endl;
        cout << "Booked Tickets: " << bookedTickets << endl;
        cout << "Available Tickets: " << getAvailableTickets() << endl;
    }

private:
    int id;
    string eventName;
    int totalTickets;
    int bookedTickets;
};

class TicketReservationSystem {
public:
    void addEvent(int id, string eventName, int totalTickets) {
        tickets.push_back(Ticket(id, eventName, totalTickets));
    }

    void viewEvents() const {
        for (const auto& ticket : tickets) {
            cout << "ID: " << ticket.getId() << endl;
            ticket.displayInfo();
            cout << endl;
        }
    }

    void bookTickets(int id, int count) {
        for (auto& ticket : tickets) {
            if (ticket.getId() == id) {
                ticket.bookTickets(count);
                return;
            }
        }
        cout << "Event not found." << endl;
    }

    void cancelTickets(int id, int count) {
        for (auto& ticket : tickets) {
            if (ticket.getId() == id) {
                ticket.cancelTickets(count);
                return;
            }
        }
        cout << "Event not found." << endl;
    }

private:
    vector<Ticket> tickets;
};

int main() {
    TicketReservationSystem system;

    // Adding some events
    system.addEvent(1, "Concert", 100);
    system.addEvent(2, "Theater Play", 50);
    system.addEvent(3, "Movie Screening", 30);

    while (true) {
        cout << "1. View Events" << endl;
        cout << "2. Book Tickets" << endl;
        cout << "3. Cancel Tickets" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                system.viewEvents();
                break;
            }
            case 2: {
                int id, count;
                cout << "Enter Event ID: ";
                cin >> id;
                cout << "Enter number of tickets to book: ";
                cin >> count;
                system.bookTickets(id, count);
                break;
            }
            case 3: {
                int id, count;
                cout << "Enter Event ID: ";
                cin >> id;
                cout << "Enter number of tickets to cancel: ";
                cin >> count;
                system.cancelTickets(id, count);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}


