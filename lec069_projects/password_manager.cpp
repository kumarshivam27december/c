#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

class PasswordManager {
public:
    PasswordManager(const std::string& filename) : filename_(filename) {
        load();
    }

    ~PasswordManager() {
        save();
    }

    void addPassword(const std::string& site, const std::string& password) {
        passwords_[site] = password;
    }

    void getPassword(const std::string& site) const {
        auto it = passwords_.find(site);
        if (it != passwords_.end()) {
            std::cout << "Password for " << site << ": " << it->second << std::endl;
        } else {
            std::cout << "No password found for " << site << std::endl;
        }
    }

    void listPasswords() const {
        if (passwords_.empty()) {
            std::cout << "No passwords stored." << std::endl;
            return;
        }

        for (const auto& pair : passwords_) {
            std::cout << "Site: " << pair.first << ", Password: " << pair.second << std::endl;
        }
    }

private:
    std::string filename_;
    std::unordered_map<std::string, std::string> passwords_;

    void load() {
        std::ifstream file(filename_);
        if (!file.is_open()) return;

        std::string site, password;
        while (file >> site >> password) {
            passwords_[site] = password;
        }
        file.close();
    }

    void save() const {
        std::ofstream file(filename_);
        if (!file.is_open()) return;

        for (const auto& pair : passwords_) {
            file << pair.first << ' ' << pair.second << '\n';
        }
        file.close();
    }
};

int main() {
    PasswordManager pm("passwords.txt");

    int choice;
    std::string site, password;

    while (true) {
        std::cout << "1. Add Password\n2. Get Password\n3. List Passwords\n4. Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter site: ";
            std::cin >> site;
            std::cout << "Enter password: ";
            std::cin >> password;
            pm.addPassword(site, password);
            break;
        case 2:
            std::cout << "Enter site: ";
            std::cin >> site;
            pm.getPassword(site);
            break;
        case 3:
            pm.listPasswords();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
