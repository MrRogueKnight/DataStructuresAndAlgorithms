#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

class List {
private:
    int A[MAX_SIZE];
    int size;

public:
    List() : size(0) {}

    void print() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << A[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    void insertAtEnd(int value) {
        if (size < MAX_SIZE) {
            A[size++] = value;
        }
    }
};

int main() {
    List list;

    cout << "Before 1: ";
    list.print();

    for (int i = 1; i <= 10; i++) {
        list.insertAtEnd(i * 10);
    }

    cout << "After 1: ";
    list.print();

    return 0;
}