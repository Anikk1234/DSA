#include <iostream>
using namespace std;

// Tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find LCA in a BST
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (!root) return nullptr;

    // If both n1 and n2 are smaller, go left
    if (n1 < root->val && n2 < root->val)
        return findLCA(root->left, n1, n2);

    // If both n1 and n2 are greater, go right
    if (n1 > root->val && n2 > root->val)
        return findLCA(root->right, n1, n2);

    // Current node is the LCA
    return root;
}

// Sample tree builder for manual testing
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    return root;
}

// Example usage
int main() {
    /*
        Example BST:
                    20
                   /  \
                 8     22
                / \
              4   12
                 /  \
               10   14
    */
    TreeNode* root = nullptr;
    int nodes[] = {20, 8, 22, 4, 12, 10, 14};
    for (int val : nodes)
        root = insert(root, val);

    int n1 = 8, n2 = 14;
    TreeNode* lca = findLCA(root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
