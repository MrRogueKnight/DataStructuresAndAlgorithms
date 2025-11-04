#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int checkAVL(Node* root) {
    if (!root) return 0;
    int lh = checkAVL(root->left);
    if (lh == -1) return -1;
    int rh = checkAVL(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool isAVL(Node* root) {
    return checkAVL(root) != -1;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << (isAVL(root) ? "Given BST is an AVL Tree" : "Given BST is not an AVL Tree");
    return 0;
}
