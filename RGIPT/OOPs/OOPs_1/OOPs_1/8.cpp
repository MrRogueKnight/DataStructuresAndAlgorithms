// Write a program in C++ to display the even or odd numbers between 1 to 100 using while loop.
#include <iostream>
using namespace std;

int main() {
    int i = 1;
    cout << "Even numbers: ";
    while (i <= 100) {
        if (i % 2 == 0) cout << i << " ";
        i++;
    }
    cout << "\nOdd numbers: ";
    i = 1;
    while (i <= 100) {
        if (i % 2 != 0) cout << i << " ";
        i++;
    }
    return 0;
}