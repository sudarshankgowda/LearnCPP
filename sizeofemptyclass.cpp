#include <iostream>

class Shape {
public:
    virtual void draw() const {
        // Base class implementation
    }
};

class Circle : public Shape {
public:
    // Additional members specific to Circle, if any

    void draw() const override {
        // Derived class implementation
    }
};

int main() {
    Shape *ptr = new Shape();
    std::cout << "Size of Shape object: " << sizeof(*ptr) << " bytes" << std::endl;
    Circle* circlePtr = new Circle();
    std::cout << "Size of Circle object: " << sizeof(*circlePtr) << " bytes" << std::endl;

    delete circlePtr;  // Don't forget to free the allocated memory

    return 0;
}
