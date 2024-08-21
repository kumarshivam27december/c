#include <iostream>
#include <vector>
#include <string>

// Product Class
class Product {
private:
    std::string name;
    double price;

public:
    Product(std::string n, double p) : name(n), price(p) {}

    std::string getName() const { return name; }
    double getPrice() const { return price; }

    void display() const {
        std::cout << "Product: " << name << ", Price: $" << price << std::endl;
    }
};

// Cart Class
class Cart {
private:
    std::vector<Product> items;

public:
    void addProduct(const Product& product) {
        items.push_back(product);
    }

    void removeProduct(const std::string& productName) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getName() == productName) {
                items.erase(it);
                return;
            }
        }
        std::cout << "Product not found in cart." << std::endl;
    }

    void displayCart() const {
        if (items.empty()) {
            std::cout << "Cart is empty." << std::endl;
            return;
        }
        std::cout << "Items in cart:" << std::endl;
        for (const auto& item : items) {
            item.display();
        }
    }

    double getTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getPrice();
        }
        return total;
    }
};

// User Class
class User {
private:
    std::string username;
    Cart cart;

public:
    User(std::string name) : username(name) {}

    std::string getUsername() const { return username; }

    Cart& getCart() { return cart; }

    void displayInfo() const {
        std::cout << "Username: " << username << std::endl;
    }
};

// Main function
int main() {
    std::vector<Product> products = {
        Product("Laptop", 999.99),
        Product("Smartphone", 599.99),
        Product("Headphones", 149.99)
    };

    User user("john_doe");

    int choice;
    do {
        std::cout << "\nOnline Shopping System\n";
        std::cout << "1. View Products\n";
        std::cout << "2. Add Product to Cart\n";
        std::cout << "3. Remove Product from Cart\n";
        std::cout << "4. View Cart\n";
        std::cout << "5. Checkout\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nAvailable Products:\n";
                for (const auto& product : products) {
                    product.display();
                }
                break;
            case 2: {
                std::string productName;
                std::cout << "Enter product name to add to cart: ";
                std::cin.ignore(); // To ignore the newline character left in the buffer
                std::getline(std::cin, productName);

                bool found = false;
                for (const auto& product : products) {
                    if (product.getName() == productName) {
                        user.getCart().addProduct(product);
                        std::cout << "Product added to cart." << std::endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Product not found." << std::endl;
                }
                break;
            }
            case 3: {
                std::string productName;
                std::cout << "Enter product name to remove from cart: ";
                std::cin.ignore(); // To ignore the newline character left in the buffer
                std::getline(std::cin, productName);

                user.getCart().removeProduct(productName);
                break;
            }
            case 4:
                user.getCart().displayCart();
                break;
            case 5:
                std::cout << "Total amount: $" << user.getCart().getTotal() << std::endl;
                user.getCart().displayCart();
                std::cout << "Thank you for shopping with us!" << std::endl;
                break;
            case 0:
                std::cout << "Exiting the system." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
