#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s, p;
    cin >> s >> p;
    vector<pair<int, int>> shots(s), players(p);
    for(int i = 0; i < s; i++) cin >> shots[i].first >> shots[i].second;
    for(int i = 0; i < p; i++) cin >> players[i].first >> players[i].second;
    int total = 0;
    for(int i = 0; i < p; i++) {
        int strength = 0;
        for(int j = 0; j < s; j++) {
            if(!(players[i].second < shots[j].first || players[i].first > shots[j].second))
                strength++;
        }
        total += strength;
    }
    cout << total;
    return 0;
}
