#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
vector<int> mergeHeaps(vector<int>& a, vector<int>& b) {
    vector<int> merged = a;
    merged.insert(merged.end(), b.begin(), b.end());
    int n = merged.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(merged, n, i);
    return merged;
}
int main() {
    vector<int> heap1 = {50, 30, 40, 10, 5, 20, 30};
    vector<int> heap2 = {45, 35, 15, 20};
    vector<int> merged = mergeHeaps(heap1, heap2);
    cout << "Merged Max Heap: ";
    for (int x : merged) cout << x << " ";
    cout << endl;
}
