#include <iostream>
#include <climits>
using namespace std;

int main() {
    int smallest = INT_MAX, num;
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++) {
        cin >> num;
        if (num < smallest) smallest = num;
    }
    cout << "Smallest number: " << smallest << endl;
    return 0;
}