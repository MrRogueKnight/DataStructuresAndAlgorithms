/*Q.3: Implement the Queue considering the dynamic array and perform the following operations:
(a) Insert the 26 real numbers, i.e., 10.0, 12.0,..., into the Queue
(b) Perform ten consecutive deletions into the Queue
*/

#include <iostream>
using namespace std;

class QueueArray {
private:
  double* arr;
  int capacity;
  int front, rear, count;

public:
  QueueArray(int cap = 10) {
    capacity = cap;
    arr = new double[capacity];
    front = 0;
    rear = -1;
    count = 0;
  }

  ~QueueArray() { delete[] arr; }

  void enqueue(double element) {
    if (count == capacity) {
      // Resize
      double* newArr = new double[capacity * 2];
      for (int i = 0; i < count; i++) newArr[i] = arr[(front + i) % capacity];
      delete[] arr;
      arr = newArr;
      front = 0;
      rear = count - 1;
      capacity *= 2;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = element;
    count++;
  }

  double dequeue() {
    if (isEmpty()) throw runtime_error("Queue is empty!");
    double val = arr[front];
    front = (front + 1) % capacity;
    count--;
    return val;
  }

  bool isEmpty() const { return count == 0; }

  void display() const {
    for (int i = 0; i < count; i++) {
      cout << arr[(front + i) % capacity] << " ";
    }
    cout << endl;
  }
};

int main() {
  cout << "Q.3: Queue (Dynamic Array)" << endl;
  QueueArray q;

  for (int i = 0; i < 26; i++) q.enqueue(10.0 + i * 2.0);

  cout << "Queue after inserting 26 elements:" << endl;
  q.display();

  cout << "Performing 10 dequeues:" << endl;
  for (int i = 0; i < 10; i++) cout << q.dequeue() << " ";
  cout << endl;

  cout << "Queue after deletions:" << endl;
  q.display();
}
