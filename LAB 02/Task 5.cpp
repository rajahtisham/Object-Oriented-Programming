#include <iostream>
using namespace std;

class Calculator {
private:
    float num1, num2;

public:
    void setValues() {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;
    }

    float add() {
        return num1 + num2;
    }

    float subtract() {
        return num1 - num2;
    }

    float multiply() {
        return num1 * num2;
    }

    float divide() {
        if (num2 == 0) {
            cout << "Error: Division by zero is not allowed!" << endl;
            return 0;
        }
        return num1 / num2;
    }
};

int main() {
    Calculator c;
    int choice;

    c.setValues();

    cout << "\nChoose operation:\n";
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Result: " << c.add() << endl;
            break;
        case 2:
            cout << "Result: " << c.subtract() << endl;
            break;
        case 3:
            cout << "Result: " << c.multiply() << endl;
            break;
        case 4:
            cout << "Result: " << c.divide() << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
