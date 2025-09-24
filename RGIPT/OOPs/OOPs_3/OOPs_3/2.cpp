#include <iostream>
using namespace std;

class Processor {
    int a;
    float b;
public:
    void process(float num) {
        float square = num * num;
        a = static_cast<int>(num);
        b = num - a;
        int c = (a * a) + (b * b);
        cout << "Square: " << square << endl;
        cout << "Integer part: " << a << endl;
        cout << "Fractional part: " << b << endl;
        cout << "Sum of squares: " << c << endl;
    }
};

int main() {
    Processor obj;
    float num;
    cout << "Enter a float number: ";
    cin >> num;
    obj.process(num);
    return 0;
}