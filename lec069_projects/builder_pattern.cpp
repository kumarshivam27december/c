#include <iostream>
#include <string>
using namespace std;

// =============================
// Product Class
// =============================
// This is the complex object we want to build step-by-step
class Car {
public:
    string engine;
    string body;
    bool sunroof;
    bool GPS;

    // Utility function to display final car specs
    void showSpecifications() {
        cout << "Engine: " << engine << endl;
        cout << "Body: " << body << endl;
        cout << "Sunroof: " << (sunroof ? "Yes" : "No") << endl;
        cout << "GPS: " << (GPS ? "Yes" : "No") << endl;
    }
};

// =============================
// Abstract Builder Interface
// =============================
// Declares all the building steps
// This allows multiple builder types (e.g., SUVBuilder, TruckBuilder)
class CarBuilder {
public:
    virtual void setEngine() = 0;
    virtual void setBody() = 0;
    virtual void setSunroof(bool) = 0;
    virtual void setGPS(bool) = 0;

    // Returns the final product
    virtual Car* getCar() = 0;

    virtual ~CarBuilder() {}
};

// =============================
// Concrete Builder
// =============================
// Implements the actual building logic for a specific car type
class SportsCarBuilder : public CarBuilder {
private:
    Car* car;
public:
    SportsCarBuilder() {
        car = new Car();  // Initialize an empty car
    }

    void setEngine() override {
        car->engine = "V8 Turbo Engine";
    }

    void setBody() override {
        car->body = "Coupe";
    }

    void setSunroof(bool value) override {
        car->sunroof = value;
    }

    void setGPS(bool value) override {
        car->GPS = value;
    }

    Car* getCar() override {
        return car;
    }
};

// =============================
// Director Class
// =============================
// Responsible for constructing the object in a particular sequence
// Client tells the Director what type of product to build
class CarDirector {
private:
    CarBuilder* builder;
public:
    CarDirector(CarBuilder* b) : builder(b) {}

    // Builds a basic car with no luxury features
    Car* buildBasicCar() {
        builder->setEngine();
        builder->setBody();
        builder->setSunroof(false);
        builder->setGPS(false);
        return builder->getCar();
    }

    // Builds a full-featured luxury car
    Car* buildLuxuryCar() {
        builder->setEngine();
        builder->setBody();
        builder->setSunroof(true);
        builder->setGPS(true);
        return builder->getCar();
    }
};

// =============================
// Main Function - Client Code
// =============================
int main() {
    // Build Basic Car
    SportsCarBuilder* basicBuilder = new SportsCarBuilder();
    CarDirector basicDirector(basicBuilder);
    cout << "--- Basic Car ---" << endl;
    Car* basicCar = basicDirector.buildBasicCar();
    basicCar->showSpecifications();

    // Build Luxury Car
    SportsCarBuilder* luxuryBuilder = new SportsCarBuilder();
    CarDirector luxuryDirector(luxuryBuilder);
    cout << "\n--- Luxury Car ---" << endl;
    Car* luxuryCar = luxuryDirector.buildLuxuryCar();
    luxuryCar->showSpecifications();

    // Cleanup
    delete basicBuilder;
    delete luxuryBuilder;
    delete basicCar;
    delete luxuryCar;

    return 0;
}
