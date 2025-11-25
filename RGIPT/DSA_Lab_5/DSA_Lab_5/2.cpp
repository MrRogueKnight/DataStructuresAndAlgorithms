#include <iostream>
#include <stack>

class QueueUsingStack {
private:
  std::stack<int> s1;
  std::stack<int> s2;

public:
  void enqueue(int x) {
    std::cout << "Enqueue: " << x << std::endl;
    s1.push(x);
  }

  int dequeue() {
    if (s1.empty() && s2.empty()) {
      std::cout << "Queue is empty." << std::endl;
      return -1;
    }

    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int dequeued_val = s2.top();
    s2.pop();
    std::cout << "Dequeued: " << dequeued_val << std::endl;
    return dequeued_val;
  }

  void display() {
    std::stack<int> temp_s2 = s2;
    std::stack<int> temp_s1 = s1;
    std::cout << "Current Queue (front to rear): ";

    while (!temp_s2.empty()) {
      std::stack<int> display_temp;
      while (!temp_s2.empty()) {
        display_temp.push(temp_s2.top());
        temp_s2.pop();
      }
      while (!display_temp.empty()) {
        std::cout << display_temp.top() << " ";
        display_temp.pop();
      }
    }

    if (!s1.empty()) {
      std::stack<int> display_s1_temp;
      while (!temp_s1.empty()) {
        display_s1_temp.push(temp_s1.top());
        temp_s1.pop();
      }
      while (!display_s1_temp.empty()) {
        std::cout << display_s1_temp.top() << " ";
        display_s1_temp.pop();
      }
    }
    std::cout << std::endl;
  }
};

int main() {
  QueueUsingStack q1;
  std::cout << "Test Case 1" << std::endl;
  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  q1.display();
  q1.dequeue();
  q1.display();
  q1.enqueue(40);
  q1.dequeue();
  q1.display();

  std::cout << "\nTest Case 2 " << std::endl;
  QueueUsingStack q2;
  q2.enqueue(5);
  q2.enqueue(15);
  q2.dequeue();
  q2.enqueue(25);
  q2.dequeue();
  q2.dequeue();

  return 0;
}
