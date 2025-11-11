/*
Q.1: Implement the stack considering the dynamic array and perform the following operations:
(a) Insert the 26 Alphabets, i.e., "A"...."Z", into the stack
(b) Perform ten consecutive deletions into the stack */

#include <iostream>
using namespace std;

class StackArray {
private:
  char* arr;
  int capacity;
  int topIndex;

public:
  StackArray(int cap = 10) {
    capacity = cap;
    arr = new char[capacity];
    topIndex = -1;
  }

  ~StackArray() {
    delete[] arr;
  }

  void push(char element) {
    if (topIndex == capacity - 1) {
      char* newArr = new char[capacity * 2];
      for (int i = 0; i <= topIndex; i++) newArr[i] = arr[i];
      delete[] arr;
      arr = newArr;
      capacity *= 2;
    }
    arr[++topIndex] = element;
  }

  char pop() {
    if (isEmpty()) throw runtime_error("Stack is empty!");
    return arr[topIndex--];
  }

  bool isEmpty() const {
    return topIndex == -1;
  }

  void display() const {
    for (int i = 0; i <= topIndex; i++) cout << arr[i] << " ";
    cout << endl;
  }
};

int main() {
  cout << "Q.1: Stack (Dynamic Array)" << endl;
  StackArray s;

  for (char c = 'A'; c <= 'Z'; c++) s.push(c);

  cout << "Stack after inserting A-Z:" << endl;
  s.display();

  cout << "Performing 10 pops:" << endl;
  for (int i = 0; i < 10; i++) cout << s.pop() << " ";
  cout << endl;

  cout << "Stack after deletions:" << endl;
  s.display();
}
