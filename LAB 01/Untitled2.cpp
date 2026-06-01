#include <iostream>
using namespace std;

struct Student
{
    string firstName;
    string lastName;
    int rollNumber;
    float marks;

    void displayStudentInfo()
    {
        cout << "Full Name: " << firstName << " " << lastName << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    //ARRAY
    Student s[n];   
    
    for(int i = 0; i < n; i++)
    {
        cout << " Enter details for Student " << i+1 << endl;
        cout << "First Name: ";
        cin >> s[i].firstName;
        cout << "Last Name: ";
        cin >> s[i].lastName;
        cout << "Roll Number: ";
        cin >> s[i].rollNumber;
        cout << "Marks: ";
        cin >> s[i].marks;
    }

    // Display details
    cout << "Student Information:"<<endl;
    for(int i = 0; i < n; i++)
    {
        s[i].displayStudentInfo();
    }
    
    return 0;
}
