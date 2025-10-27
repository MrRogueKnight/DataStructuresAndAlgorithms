#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

int checkAVL(Node* root) {
    if (!root)
        return 0;
    int leftHeight = checkAVL(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = checkAVL(root->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool isAVL(Node* root) {
    return checkAVL(root) != -1;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 30);

    if (isAVL(root))
        cout << "The tree is an AVL tree.\n";
    else
        cout << "The tree is NOT an AVL tree.\n";

    return 0;
}
