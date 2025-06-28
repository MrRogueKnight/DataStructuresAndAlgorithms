#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> res(n);
    for(int i = 0; i < n; i++) res[i] = a[(i + d) % n];
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    return 0;
}
