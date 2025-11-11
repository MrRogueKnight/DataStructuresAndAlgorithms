/*
Q.2: Implement the stack considering the singly linked list implementation and perform the following operations:
(a) Insert the 26 Alphabets, i.e., "A"...."Z", into the stack
(b) Perform ten consecutive deletions into the stack
*/

#include <iostream>
using namespace std;

struct Node {
  char data;
  Node* next;
  Node(char d) : data(d), next(nullptr) {}
};

class StackLinkedList {
private:
  Node* topNode;

public:
  StackLinkedList() : topNode(nullptr) {}

  ~StackLinkedList() {
    while (!isEmpty()) pop();
  }

  void push(char element) {
    Node* newNode = new Node(element);
    newNode->next = topNode;
    topNode = newNode;
  }

  char pop() {
    if (isEmpty()) throw runtime_error("Stack is empty!");
    Node* temp = topNode;
    char val = temp->data;
    topNode = topNode->next;
    delete temp;
    return val;
  }

  bool isEmpty() const {
    return topNode == nullptr;
  }

  void display() const {
    Node* temp = topNode;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  cout << "Q.2: Stack (Linked List)" << endl;
  StackLinkedList s;

  for (char c = 'A'; c <= 'Z'; c++) s.push(c);

  cout << "Stack after inserting A-Z:" << endl;
  s.display();

  cout << "Performing 10 pops:" << endl;
  for (int i = 0; i < 10; i++) cout << s.pop() << " ";
  cout << endl;

  cout << "Stack after deletions:" << endl;
  s.display();
}
