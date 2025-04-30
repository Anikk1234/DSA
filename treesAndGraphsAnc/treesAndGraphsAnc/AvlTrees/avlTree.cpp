#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val, height;
    Node *left, *right;

    Node(int v) {
        val = v;
        height = 1;
        left = right = nullptr;
    }
};

int ll = 0, rr = 0, lr = 0, rl = 0;

// Height
int h(Node* n) {
    return n ? n->height : 0;
}

// Balance Factor
int balance(Node* n) {
    return h(n->left) - h(n->right);
}

// Update Height
void update(Node* n) {
    n->height = max(h(n->left), h(n->right)) + 1;
}

// Right Rotate (LL)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    update(y);
    update(x);
    ll++;
    return x;
}

// Left Rotate (RR)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    update(x);
    update(y);
    rr++;
    return y;
}

// Insert and balance
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    else return node; // no duplicates

    update(node);

    int b = balance(node);

    // LL
    if (b > 1 && key < node->left->val)
        return rotateRight(node);

    // RR
    if (b < -1 && key > node->right->val)
        return rotateLeft(node);

    // LR
    if (b > 1 && key > node->left->val) {
        node->left = rotateLeft(node->left);
        lr++;
        return rotateRight(node);
    }

    // RL
    if (b < -1 && key < node->right->val) {
        node->right = rotateRight(node->right);
        rl++;
        return rotateLeft(node);
    }

    return node;
}

// Preorder print
void preorder(Node* node) {
    if (!node) return;
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

int main() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* root = nullptr;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nRoot Node: " << root->val << endl;
    cout << "Height: " << root->height << endl;
    cout << "Rotations: " << (ll + rr + lr + rl) << endl;
    cout << "LL: " << ll << ", RR: " << rr << ", LR: " << lr << ", RL: " << rl << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    return 0;
}
