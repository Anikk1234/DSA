#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Find path from root to target node and store nodes in path vector
bool findPath(TreeNode* root, int target, vector<TreeNode*>& path) {
    if (!root) return false;

    path.push_back(root);

    if (root->val == target)
        return true;

    if (findPath(root->left, target, path) || findPath(root->right, target, path))
        return true;

    path.pop_back(); // backtrack
    return false;
}

// Return sum of nodes at depth 'k' from current node
int sumAtDepth(TreeNode* node, int k) {
    if (!node) return 0;
    if (k == 0) return node->val;
    return sumAtDepth(node->left, k - 1) + sumAtDepth(node->right, k - 1);
}

// Main function to find total sum of nodes at distance k from target
int targetDistanceSum(TreeNode* root, int target, int k) {
    vector<TreeNode*> path;
    if (!findPath(root, target, path)) {
        cout << "Target node not found.\n";
        return 0;
    }

    int totalSum = 0;
    TreeNode* block = nullptr; // Block previously traversed subtree

    // Traverse from target up to root, computing valid subtree sums
    for (int i = path.size() - 1; i >= 0; --i) {
        TreeNode* current = path[i];
        int distFromTarget = path.size() - 1 - i;

        if (distFromTarget > k) break;

        if (distFromTarget == k) {
            totalSum += current->val;
        } else {
            // Exclude the subtree that leads back to the target
            if (current->left != block)
                totalSum += sumAtDepth(current->left, k - distFromTarget - 1);
            if (current->right != block)
                totalSum += sumAtDepth(current->right, k - distFromTarget - 1);
        }

        block = current;
    }

    return totalSum;
}

// ---------- MAIN FUNCTION ----------
int main() {
    TreeNode* root = nullptr;
    int n;

    cout << "Enter number of nodes in BST: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int target, k;
    cout << "Enter target node value: ";
    cin >> target;
    cout << "Enter distance k: ";
    cin >> k;

    int result = targetDistanceSum(root, target, k);
    cout << "Sum of nodes at distance " << k << " from target " << target << " is: " << result << endl;

    return 0;
}
