#include <iostream>
using namespace std;

class Temperature {
public:
    float celsius;   

    float toFahrenheit() {   
        return (celsius * 9/5) + 32;
    }

    void display() {   
        cout << "Temperature in Fahrenheit: " << toFahrenheit() << endl;
    }
};

int main() {
    Temperature t;  

    cout << "Enter temperature in Celsius: ";
    cin >> t.celsius;

    t.display();  

    return 0;
}
