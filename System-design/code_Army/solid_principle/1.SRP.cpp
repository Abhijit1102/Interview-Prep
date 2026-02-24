#include <iostream>
#include <vector>
using namespace std;

// Product class represents an item
class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// ShoppingCart (ONLY manages products)
class ShoppingCart {
private:
    vector<Product> products;

public:
    void addProduct(const Product& p) {
        products.push_back(p);
    }

    const vector<Product>& getProducts() const {
        return products;
    }

    double calculateTotal() const {
        double total = 0;
        for (const auto& p : products) {
            total += p.price;
        }
        return total;
    }
};

// Responsible ONLY for printing
class ShoppingCartPrinter {
private:
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this->cart = cart;
    }

    void printInvoice() {
        cout << "Shopping Cart Invoice\n";
        for (const auto& p : cart->getProducts()) {
            cout << p.name << " - $" << p.price << endl;
        }
        cout << "Total : $" << cart->calculateTotal() << endl;
    }
};

// Responsible ONLY for saving
class ShoppingCartStorage {
private:
    ShoppingCart* cart;

public:
    ShoppingCartStorage(ShoppingCart* cart) {
        this->cart = cart;
    }

    void saveToDatabase() {
        cout << "Saving Shopping Cart to Database..." << endl;
    }
};

int main() {
    ShoppingCart cart;

    cart.addProduct(Product("Laptop", 1500));
    cart.addProduct(Product("Mouse", 50));

    ShoppingCartPrinter printer(&cart);
    printer.printInvoice();

    ShoppingCartStorage db(&cart);
    db.saveToDatabase();

    return 0;
}
