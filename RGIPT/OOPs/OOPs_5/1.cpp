#include <iostream>
using namespace std;

class SerialObject {
private:
    static int count;
    int serialNumber;

public:
    SerialObject() {
        count++;
        serialNumber = count;
    }
    
    void reportSerial() {
        cout << "I am object number " << serialNumber << endl;
    }
};

int SerialObject::count = 0;

int main() {
    SerialObject obj1;
    SerialObject obj2;
    SerialObject obj3;
    
    obj1.reportSerial();
    obj2.reportSerial();
    obj3.reportSerial();
    
    return 0;
}
