#include <iostream>
using namespace std;

class Exchange {
    int a;
public:
    Exchange(int x = 0) { a = x; }

    Exchange operator=(Exchange &b) {
        Exchange temp;
        temp.a = b.a;
        cout << "Assignment (=) operator called" << endl;
        cout << "But performing comparison instead." << endl;
        cout << "Result (a == b): " << (a == b.a) << endl;
        return temp;
    }

    bool operator==(Exchange &b) {
        cout << "Equal to (==) operator called" << endl;
        cout << "But performing assignment instead." << endl;
        a = b.a;
        return true;
    }

    void show() { cout << "Value of a: " << a << endl; }
};

int main() {
    Exchange e1(5), e2(10);
    e1 == e2;
    e1.show();
    e1 = e2;

    return 0;
}