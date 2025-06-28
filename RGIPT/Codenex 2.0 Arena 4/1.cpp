#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q, x;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> q;
    while(q--) {
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        if(it != v.end() && *it == x)
            cout << "Yes " << (it - v.begin() + 1) << endl;
        else
            cout << "No " << (it - v.begin() + 1) << endl;
    }
    return 0;
}
