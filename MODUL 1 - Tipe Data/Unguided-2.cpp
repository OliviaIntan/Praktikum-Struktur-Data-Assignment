#include <iostream>

// Contoh struct
struct Rectangle {
    // Anggota data
    float length;
    float width;

    // Method untuk menghitung luas
    float calculateArea() {
        return length * width;
    }
};

// Contoh class
class Circle {
private:
    // Anggota data
    float radius;

public:
    // Constructor
    Circle(float r) {
        radius = r;
    }

    // Method untuk menghitung luas
    float calculateArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Penggunaan struct
    Rectangle rect;
    rect.length = 5.0;
    rect.width = 3.0;
    std::cout << "Luas persegi panjang: " << rect.calculateArea() << std::endl;

    // Penggunaan class
    Circle circle(2.5);
    std::cout << "Luas lingkaran: " << circle.calculateArea() << std::endl;

    return 0;
}