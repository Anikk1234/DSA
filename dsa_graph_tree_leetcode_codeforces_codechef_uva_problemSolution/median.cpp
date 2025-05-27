#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
    
    Info(bool isB, int s, int minV, int maxV) 
        : isBST(isB), size(s), minVal(minV), maxVal(maxV) {}
};

class Solution {
public:
    int maxSizeBST = 0;
    
    Info largestBSTSubtreeHelper(TreeNode* root) {
        if (!root) return Info(true, 0, INT_MAX, INT_MIN);
        
        Info left = largestBSTSubtreeHelper(root->left);
        Info right = largestBSTSubtreeHelper(root->right);
        
        // Check if current subtree is BST
        if (left.isBST && right.isBST &&
            root->val > left.maxVal && root->val < right.minVal) {
            int currSize = left.size + right.size + 1;
            maxSizeBST = max(maxSizeBST, currSize);
            int currMin = min(left.minVal, root->val);
            int currMax = max(right.maxVal, root->val);
            return Info(true, currSize, currMin, currMax);
        }
        
        return Info(false, 0, 0, 0);
    }
    
    int largestBSTSubtree(TreeNode* root) {
        maxSizeBST = 0;
        largestBSTSubtreeHelper(root);
        return maxSizeBST;
    }
};

// Utility to build tree manually for testing
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    /*
      Tree: 
           5
          / \
         2   4
        / \
       1   3
    */
    TreeNode* root1 = newNode(5);
    root1->left = newNode(2);
    root1->right = newNode(4);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    
    Solution sol;
    cout << "Largest BST size: " << sol.largestBSTSubtree(root1) << endl;  // Output: 3

    /*
       Tree:
           6
          / \
         7   3
          \  / \
          2 2   4
    */
    TreeNode* root2 = newNode(6);
    root2->left = newNode(7);
    root2->right = newNode(3);
    root2->left->right = newNode(2);
    root2->right->left = newNode(2);
    root2->right->right = newNode(4);

    cout << "Largest BST size: " << sol.largestBSTSubtree(root2) << endl;  // Output: 3

    return 0;
}
