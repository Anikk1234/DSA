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

    // Helper function for in-order traversal to find the Kth smallest element
    void inorder(Node* node, int& count, int k, int& result) {
        // Base case: If the node is null, return
        if (node == nullptr) {
            return;
        }

        // Recur on the left subtree
        inorder(node->left, count, k, result);

        // Increment count after visiting a node
        count++;

        // If count matches k, we've found the Kth smallest element
        if (count == k) {
            result = node->data;
            return;
        }

        // Recur on the right subtree
        inorder(node->right, count, k, result);
    }

public:
    BST() : root(nullptr) {}

    // Public function to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Public function to find the Kth smallest element in the BST
    int findKthSmallest(int k) {
        int count = 0;
        int result = -1;  // Initialize result with a placeholder value
        inorder(root, count, k, result);
        return result;
    }
};

int main() {
    BST tree;
    int n, value, k;

    // Taking user input for the number of nodes
    cout << "Enter the number of nodes to insert in the BST: ";
    cin >> n;

    // Inserting nodes into the BST
    cout << "Enter " << n << " values to insert into the BST: \n";
    for (int i = 0; i < n; ++i) {
        cin >> value;  // Read each value
        tree.insert(value);  // Insert the value into the BST
    }

    // Taking user input for the value of k
    cout << "Enter the value of k to find the Kth smallest element: ";
    cin >> k;

    // Finding and outputting the Kth smallest element
    int kthSmallest = tree.findKthSmallest(k);
    if (kthSmallest != -1) {
        cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
    } else {
        cout << "The value of k is out of range.\n";
    }

    return 0;
}
