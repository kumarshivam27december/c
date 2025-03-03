#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Record {
    int id;
    string name;
    int age;
};

// --- Database Class ---
class SimpleDBMS {
private:
    string filename;
public:
    SimpleDBMS(string file) : filename(file) {}

    void insert(int id, string name, int age) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << id << "," << name << "," << age << "\n";
            file.close();
            cout << "✅ Record Inserted!\n";
        } else {
            cout << "❌ Error opening file!\n";
        }
    }

    void search(int id) {
        ifstream file(filename);
        string line;
        bool found = false;
        
        while (getline(file, line)) {
            stringstream ss(line);
            string temp;
            vector<string> data;

            while (getline(ss, temp, ',')) 
                data.push_back(temp);

            if (stoi(data[0]) == id) {
                cout << "🔍 Found: ID=" << data[0] << ", Name=" << data[1] << ", Age=" << data[2] << "\n";
                found = true;
                break;
            }
        }

        if (!found) cout << "❌ Record Not Found!\n";
    }

    void displayAll() {
        ifstream file(filename);
        string line;
        cout << "\n📜 ALL RECORDS 📜\n";
        while (getline(file, line)) cout << line << endl;
        cout << "----------------------\n";
    }

    void deleteRecord(int id) {
        ifstream file(filename);
        ofstream temp("temp.txt");
        string line;
        bool deleted = false;

        while (getline(file, line)) {
            stringstream ss(line);
            string tempStr;
            vector<string> data;
            while (getline(ss, tempStr, ',')) 
                data.push_back(tempStr);

            if (stoi(data[0]) == id) {
                deleted = true;
                continue;  // Skip this record (deleting)
            }
            temp << line << "\n";
        }

        file.close();
        temp.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        if (deleted) cout << "✅ Record Deleted!\n";
        else cout << "❌ Record Not Found!\n";
    }
};

// --- Main Function ---
int main() {
    SimpleDBMS db("database.txt");
    int choice, id, age;
    string name;

    while (true) {
        cout << "\n📌 Simple DBMS 📌\n";
        cout << "1. Insert Record\n2. Search by ID\n3. Display All\n4. Delete Record\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID, Name, Age: ";
                cin >> id >> name >> age;
                db.insert(id, name, age);
                break;
            case 2:
                cout << "Enter ID to Search: ";
                cin >> id;
                db.search(id);
                break;
            case 3:
                db.displayAll();
                break;
            case 4:
                cout << "Enter ID to Delete: ";
                cin >> id;
                db.deleteRecord(id);
                break;
            case 5:
                cout << "📂 Exiting DBMS...\n";
                return 0;
            default:
                cout << "❌ Invalid Choice!\n";
        }
    }
}
