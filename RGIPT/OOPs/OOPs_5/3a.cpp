#include <iostream>
using namespace std;

int main() {
    int studentClass, failedSubjects, graceMarks = 0;
    
    cout << "Enter the class obtained (1/2/3): ";
    cin >> studentClass;
    
    cout << "Enter number of subjects failed: ";
    cin >> failedSubjects;
    
    switch(studentClass) {
        case 1:
            if(failedSubjects <= 3)
                graceMarks = 5 * failedSubjects;
            else
                graceMarks = 0;
            break;
            
        case 2:
            if(failedSubjects <= 2)
                graceMarks = 4 * failedSubjects;
            else
                graceMarks = 0;
            break;
            
        case 3:
            if(failedSubjects <= 1)
                graceMarks = 5 * failedSubjects;
            else
                graceMarks = 0;
            break;
            
        default:
            cout << "Invalid class entered" << endl;
            return 1;
    }
    
    if(graceMarks > 0)
        cout << "Grace marks awarded: " << graceMarks << endl;
    else
        cout << "No grace marks awarded" << endl;
    
    return 0;
}
