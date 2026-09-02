#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() {
        return 0;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double area() override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double area() override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Shape* shape1;
    Shape* shape2;
    
    Rectangle rect(5.0, 4.0);
    Circle circ(3.0);
    
    shape1 = &rect;
    shape2 = &circ;
    
    cout << "Rectangle Area: " << shape1->area() << endl;
    cout << "Circle Area: " << shape2->area() << endl;
    
    return 0;
}