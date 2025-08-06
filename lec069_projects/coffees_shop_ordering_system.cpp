#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////
// 1. Singleton Pattern
// Used for a single global order manager instance
class OrderManager {
private:
    static OrderManager* instance;
    OrderManager() {}

public:
    static OrderManager* getInstance() {
        if (!instance)
            instance = new OrderManager();
        return instance;
    }

    void confirmOrder(const string& orderDetails) {
        cout << "[OrderManager] Order confirmed: " << orderDetails << endl;
    }
};
OrderManager* OrderManager::instance = nullptr;

////////////////////////////////////////////////////////////////
// 2. Factory Pattern
// Used to create base coffee types
class Beverage {
public:
    virtual string getDescription() = 0;
    virtual int getCost() = 0;
    virtual ~Beverage() {}
};

class Espresso : public Beverage {
public:
    string getDescription() override { return "Espresso"; }
    int getCost() override { return 100; }
};

class Latte : public Beverage {
public:
    string getDescription() override { return "Latte"; }
    int getCost() override { return 120; }
};

class BeverageFactory {
public:
    static unique_ptr<Beverage> createBeverage(const string& type) {
        if (type == "espresso") return make_unique<Espresso>();
        if (type == "latte") return make_unique<Latte>();
        return nullptr;
    }
};

////////////////////////////////////////////////////////////////
// 3. Decorator Pattern
// Used to add toppings like milk, sugar, etc.
class BeverageDecorator : public Beverage {
protected:
    unique_ptr<Beverage> base;
public:
    BeverageDecorator(unique_ptr<Beverage> b) : base(move(b)) {}
};

class Milk : public BeverageDecorator {
public:
    Milk(unique_ptr<Beverage> b) : BeverageDecorator(move(b)) {}

    string getDescription() override {
        return base->getDescription() + " + Milk";
    }
    int getCost() override {
        return base->getCost() + 20;
    }
};

class Sugar : public BeverageDecorator {
public:
    Sugar(unique_ptr<Beverage> b) : BeverageDecorator(move(b)) {}

    string getDescription() override {
        return base->getDescription() + " + Sugar";
    }
    int getCost() override {
        return base->getCost() + 10;
    }
};

////////////////////////////////////////////////////////////////
// 4. Strategy Pattern
// Allow different payment methods at runtime
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "[Payment] Paid ₹" << amount << " via Credit Card\n";
    }
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "[Payment] Paid ₹" << amount << " via UPI\n";
    }
};

////////////////////////////////////////////////////////////////
// 5. Observer Pattern
// Notify displays (like cashier display, kitchen) when order is placed
class Observer {
public:
    virtual void update(const string& order) = 0;
};

class Subject {
    vector<Observer*> observers;
public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void notify(const string& order) {
        for (auto obs : observers)
            obs->update(order);
    }
};

class KitchenDisplay : public Observer {
public:
    void update(const string& order) override {
        cout << "[KitchenDisplay] Prepare: " << order << endl;
    }
};

class CashierDisplay : public Observer {
public:
    void update(const string& order) override {
        cout << "[CashierDisplay] Billing: " << order << endl;
    }
};

////////////////////////////////////////////////////////////////
// Main – Tying it All Together

int main() {
    cout << "\n👨‍🍳 Welcome to Coffee Shop System\n";

    // Create observers
    KitchenDisplay kitchen;
    CashierDisplay cashier;
    Subject orderNotifier;
    orderNotifier.addObserver(&kitchen);
    orderNotifier.addObserver(&cashier);

    // Customer wants a Latte with Milk and Sugar
    auto beverage = BeverageFactory::createBeverage("latte");
    beverage = make_unique<Milk>(move(beverage));
    beverage = make_unique<Sugar>(move(beverage));

    string orderDesc = beverage->getDescription();
    int cost = beverage->getCost();

    cout << "\n🧾 Order Summary:\n";
    cout << "Item: " << orderDesc << "\n";
    cout << "Total: ₹" << cost << "\n\n";

    // Payment using strategy
    unique_ptr<PaymentStrategy> paymentMethod = make_unique<UpiPayment>();
    paymentMethod->pay(cost);

    // Confirm order using singleton manager
    OrderManager::getInstance()->confirmOrder(orderDesc);

    // Notify kitchen & cashier
    orderNotifier.notify(orderDesc);

    return 0;
}
