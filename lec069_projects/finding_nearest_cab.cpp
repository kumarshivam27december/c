#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Location {
    double x; // x-coordinate (longitude)
    double y; // y-coordinate (latitude)
};

struct Cab {
    int id;
    Location location;
};

double calculateDistance(const Location& a, const Location& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

std::vector<Cab> findNearbyCabs(const Location& userLocation, const std::vector<Cab>& cabs, int numNearby) {
    std::vector<std::pair<double, Cab>> distances;

    for (const auto& cab : cabs) {
        double distance = calculateDistance(userLocation, cab.location);
        distances.emplace_back(distance, cab);
    }

    // Sort by distance
    std::sort(distances.begin(), distances.end(), [](const std::pair<double, Cab>& a, const std::pair<double, Cab>& b) {
        return a.first < b.first;
    });

    // Collect the nearest cabs
    std::vector<Cab> nearbyCabs;
    for (int i = 0; i < numNearby && i < distances.size(); ++i) {
        nearbyCabs.push_back(distances[i].second);
    }

    return nearbyCabs;
}

int main() {
    Location userLocation = { 10.0, 20.0 }; // Example user location

    // Example cabs with their locations
    std::vector<Cab> cabs = {
        { 1, { 10.5, 20.5 } },
        { 2, { 11.0, 21.0 } },
        { 3, { 9.5, 19.5 } },
        { 4, { 12.0, 22.0 } }
    };

    int numNearby = 2; // Number of nearby cabs to find
    std::vector<Cab> nearbyCabs = findNearbyCabs(userLocation, cabs, numNearby);

    std::cout << "Nearby cabs:\n";
    for (const auto& cab : nearbyCabs) {
        std::cout << "Cab ID: " << cab.id << ", Location: (" << cab.location.x << ", " << cab.location.y << ")\n";
    }

    return 0;
}
