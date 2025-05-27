#include <iostream>
#include <vector>
using namespace std;

// Binary Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Check if a node is a leaf
bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

// Add left boundary (excluding leaves)
void addLeftBoundary(TreeNode* node, vector<int>& res) {
    TreeNode* curr = node->left;
    while (curr) {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// Add all leaf nodes
void addLeaves(TreeNode* node, vector<int>& res) {
    if (!node) return;
    if (isLeaf(node)) {
        res.push_back(node->data);
        return;
    }
    addLeaves(node->left, res);
    addLeaves(node->right, res);
}

// Add right boundary in bottom-up (excluding leaves)
void addRightBoundary(TreeNode* node, vector<int>& res) {
    TreeNode* curr = node->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    // Add in reverse order
    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back(temp[i]);
}

// Main boundary traversal function
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

// Example usage
int main() {
    // Build sample tree for test: 
    // root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = boundaryTraversal(root);
    cout << "Boundary Traversal: ";
    printVector(result);

    return 0;
}
