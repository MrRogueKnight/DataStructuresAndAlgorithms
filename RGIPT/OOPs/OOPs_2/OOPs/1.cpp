#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double length, breadth, costPerSqMeter;

    cout << "Enter the length of the room (in meters): ";
    cin >> length;

    while (length <= 0) {
        cout << "Error: Length must be a positive value. Please enter again: ";
        cin >> length;
    }

    cout << "Enter the breadth of the room (in meters): ";
    cin >> breadth;

    while (breadth <= 0) {
        cout << "Error: Breadth must be a positive value. Please enter again: ";
        cin >> breadth;
    }

    cout << "Enter the cost per square meter of the carpet: ";
    cin >> costPerSqMeter;

    while (costPerSqMeter <= 0) {
        cout << "Error: Cost must be a positive value. Please enter again: ";
        cin >> costPerSqMeter;
    }

    double area = length * breadth;

    double totalCost = area * costPerSqMeter;

    cout << fixed << setprecision(2);
    cout << "Room dimensions: " << length << "m x " << breadth << "m" << endl;
    cout << "Area of the room: " << area << " square meters" << endl;
    cout << "Cost per square meter: $" << costPerSqMeter << endl;
    cout << "Total cost of carpeting: $" << totalCost << endl;

    return 0;
}