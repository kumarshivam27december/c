#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

class StockManager {
public:
    StockManager(const std::string& filename) : filename(filename) {
        loadStock();
    }

    ~StockManager() {
        saveStock();
    }

    void addProduct() {
        std::string productName;
        int quantity;
        std::cout << "Enter product name: ";
        std::cin.ignore();
        std::getline(std::cin, productName);
        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        stock[productName] += quantity;
        std::cout << "Product added/updated successfully.\n";
    }

    void removeProduct() {
        std::string productName;
        int quantity;
        std::cout << "Enter product name: ";
        std::cin.ignore();
        std::getline(std::cin, productName);
        std::cout << "Enter quantity to remove: ";
        std::cin >> quantity;

        auto it = stock.find(productName);
        if (it != stock.end()) {
            if (it->second >= quantity) {
                it->second -= quantity;
                if (it->second == 0) {
                    stock.erase(it);
                }
                std::cout << "Product removed successfully.\n";
            } else {
                std::cout << "Insufficient stock to remove.\n";
            }
        } else {
            std::cout << "Product not found.\n";
        }
    }

    void listProducts() const {
        if (stock.empty()) {
            std::cout << "No products in stock.\n";
        } else {
            std::cout << "Product List:\n";
            for (const auto& item : stock) {
                std::cout << "Product: " << item.first << ", Quantity: " << item.second << '\n';
            }
        }
    }

private:
    std::string filename;
    std::unordered_map<std::string, int> stock;

    void loadStock() {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                std::string productName;
                int quantity;
                if (std::getline(iss, productName, ':') && (iss >> quantity)) {
                    stock[productName] = quantity;
                }
            }
            file.close();
        }
    }

    void saveStock() const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& item : stock) {
                file << item.first << ':' << item.second << '\n';
            }
            file.close();
        }
    }
};

int main() {
    StockManager stockManager("stock.txt");

    while (true) {
        int choice;
        std::cout << "1. Add Product\n2. Remove Product\n3. List Products\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                stockManager.addProduct();
                break;
            case 2:
                stockManager.removeProduct();
                break;
            case 3:
                stockManager.listProducts();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
