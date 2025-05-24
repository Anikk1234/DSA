#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a new value into the BST
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

// Function to compute the range sum in the BST
int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
        return 0;
    }

    // If node value is less than low, explore right subtree only
    if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    }

    // If node value is greater than high, explore left subtree only
    if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }

    // If node is within range, include its value and search both subtrees
    return root->val +
           rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
}

int main() {
    TreeNode* root = nullptr;
    int n;

    // Input number of nodes
    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    // Input node values
    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    // Input the range [low, high]
    int low, high;
    cout << "Enter the range (low and high): ";
    cin >> low >> high;

    // Calculate and display the range sum
    int sum = rangeSumBST(root, low, high);
    cout << "Range Sum between " << low << " and " << high << " = " << sum << endl;

    return 0;
}
