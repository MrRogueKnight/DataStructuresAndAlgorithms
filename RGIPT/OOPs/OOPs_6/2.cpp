#include <iostream>
using namespace std;

class Vehicle {
public:
    string name;
    int wheels;
    Vehicle(string n, int w) { name = n; wheels = w; }
    void display() {
        cout << "Vehicle: " << name << ", Wheels: " << wheels << endl;
    }
};

class two_wheeler : public Vehicle {
public:
    two_wheeler() : Vehicle("Bike", 2) {}
};

class three_wheeler : public Vehicle {
public:
    three_wheeler() : Vehicle("Auto Rickshaw", 3) {}
};

class four_wheeler : public Vehicle {
public:
    four_wheeler() : Vehicle("Car", 4) {}
};

int main() {
    two_wheeler t;
    three_wheeler th;
    four_wheeler f;
    t.display();
    th.display();
    f.display();
    return 0;
}
