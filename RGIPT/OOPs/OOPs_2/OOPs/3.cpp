#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    while (n <= 0) {
        cout << "Error: Please enter a positive integer: ";
        cin >> n;
    }

    cout << "Sequence generated from " << n << ":" << endl;
    cout << n << " ";  
    int count = 1;  
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = n * 3 + 1;
        }

        cout << n << " ";
        count++;
        if (count % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl << "Sequence length: " << count << " numbers" << endl;
    return 0;
}