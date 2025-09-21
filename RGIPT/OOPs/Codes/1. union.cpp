#include <iostream>
using namespace std;
union Emp {
    int num;
    double sal;
};

int main() {
    Emp value;
    value.num = 2;
    cout << "Employee Number::" << value.num << "\nSalary is:: " << value.sal << endl;
    value.sal = 2000.0;
    cout<<"--------------------"<< endl;
    cout << "Employee Number::" << value.num << "\nSalary is:: " << value.sal << endl;
    cout<<"--------------------"<< endl;
    value.sal = 2000.0;
    cout << "Employee Number::" << value.num << "\nSalary is:: " << value.sal << endl;
    cout<<"--------------------"<< endl;
    value.num = 10.0;
    cout << "Employee Number::" << value.sal<< "\nSalary is:: " << value.num<< endl;
    cout<<"--------------------"<< endl;
    value.sal=5000.0;
    cout << "Employee Number::" << value.sal<< "\nSalary is:: " << value.num<< endl;
    cout<<"--------------------"<< endl;
    return 0;
}
