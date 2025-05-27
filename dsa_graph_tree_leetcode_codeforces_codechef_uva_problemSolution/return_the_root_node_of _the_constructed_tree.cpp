#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Tree Node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build the tree
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
                          int inStart, int inEnd, int& preIndex, 
                          unordered_map<int, int>& inorderMap) {
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = inorderMap[rootVal];

    root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex, inorderMap);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++)
        inorderMap[inorder[i]] = i;

    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, preIndex, inorderMap);
}

// Postorder traversal
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Driver code
int main() {
    vector<int> inorder1 = {1, 6, 8, 7};
    vector<int> preorder1 = {1, 6, 7, 8};
    TreeNode* root1 = buildTree(preorder1, inorder1);
    postorder(root1);
    cout << endl;

    vector<int> inorder2 = {3, 1, 4, 0, 2, 5};
    vector<int> preorder2 = {0, 1, 3, 4, 2, 5};
    TreeNode* root2 = buildTree(preorder2, inorder2);
    postorder(root2);
    cout << endl;

    vector<int> inorder3 = {2, 5, 4, 1, 3};
    vector<int> preorder3 = {1, 4, 5, 2, 3};
    TreeNode* root3 = buildTree(preorder3, inorder3);
    postorder(root3);
    cout << endl;

    return 0;
}
