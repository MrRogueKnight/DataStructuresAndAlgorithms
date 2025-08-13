// Write a program in C++ to find the area of circle using input value.
#include <iostream>
using namespace std;

int main() {
    double radius, area, pi = 3.14159265359;
    cout << "Enter the radius of circle: ";
    cin >> radius;
    area = pi * pow(radius, 2);
    cout << "Area of circle: " << area << endl;
    return 0;
}