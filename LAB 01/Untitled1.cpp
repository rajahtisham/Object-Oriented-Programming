#include <iostream>
using namespace std;

struct Student
{
    string firstName;
    string lastName;
    int rollNumber;
    float marks;

    // Member function
    void displayStudentInfo()
    {
        cout << "Full Name: " << firstName << " " << lastName << endl;
        cout << "Marks: " << marks << endl;
    }
    
};

int main()
{
    // object
    Student s1;
    s1.firstName = "Ihtisham";
    s1.lastName = "Hussain";
    s1.rollNumber = 101;
    s1.marks = 73.2;
    
    // Call member function
    s1.displayStudentInfo();

    return 0;
}
