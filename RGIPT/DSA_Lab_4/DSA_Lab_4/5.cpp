/*
Q.5: Write a program to check whether the input arithmetic expression has balanced symbols/brackets or not (Application of stack)? Show your output for the following test cases:
(a) [{(a+b)/(a-b)}+{{d*(e+f)}]
(b) 
[{(a+b)/(a-b)+(d*f)}+{{d*(e+f)}}]
*/
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
  char* arr;
  int capacity, topIndex;

public:
  Stack(int cap = 10) {
    capacity = cap;
    arr = new char[capacity];
    topIndex = -1;
  }

  ~Stack() { delete[] arr; }

  void push(char c) {
    if (topIndex == capacity - 1) {
      char* newArr = new char[capacity * 2];
      for (int i = 0; i <= topIndex; i++) newArr[i] = arr[i];
      delete[] arr;
      arr = newArr;
      capacity *= 2;
    }
    arr[++topIndex] = c;
  }

  char pop() {
    if (isEmpty()) throw runtime_error("Stack underflow!");
    return arr[topIndex--];
  }

  bool isEmpty() const { return topIndex == -1; }
};

bool isBalanced(const string& expr) {
  Stack s;
  for (char c : expr) {
    if (c == '(' || c == '[' || c == '{') {
      s.push(c);
    }
    else if (c == ')') {
      if (s.isEmpty() || s.pop() != '(') return false;
    }
    else if (c == ']') {
      if (s.isEmpty() || s.pop() != '[') return false;
    }
    else if (c == '}') {
      if (s.isEmpty() || s.pop() != '{') return false;
    }
  }
  return s.isEmpty();
}

int main() {
  cout << "Q.5: Balanced Symbols Check" << endl;

  string expr1 = "[{(a+b)/(a-b)}+{{d*(e+f)}]";
  string expr2 = "[{(a+b)/(a-b)+(d*f)}+{{d*(e+f)}}]";

  cout << "Expression (a): " << expr1 << " -> "
    << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;

  cout << "Expression (b): " << expr2 << " -> "
    << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
}
