#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long A[] = {5, 2, 1, 7, 2, 9};
    int n = sizeof(A) / sizeof(A[0]);

    sort(A, A + n);

    bool hasRepeat = false;
    for (int i = 1; i < n; ++i) {
        if (A[i] == A[i - 1]) {
            hasRepeat = true;
            break;
        }
    }

    if (hasRepeat)
        cout << "Repeated elements are present\n";
    else
        cout << "No repeated elements\n";

    return 0;
}
