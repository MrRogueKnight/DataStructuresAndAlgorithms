#include <iostream>
using namespace std;

class Number {
    int a, b;
    void display() {
        cout << "a = " << a << ", b = " << b << endl;
    }
public:
    void setValues(int x, int y) {
        a = x;
        b = y;
        display();
    }
};

int main() {
    Number obj;
    obj.setValues(10, 20);
    return 0;
}