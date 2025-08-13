// Write a program in C++ to print the upper case letters to lower case.
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char upper;
    cout << "Enter an uppercase letter: ";
    cin >> upper;
    cout << "Lowercase: " << char(tolower(upper)) << endl;
    return 0;
}