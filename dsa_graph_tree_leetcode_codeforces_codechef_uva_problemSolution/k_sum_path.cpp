#include <iostream>
#include <unordered_map>
using namespace std;

// Tree node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function
int dfs(TreeNode* node, long long currSum, int k, unordered_map<long long, int>& prefixSum) {
    if (!node) return 0;

    currSum += node->val;
    int count = 0;

    // Check if there's a prefix sum such that currSum - prefix = k
    if (prefixSum.find(currSum - k) != prefixSum.end()) {
        count += prefixSum[currSum - k];
    }

    // Add current prefix sum to map
    prefixSum[currSum]++;

    // Recurse left and right
    count += dfs(node->left, currSum, k, prefixSum);
    count += dfs(node->right, currSum, k, prefixSum);

    // Backtrack
    prefixSum[currSum]--;

    return count;
}

int pathSum(TreeNode* root, int k) {
    unordered_map<long long, int> prefixSum;
    prefixSum[0] = 1;  // To handle paths starting from root
    return dfs(root, 0, k, prefixSum);
}

// Example usage
int main() {
    /*
        Tree:
            1
           / \
          2   3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    int k1 = 3;
    cout << "Number of paths with sum " << k1 << ": " << pathSum(root, k1) << endl;

    /*
        Tree:
              10
             /  \
            5   -3
           / \    \
          3   2    11
         / \   \
        3  -2   1
    */
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(-3);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(2);
    root2->right->right = new TreeNode(11);
    root2->left->left->left = new TreeNode(3);
    root2->left->left->right = new TreeNode(-2);
    root2->left->right->right = new TreeNode(1);

    int k2 = 8;
    cout << "Number of paths with sum " << k2 << ": " << pathSum(root2, k2) << endl;

    return 0;
}
