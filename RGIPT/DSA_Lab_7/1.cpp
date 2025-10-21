#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    auto separateChaining = [](int m, const vector<int>& keys) {
        vector<vector<int>> hashTable(m);
        for (int key : keys) {
            int index = key % m;
            hashTable[index].push_back(key);
        }
        cout << "\nHash Table (m = " << m << "):\n";
        for (int i = 0; i < m; ++i) {
            cout << setw(2) << i << " -> ";
            for (int val : hashTable[i]) cout << val << " -> ";
            cout << "NULL\n";
        }
    };

    vector<int> keys = {75, 88, 28, 33, 55, 95, 31, 65, 42, 10, 21, 99, 108, 105};
    separateChaining(10, keys);
    separateChaining(13, keys);
    return 0;
}
