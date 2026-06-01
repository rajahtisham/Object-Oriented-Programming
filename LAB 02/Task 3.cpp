#include <iostream>
using namespace std;

class Voter {
private:
    string name;
    int age;

public:
    void setData();     
    bool isEligible(); 
};

// Function definitions outside the class

void Voter::setData() {
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter age: ";
    cin >> age;
}

bool Voter::isEligible() {
    if (age > 18)
        return true;
    else
        return false;
}

int main() {
    Voter v; 

    v.setData();

    if (v.isEligible()) {
        cout << "\nEligible to vote." << endl;
    } else {
        cout << "\nNot eligible to vote." << endl;
    }

    return 0;
}
