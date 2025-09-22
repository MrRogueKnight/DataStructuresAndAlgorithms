#include <iostream>
#include <string>

// A union to hold different types in the same memory space
union Value {
    int i;
    float f;
    char c;
};

int main() {
    Value myValue;

    // 1. Store an integer
    myValue.i = 65;
    std::cout << "After assigning integer: " << std::endl;
    std::cout << "myValue.i = " << myValue.i << std::endl;
    std::cout << "myValue.f = " << myValue.f << std::endl; // Garbage
    std::cout << "myValue.c = " << myValue.c << std::endl; // Interprets 65 as a character ('A')

    std::cout << "\n--------------------------\n\n";

    // 2. Store a floating-point number
    myValue.f = 98.6;
    std::cout << "After assigning float: " << std::endl;
    std::cout << "myValue.i = " << myValue.i << std::endl; // Garbage
    std::cout << "myValue.f = " << myValue.f << std::endl;
    std::cout << "myValue.c = " << myValue.c << std::endl; // Garbage

    std::cout << "\n--------------------------\n\n";

    // 3. Store a character
    myValue.c = 'Z';
    std::cout << "After assigning character: " << std::endl;
    std::cout << "myValue.i = " << myValue.i << std::endl; // Garbage
    std::cout << "myValue.f = " << myValue.f << std::endl; // Garbage
    std::cout << "myValue.c = " << myValue.c << std::endl;

    return 0;
}
