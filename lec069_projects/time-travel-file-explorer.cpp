#include <iostream>
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <string>
#include <chrono>

namespace fs = std::filesystem;

std::string SNAP_DIR = ".ttfe_snapshots";

std::string nowTime() {
    auto t = std::chrono::system_clock::now();
    auto tt = std::chrono::system_clock::to_time_t(t);
    std::string s = std::ctime(&tt);
    s.pop_back();
    for (char &c : s) if (c == ':' || c == ' ') c = '-';
    return s;
}

void takeSnapshot(const std::string& target) {
    std::string snapName = SNAP_DIR + "/snap_" + nowTime() + ".txt";
    fs::create_directory(SNAP_DIR);

    std::ofstream out(snapName);
    if (!out) { std::cout << "Failed to save snapshot!\n"; return; }

    for (auto &p : fs::recursive_directory_iterator(target)) {
        if (fs::is_regular_file(p)) {
            auto t = fs::last_write_time(p);
            out << p.path().string() << "|" << t.time_since_epoch().count() << "\n";
        }
    }

    out.close();
    std::cout << "Snapshot saved: " << snapName << "\n";
}

std::unordered_map<std::string, long long> loadSnapshot(const std::string &file) {
    std::unordered_map<std::string, long long> snap;
    std::ifstream in(file);
    std::string line;

    while (std::getline(in, line)) {
        size_t pos = line.find("|");
        std::string path = line.substr(0, pos);
        long long timestamp = std::stoll(line.substr(pos + 1));
        snap[path] = timestamp;
    }
    return snap;
}

void compareSnapshots(const std::string &snapA, const std::string &snapB) {
    auto A = loadSnapshot(snapA);
    auto B = loadSnapshot(snapB);

    std::cout << "\n===== COMPARISON =====\n";

    for (auto &x : B) {
        if (!A.count(x.first))
            std::cout << "[ADDED]    " << x.first << "\n";
    }

    for (auto &x : A) {
        if (!B.count(x.first))
            std::cout << "[REMOVED]  " << x.first << "\n";
    }

    for (auto &x : A) {
        if (B.count(x.first) && A[x.first] != B[x.first])
            std::cout << "[MODIFIED] " << x.first << "\n";
    }

    std::cout << "=======================\n";
}

void listSnapshots() {
    std::cout << "Available Snapshots:\n";
    if (!fs::exists(SNAP_DIR)) return;

    for (auto &p : fs::directory_iterator(SNAP_DIR)) {
        std::cout << " - " << p.path().string() << "\n";
    }
}

int main() {
    std::string target;
    std::cout << "Enter directory to track: ";
    std::getline(std::cin, target);

    int choice;
    while (true) {
        std::cout << "\n--- Time-Travel File Explorer ---\n"
                     "1. Take Snapshot\n"
                     "2. List Snapshots\n"
                     "3. Compare Two Snapshots\n"
                     "4. Exit\n"
                     "Choose: ";
        std::cin >> choice;

        if (choice == 1) {
            takeSnapshot(target);
        }
        else if (choice == 2) {
            listSnapshots();
        }
        else if (choice == 3) {
            std::string a, b;
            std::cout << "Snapshot A path: ";
            std::cin >> a;
            std::cout << "Snapshot B path: ";
            std::cin >> b;
            compareSnapshots(a, b);
        }
        else break;
    }
    return 0;
}

