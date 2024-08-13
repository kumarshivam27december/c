#include <iostream>
#include <map>
#include <string>

using namespace std;

class PhoneBook {
public:
    void addContact(const string& name, const string& phoneNumber) {
        phoneBook[name] = phoneNumber;
        cout << "Contact added." << endl;
    }

    void searchContact(const string& name) const {
        auto it = phoneBook.find(name);
        if (it != phoneBook.end()) {
            cout << "Name: " << it->first << ", Phone Number: " << it->second << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void listContacts() const {
        if (phoneBook.empty()) {
            cout << "Phone book is empty." << endl;
            return;
        }
        for (const auto& contact : phoneBook) {
            cout << "Name: " << contact.first << ", Phone Number: " << contact.second << endl;
        }
    }

private:
    map<string, string> phoneBook;
};

int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        cout << "\nPhone Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. List Contacts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left in the input buffer

        switch (choice) {
            case 1: {
                string name, phoneNumber;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                phoneBook.addContact(name, phoneNumber);
                break;
            }
            case 2: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                phoneBook.searchContact(name);
                break;
            }
            case 3:
                phoneBook.listContacts();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
