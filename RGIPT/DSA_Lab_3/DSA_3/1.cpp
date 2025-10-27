#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = tail = NULL;
        size = 0;
    }


    void insertEnd(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }


    void insertBegin(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }


    void insertBeforePos(int pos, char val) {
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position: " << pos << endl;
            return;
        }

        if (pos == 1) {
            insertBegin(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        size++;
    }


    void deleteBegin() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        delete temp;
        size--;
    }


    void deleteEnd() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete temp;
        size--;
    }


    void deletePos(int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid deletion position: " << pos << endl;
            return;
        }

        if (pos == 1) {
            deleteBegin();
            return;
        }

        if (pos == size) {
            deleteEnd();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }


    void display() {
        Node* temp = head;
        cout << "List (" << size << " elements): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() { return size; }
};

int main() {
    DoublyLinkedList dll;

    cout << "Inserting A-J at end: ";
    for (char ch = 'A'; ch <= 'J'; ch++) {
        dll.insertEnd(ch);
        cout << ch << " ";
    }
    cout << endl;
    dll.display();

    cout << "Inserting K-T at beginning: ";
    for (char ch = 'T'; ch >= 'K'; ch--) {
        dll.insertBegin(ch);
        cout << ch << " ";
    }
    cout << endl;
    dll.display();


    int positions[] = { 4, 8, 12, 16, 20 };
    char chars[] = { 'U', 'V', 'W', 'X', 'Y' };

    cout << "Inserting U-Y before positions 4,8,12,16,20: ";
    for (int i = 0; i < 5; i++) {
        dll.insertBeforePos(positions[i], chars[i]);
        cout << chars[i] << " before " << positions[i] << " ";
    }
    cout << endl;

    dll.insertEnd('Z');
    cout << "Inserting Z at end" << endl;

    cout << "Final list after all insertions: ";
    dll.display();


    int originalSize = dll.getSize();


    cout << "Deleting from beginning and end" << endl;
    dll.deleteBegin();
    dll.deleteEnd();
    dll.display();


    int delPositions[] = { 3, 6, 9, 12 };

    for (int i = 0; i < 4; i++) {

        int adjustedPos = delPositions[i] - i;
        cout << "Deleting position " << adjustedPos << " (original position " << delPositions[i] << ")" << endl;
        dll.deletePos(adjustedPos);
        dll.display();
    }

    dll.display();

    return 0;
}