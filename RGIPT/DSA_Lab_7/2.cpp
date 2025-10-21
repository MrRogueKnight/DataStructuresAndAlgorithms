#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int quadraticProbing(int m, const vector<int>& keys, vector<int>& table) {
    int collisions = 0;
    for (int key : keys) {
        int h = key % m;
        int i = 0, pos = h;
        while (table[pos] != -1) {
            collisions++;
            i++;
            pos = (h + i * i) % m;
        }
        table[pos] = key;
    }
    return collisions;
}

int doubleHashing(int m, int R, const vector<int>& keys, vector<int>& table) {
    int collisions = 0;
    for (int key : keys) {
        int h1 = key % m;
        int h2 = R - (key % R);
        int i = 0, pos = h1;
        while (table[pos] != -1) {
            collisions++;
            i++;
            pos = (h1 + i * h2) % m;
        }
        table[pos] = key;
    }
    return collisions;
}

void display(const vector<int>& table, string title) {
    cout << "\n" << title << ":\n";
    for (int i = 0; i < table.size(); ++i) {
        cout << setw(2) << i << " -> ";
        if (table[i] == -1) cout << "NULL\n";
        else cout << table[i] << "\n";
    }
}

int main() {
    int m = 27, R = 23;
    vector<int> keys = {75, 88, 28, 33, 55, 95, 31, 65, 42, 10, 21, 99, 108, 105};
    vector<int> tableQuad(m, -1), tableDouble(m, -1);
    int quadCollisions = quadraticProbing(m, keys, tableQuad);
    int doubleCollisions = doubleHashing(m, R, keys, tableDouble);
    display(tableQuad, "Quadratic Probing Hash Table");
    display(tableDouble, "Double Hashing Hash Table");
    cout << "\nCollision Comparison:\n";
    cout << "Quadratic Probing Collisions = " << quadCollisions << "\n";
    cout << "Double Hashing Collisions   = " << doubleCollisions << "\n";
    return 0;
}
