#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// -------------------- Q1: Separate Chaining --------------------
void separateChaining(int m, const vector<int>& keys) {
    vector<vector<int>> hashTable(m);

    for (int key : keys) {
        int index = key % m;
        hashTable[index].push_back(key);
    }

    cout << "\nSeparate Chaining Hash Table (m = " << m << "):\n";
    for (int i = 0; i < m; ++i) {
        cout << setw(2) << i << " -> ";
        for (int val : hashTable[i]) cout << val << " -> ";
        cout << "NULL\n";
    }
}

// -------------------- Q2: Quadratic Probing --------------------
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

// -------------------- Q2: Double Hashing --------------------
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

// -------------------- Display Function --------------------
void displayOpenAddressing(const vector<int>& table, const string& title) {
    cout << "\n" << title << ":\n";
    for (int i = 0; i < table.size(); ++i) {
        cout << setw(2) << i << " -> ";
        if (table[i] == -1) cout << "NULL\n";
        else cout << table[i] << "\n";
    }
}

// -------------------- MAIN --------------------
int main() {
    // ---- Q1: Separate Chaining ----
    vector<int> keys = {75, 88, 28, 33, 55, 95, 31, 65, 42, 10, 21, 99, 108, 105};
    separateChaining(10, keys);   // Case A
    separateChaining(13, keys);   // Case B

    // ---- Q2: Open Addressing ----
    int m = 27, R = 23;
    vector<int> tableQuad(m, -1), tableDouble(m, -1);

    int quadCollisions = quadraticProbing(m, keys, tableQuad);
    int doubleCollisions = doubleHashing(m, R, keys, tableDouble);

    displayOpenAddressing(tableQuad, "Quadratic Probing Hash Table");
    displayOpenAddressing(tableDouble, "Double Hashing Hash Table");

    cout << "\nCollision Comparison:\n";
    cout << "Quadratic Probing Collisions = " << quadCollisions << "\n";
    cout << "Double Hashing Collisions   = " << doubleCollisions << "\n";

    return 0;
}
