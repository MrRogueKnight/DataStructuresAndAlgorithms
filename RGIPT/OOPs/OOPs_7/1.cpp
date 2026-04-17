#include <iostream>
using namespace std;

int main();
class Logic {
    int a;
public:
    Logic(int x) { a = x; }
    friend bool operator&&(Logic &x, Logic &y);
    friend bool operator||(Logic &x, Logic &y);
};

bool operator&&(Logic &x, Logic &y) {
    return (x.a && y.a);
}

bool operator||(Logic &x, Logic &y) {
    return (x.a || y.a);
}

int main() {
    Logic x1(1), x2(0);
    cout << (x1 && x2) << endl;
    cout << (x1 || x2) << endl;

    return 0;
}
