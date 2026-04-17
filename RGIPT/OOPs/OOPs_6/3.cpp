#include <iostream>
using namespace std;

class employee {
public:
    string name;
    int id;
    employee(string n, int i) { name = n; id = i; }
    void show() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class employee2 : public employee {
public:
    double compensation;
    enum period { hourly, weekly, monthly } pay_period;
    employee2(string n, int i, double c, period p) : employee(n, i) {
        compensation = c;
        pay_period = p;
    }
    void display() {
        show();
        cout << "Compensation: " << compensation << endl;
        cout << "Pay Period: ";
        if (pay_period == hourly) cout << "Hourly";
        else if (pay_period == weekly) cout << "Weekly";
        else cout << "Monthly";
        cout << endl;
    }
};

int main() {
    employee2 e("John", 101, 5000.75, employee2::monthly);
    e.display();
    return 0;
}
