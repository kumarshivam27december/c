#include <iostream>
#include <thread>
#include <chrono>

// Enum to represent traffic light states
enum class TrafficLightState {
    RED,
    GREEN,
    YELLOW
};

// Class to manage traffic light
class TrafficLight {
private:
    TrafficLightState state;

public:
    TrafficLight() : state(TrafficLightState::RED) {}

    // Function to simulate traffic light changes
    void changeState() {
        switch (state) {
            case TrafficLightState::RED:
                state = TrafficLightState::GREEN;
                break;
            case TrafficLightState::GREEN:
                state = TrafficLightState::YELLOW;
                break;
            case TrafficLightState::YELLOW:
                state = TrafficLightState::RED;
                break;
        }
    }

    // Function to display the current state
    void displayState() const {
        switch (state) {
            case TrafficLightState::RED:
                std::cout << "RED\n";
                break;
            case TrafficLightState::GREEN:
                std::cout << "GREEN\n";
                break;
            case TrafficLightState::YELLOW:
                std::cout << "YELLOW\n";
                break;
        }
    }
};

// Function to simulate traffic light management
void trafficLightSimulation() {
    TrafficLight trafficLight;
    while (true) {
        trafficLight.displayState();
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for 2 seconds
        trafficLight.changeState();
    }
}

int main() {
    std::cout << "Traffic Light Management System\n";
    std::cout << "Simulation running. Press Ctrl+C to exit.\n";
    trafficLightSimulation();
    return 0;
}
