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

class AVLTree {
private:
    Node* root;

    // Helper function to get the height of a node
    int height(Node* node) {
        return node ? max(height(node->left), height(node->right)) + 1 : 0;
    }

    // Helper function to check the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // Helper function to check if the tree is a BST
    bool isBSTUtil(Node* node, int minVal, int maxVal) {
        if (node == nullptr) return true;

        // The current node's data must be in the range [minVal, maxVal]
        if (node->data < minVal || node->data > maxVal) {
            return false;
        }

        // Check the left and right subtrees with updated ranges
        return isBSTUtil(node->left, minVal, node->data - 1) &&
               isBSTUtil(node->right, node->data + 1, maxVal);
    }

    // Helper function to check if the tree is balanced and satisfies both BST and balance factor conditions
    bool isAVLUtil(Node* node) {
        // Base case: If the node is null, it's trivially balanced and a BST
        if (node == nullptr) return true;

        // Get the balance factor of the current node
        int balance = getBalance(node);

        // If the node is unbalanced, return false
        if (balance < -1 || balance > 1) {
            return false;
        }

        // Recursively check the left and right subtrees
        return isAVLUtil(node->left) && isAVLUtil(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    // Public function to insert a value into the AVL Tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Helper function to insert a value into the tree
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }

    // Public function to check if the tree is an AVL tree
    bool isAVLTree() {
        // Check if the tree is a BST and balanced
        return isBSTUtil(root, INT_MIN, INT_MAX) && isAVLUtil(root);
    }
};

int main() {
    AVLTree tree;
    int n, value;

    // Taking user input for the number of nodes
    cout << "Enter the number of nodes to insert in the binary tree: ";
    cin >> n;

    // Inserting nodes into the AVL tree
    cout << "Enter " << n << " values to insert into the binary tree: \n";
    for (int i = 0; i < n; ++i) {
        cin >> value;  // Read each value
        tree.insert(value);  // Insert the value into the tree
    }

    // Checking if the tree is an AVL tree
    if (tree.isAVLTree()) {
        cout << "The tree is an AVL tree." << endl;
    } else {
        cout << "The tree is NOT an AVL tree." << endl;
    }

    return 0;
}
