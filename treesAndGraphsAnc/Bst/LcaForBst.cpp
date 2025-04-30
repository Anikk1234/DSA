#include <iostream>
using namespace std;

// Define the structure of a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Helper function for inserting a node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);  // Insert in the left subtree
        } else if (value > node->data) {
            node->right = insert(node->right, value);  // Insert in the right subtree
        }
        return node;
    }

    // Helper function to find the LCA in a BST
    Node* findLCA(Node* node, int p, int q) {
        // Base case: If the node is null or matches p or q
        if (node == nullptr) return nullptr;
        
        // If both p and q are smaller, move to the left subtree
        if (p < node->data && q < node->data) {
            return findLCA(node->left, p, q);
        }

        // If both p and q are greater, move to the right subtree
        if (p > node->data && q > node->data) {
            return findLCA(node->right, p, q);
        }

        // Otherwise, we've found the split point where p and q are on different sides
        return node;
    }

public:
    BST() : root(nullptr) {}

    // Public function to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Public function to find the LCA of two nodes in the BST
    Node* findLCA(int p, int q) {
        return findLCA(root, p, q);
    }
};

int main() {
    BST tree;
    int n, value, p, q;

    // Taking user input for the number of nodes
    cout << "Enter the number of nodes to insert in the BST: ";
    cin >> n;

    // Inserting nodes into the BST
    cout << "Enter " << n << " values to insert into the BST: \n";
    for (int i = 0; i < n; ++i) {
        cin >> value;  // Read each value
        tree.insert(value);  // Insert the value into the BST
    }

    // Taking user input for the two nodes to find the LCA
    cout << "Enter the two nodes to find the LCA: ";
    cin >> p >> q;

    // Finding the LCA of the two nodes
    Node* lca = tree.findLCA(p, q);
    
    // Output the result
    if (lca != nullptr) {
        cout << "LCA of " << p << " and " << q << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}
