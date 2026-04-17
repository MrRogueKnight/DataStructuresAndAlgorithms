#include <iostream>
#include <iomanip>
using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle() : degrees(0), minutes(0.0), direction('N') {}
    
    Angle(int deg, float min, char dir) : degrees(deg), minutes(min), direction(dir) {}
    
    void getAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N/S/E/W): ";
        cin >> direction;
    }
    
    void displayAngle() const {
        cout << degrees << (char)248 << fixed << setprecision(1) 
             << minutes << "' " << direction << endl;
    }
};

int main() {
    Angle angle1(149, 34.8, 'W');
    
    cout << "Initial angle: ";
    angle1.displayAngle();
    
    char choice;
    do {
        Angle userAngle;
        cout << "\nEnter angle details:" << endl;
        userAngle.getAngle();
        
        cout << "You entered: ";
        userAngle.displayAngle();
        
        cout << "\nEnter another angle? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');
    
    return 0;
}
