/*Q.4: Implement the Queue considering the singly linked list implementation and perform the following operations:
(a) Insert the 26 real numbers, i.e., 10.0, 12.0,..., into the Queue
(b) Perform ten consecutive deletions into the Queue*/

#include <iostream>
using namespace std;

struct QNode {
  double data;
  QNode* next;
  QNode(double d) : data(d), next(nullptr) {}
};

class QueueLinkedList {
private:
  QNode* front;
  QNode* rear;

public:
  QueueLinkedList() : front(nullptr), rear(nullptr) {}

  ~QueueLinkedList() {
    while (!isEmpty()) dequeue();
  }

  void enqueue(double element) {
    QNode* newNode = new QNode(element);
    if (isEmpty()) {
      front = rear = newNode;
    }
    else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  double dequeue() {
    if (isEmpty()) throw runtime_error("Queue is empty!");
    QNode* temp = front;
    double val = temp->data;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
    return val;
  }

  bool isEmpty() const { return front == nullptr; }

  void display() const {
    QNode* temp = front;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  cout << "Q.4: Queue (Linked List)" << endl;
  QueueLinkedList q;

  for (int i = 0; i < 26; i++) q.enqueue(10.0 + i * 2.0);

  cout << "Queue after inserting 26 elements:" << endl;
  q.display();

  cout << "Performing 10 dequeues:" << endl;
  for (int i = 0; i < 10; i++) cout << q.dequeue() << " ";
  cout << endl;

  cout << "Queue after deletions:" << endl;
  q.display();
}
