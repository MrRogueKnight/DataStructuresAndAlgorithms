#include <bits/stdc++.h>
using namespace std;

void heapifyDown(vector<int> &h, int n, int i) {
    while (true) {
        int l = 2 * i;
        int r = 2 * i + 1;
        int smallest = i;
        if (l <= n && h[l] < h[smallest]) smallest = l;
        if (r <= n && h[r] < h[smallest]) smallest = r;
        if (smallest == i) break;
        swap(h[i], h[smallest]);
        i = smallest;
    }
}

void heapifyUp(vector<int> &h, int i) {
    while (i > 1) {
        int p = i / 2;
        if (h[p] <= h[i]) break;
        swap(h[p], h[i]);
        i = p;
    }
}

void deleteAtIndex(vector<int> &h, int &n, int idx) {
    if (idx < 1 || idx > n) return;
    if (idx == n) {
        n--;
        return;
    }
    h[idx] = h[n];
    n--;
    if (idx > 1 && h[idx] < h[idx / 2]) heapifyUp(h, idx);
    else heapifyDown(h, n, idx);
}

int main() {
    vector<int> h(1);
    h.push_back(2);
    h.push_back(4);
    h.push_back(5);
    h.push_back(7);
    h.push_back(8);
    h.push_back(9);
    int n = 6;

    cout << "Initial heap: ";
    for (int i = 1; i <= n; i++) cout << h[i] << " ";
    cout << endl;

    int idx = 3;
    deleteAtIndex(h, n, idx);

    cout << "Heap after deleting index " << idx << ": ";
    for (int i = 1; i <= n; i++) cout << h[i] << " ";
    cout << endl;

    return 0;
}
