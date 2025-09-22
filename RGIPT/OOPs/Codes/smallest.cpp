#include <iostream>
using namespace std;

int main() {
    int n, num, smallest;
    cout << "Enter how many numbers: ";
    cin >> n;

    cout << "Enter 1st number : ";
    cin >> smallest;  // take first number as smallest

    for (int i = 2; i <= n; i++) {
        cout << "Enter next number : ";
        cin >> num;
        if (num < smallest) {
            smallest = num;
        }
    }

    cout << "Smallest number: " << smallest << endl;
    return 0;
}



/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "How many numbers do you want to enter? ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int smallest = *min_element(nums.begin(), nums.end());

    cout << "Smallest number: " << smallest << endl;
    return 0;
}
*/
