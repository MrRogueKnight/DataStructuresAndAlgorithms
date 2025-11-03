#include <bits/stdc++.h>
using namespace std;
void heapifyDown(vector<int>& a, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;
    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapifyDown(a, n, smallest);
    }
}
void heapifyUp(vector<int>& a, int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && a[i] < a[parent]) {
        swap(a[i], a[parent]);
        heapifyUp(a, parent);
    }
}
void deleteElement(vector<int>& a, int key) {
    int n = a.size();
    int idx = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == key) { idx = i; break; }
    if (idx == -1) return;
    a[idx] = a.back();
    a.pop_back();
    if (idx < a.size()) {
        heapifyUp(a, idx);
        heapifyDown(a, a.size(), idx);
    }
}
int main() {
    vector<int> heap = {5, 10, 15, 20, 30, 40, 50};
    cout << "Original Min Heap: ";
    for (int x : heap) cout << x << " ";
    cout << endl;
    deleteElement(heap, 15);
    cout << "After Deleting 15: ";
    for (int x : heap) cout << x << " ";
    cout << endl;
}
