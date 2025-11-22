#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
  queue<int> q1, q2;

public:
  void push(int x) {
    cout << "Pushing " << x << endl;
    q2.push(x);
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    swap(q1, q2);
  }

  void pop() {
    if (q1.empty()) {
      cout << "Stack is Empty\n";
      return;
    }
    cout << "Popped " << q1.front() << endl;
    q1.pop();
  }

  void display() {
    cout << "Current Stack (top to bottom): ";
    queue<int> temp = q1;
    while (!temp.empty()) {
      cout << temp.front() << " ";
      temp.pop();
    }
    cout << endl;
  }
};

int main() {
  StackUsingQueue s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.display();
  s.pop();
  s.display();
  cout << endl;
  return 0;
}
