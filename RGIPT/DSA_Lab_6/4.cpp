// Q.4: Given a list of integer pairs, where first element of 
// each pair is unique, write a program to detect the symmetric pairs, 
// e.g., given list {(10,20), (5,6), (8,9), (20,10), (2,3), (3,1)} has (10, 20) and (20,10) 
// symmetric pairs. [Use hashing to solve the problem.]

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find symmetric pairs
void findSymmetricPairs(vector<pair<int, int>> pairs) {
    unordered_map<int, int> mp;

    for (auto p : pairs) {
        int first = p.first;
        int second = p.second;

        // Check if symmetric pair exists (second, first)
        if (mp.find(second) != mp.end() && mp[second] == first) {
            cout << "Symmetric pair found: (" << first << ", " << second
                 << ") and (" << second << ", " << first << ")" << endl;
        } else {
            mp[first] = second;  // store current pair
        }
    }
}

int main() {
    vector<pair<int, int>> pairs = {
        {10, 20},
        {5, 6},
        {8, 9},
        {20, 10},
        {2, 3},
        {3, 1}
    };

    findSymmetricPairs(pairs);

    return 0;
}
