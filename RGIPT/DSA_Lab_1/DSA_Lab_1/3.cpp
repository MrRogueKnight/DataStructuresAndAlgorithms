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

    void insertAtStart(int value) {
        if (size < MAX_SIZE) {
            for (int i = size; i > 0; i--) {
                A[i] = A[i - 1];
            }
            A[0] = value;
            size++;
        }
    }

    void insertBefore(int beforeVal, int insertVal) {
        if (size >= MAX_SIZE) return;

        for (int i = 0; i < size; i++) {
            if (A[i] == beforeVal) {
                for (int j = size; j > i; j--) {
                    A[j] = A[j - 1];
                }
                A[i] = insertVal;
                size++;
                break;
            }
        }
    }
};

int main() {
    List list;

    for (int i = 1; i <= 10; i++) {
        list.insertAtEnd(i * 10);
    }
    list.insertAtStart(5);
    list.insertAtStart(6);
    list.insertAtStart(7);

    cout << "Before 3: ";
    list.print();

    list.insertBefore(40, 0);
    list.insertBefore(60, 0);
    list.insertBefore(90, 0);

    cout << "After 3: ";
    list.print();

    return 0;
}