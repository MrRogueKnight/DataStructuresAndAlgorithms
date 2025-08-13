// Write a program in C++ to show of a numeric value of a variable using hex, oct, and dec manipulator functions.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Decimal: " << dec << num << endl;
    cout << "Octal: " << oct << num << endl;
    cout << "Hexadecimal: " << hex << num << endl;
    return 0;
}