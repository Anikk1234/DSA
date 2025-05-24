#include <iostream>
#include <climits>  // For INT_MIN and INT_MAX
using namespace std;

// Define the structure of a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    // Helper function to check if the tree is a BST
    bool isBSTUtil(Node* node, int minValue, int maxValue) {
        // Base case: If the node is null, it's a valid BST (empty subtree)
        if (node == nullptr) {
            return true;
        }

        // If the node's data is out of the valid range, return false
        if (node->data < minValue || node->data > maxValue) {
            return false;
        }

        // Recursively check the left and right subtrees
        // Left subtree should have values less than the current node's data
        // Right subtree should have values greater than the current node's data
        return isBSTUtil(node->left, minValue, node->data - 1) && 
               isBSTUtil(node->right, node->data + 1, maxValue);
    }

public:
    // Constructor to initialize the root of the tree
    BinaryTree() : root(nullptr) {}

    // Public function to insert a node into the binary tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Helper function to insert a node in the binary tree
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Public function to check if the tree is a BST
    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};

int main() {
    BinaryTree tree;
    int n, value;

    // Taking user input for the number of nodes
    cout << "Enter the number of nodes to insert in the binary tree: ";
    cin >> n;

    // Inserting nodes into the binary tree
    cout << "Enter " << n << " values to insert into the binary tree: \n";
    for (int i = 0; i < n; ++i) {
        cin >> value;  // Read each value
        tree.insert(value);  // Insert the value into the binary tree
    }

    // Check if the tree is a BST and output the result
    if (tree.isBST()) {
        cout << "The tree is a Binary Search Tree (BST)." << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree (BST)." << endl;
    }

    return 0;
}
