#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

class List {
private:
    int A[MAX_SIZE];
    int size;

public:
    List() : A{}, size(0) {}

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

    void deleteAtStart() {
        if (size > 0) {
            for (int i = 0; i < size - 1; i++) {
                A[i] = A[i + 1];
            }
            size--;
        }
    }

    void deleteAtEnd() {
        if (size > 0) {
            size--;
        }
    }

    void deleteBeforeAndAfter(int value) {
        for (int i = 0; i < size; i++) {
            if (A[i] == value) {
                // Delete after
                if (i < size - 1) {
                    for (int j = i + 1; j < size - 1; j++) {
                        A[j] = A[j + 1];
                    }
                    size--;
                }

                // Delete before
                if (i > 0) {
                    for (int j = i - 1; j < size - 1; j++) {
                        A[j] = A[j + 1];
                    }
                    size--;
                    i--; 
                }
                break;
            }
        }
    }
};

int main() {
    List list;

    // Solution 1: Insert 10 integers at the end
    cout << "Before 1: ";
    list.print();
    for (int i = 1; i <= 10; i++) {
        list.insertAtEnd(i * 10);
    }
    cout << "After 1: ";
    list.print();
    cout << endl;

    // Solution 2: Insert 3 integers at the start
    cout << "Before 2: ";
    list.print();
    list.insertAtStart(5);
    list.insertAtStart(6);
    list.insertAtStart(7);
    cout << "After 2: ";
    list.print();
    cout << endl;

    // Solution 3: Insert 0 before first occurrences of 40, 60, 90
    cout << "Before 3: ";
    list.print();
    list.insertBefore(40, 0);
    list.insertBefore(60, 0);
    list.insertBefore(90, 0);
    cout << "After 3: ";
    list.print();
    cout << endl;

    // Solution 4: Delete from start and end
    cout << "Before 4: ";
    list.print();
    list.deleteAtStart();
    list.deleteAtEnd();
    cout << "After 4: ";
    list.print();
    cout << endl;

    // Solution 5: Delete before and after first occurrence of 70
    cout << "Before 5: ";
    list.print();
    list.deleteBeforeAndAfter(70);
    cout << "After 5: ";
    list.print();

    return 0;
}