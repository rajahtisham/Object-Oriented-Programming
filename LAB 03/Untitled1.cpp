#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    // Setter for name
    void setName(string n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "Invalid name! Name cannot be empty." << endl;
        }
    }

    // Setter for price
    void setPrice(double p) {
        if (p > 0) {
            price = p;
        } else {
            cout << "Invalid price! Price must be greater than 0." << endl;
        }
    }

    // Setter for quantity
    void setQuantity(int q) {
        if (q >= 0) {
            quantity = q;
        } else {
            cout << "Invalid quantity! Quantity cannot be negative." << endl;
        }
    }

    // Getters
    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }
};
