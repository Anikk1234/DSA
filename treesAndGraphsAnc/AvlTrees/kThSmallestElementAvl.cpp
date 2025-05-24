#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val, height, size;
    Node *left, *right;

    Node(int v) {
        val = v;
        height = size = 1;
        left = right = nullptr;
    }
};

// Utility: Height
int h(Node* n) {
    return n ? n->height : 0;
}

// Utility: Size
int s(Node* n) {
    return n ? n->size : 0;
}

// Balance factor
int balance(Node* n) {
    return h(n->left) - h(n->right);
}

// Update height and size
void update(Node* n) {
    n->height = max(h(n->left), h(n->right)) + 1;
    n->size = s(n->left) + s(n->right) + 1;
}

// Right rotate
Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    update(y);
    update(x);
    return x;
}

// Left rotate
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    update(x);
    update(y);
    return y;
}

// Insert in AVL
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    else
        return node; // no duplicates

    update(node);
    int b = balance(node);

    if (b > 1 && key < node->left->val)
        return rotateRight(node);
    if (b < -1 && key > node->right->val)
        return rotateLeft(node);
    if (b > 1 && key > node->left->val) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (b < -1 && key < node->right->val) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Find k-th smallest element
int kthSmallest(Node* root, int k) {
    if (!root) return -1; // not found

    int leftSize = s(root->left);

    if (k == leftSize + 1)
        return root->val;
    else if (k <= leftSize)
        return kthSmallest(root->left, k);
    else
        return kthSmallest(root->right, k - leftSize - 1);
}

// Driver
int main() {
    Node* root = nullptr;
    int n, x, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Enter k to find k-th smallest element: ";
    cin >> k;

    int result = kthSmallest(root, k);
    if (result == -1)
        cout << "Invalid k.\n";
    else
        cout << k << "-th smallest element is: " << result << endl;

    return 0;
}
