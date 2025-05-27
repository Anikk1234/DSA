#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;               // Value of the node
    TreeNode* left;        // Pointer to left child
    TreeNode* right;       // Pointer to right child

    // Constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (key < root->val) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to find the Lowest Common Ancestor in a BST
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    // Traverse the BST
    while (root != nullptr) {
        if (p < root->val && q < root->val) {
            // Both values are in the left subtree
            root = root->left;
        } else if (p > root->val && q > root->val) {
            // Both values are in the right subtree
            root = root->right;
        } else {
            // Found the split point (one on each side or one is equal to root)
            return root;
        }
    }

    return nullptr; // In case one or both values are not present
}

int main() {
    TreeNode* root = nullptr;
    int n;

    // Input: Number of nodes
    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    // Input: Node values
    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    // Input: Two node values for which to find LCA
    int p, q;
    cout << "Enter two node values to find their LCA: ";
    cin >> p >> q;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is: " << lca->val << endl;
    } else {
        cout << "One or both values not found in the BST.\n";
    }

    return 0;
}
