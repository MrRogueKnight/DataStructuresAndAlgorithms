#include <iostream>
using namespace std;

class Arithmetic {
    int a;
public:
    Arithmetic(int x = 0) { a = x; }
    Arithmetic operator+(Arithmetic b) { return Arithmetic(a + b.a); }
    Arithmetic operator-(Arithmetic b) { return Arithmetic(a - b.a); }
    Arithmetic operator*(Arithmetic b) { return Arithmetic(a * b.a); }
    Arithmetic operator/(Arithmetic b) { return Arithmetic(a / b.a); }
    Arithmetic operator%(Arithmetic b) { return Arithmetic(a % b.a); }
    void display() { cout << a << endl; }
};

int main() {
    Arithmetic n1(20), n2(10), r;
    r = n1 + n2; r.display();
    r = n1 - n2; r.display();
    r = n1 * n2; r.display();
    r = n1 / n2; r.display();
    r = n1 % n2; r.display();

    return 0;
}
