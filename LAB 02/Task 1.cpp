#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Function to get data from user
    void getData() {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter marks: ";
        cin >> marks;
    }

    // Function to display data
    void displayData() {
        cout << "\nStudent Information:\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s; 

    s.getData();      
    s.displayData(); 

    return 0;
}
