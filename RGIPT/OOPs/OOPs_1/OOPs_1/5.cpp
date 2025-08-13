// Write a program in C++ to check whether the given character upper, lower , number or not.
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    if (isupper(ch)) cout << "Uppercase letter" << endl;
    else if (islower(ch)) cout << "Lowercase letter" << endl;
    else if (isdigit(ch)) cout << "Number" << endl;
    else cout << "Other character" << endl;
    return 0;
}