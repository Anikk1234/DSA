#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Define structure for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Build tree from preorder and inorder
TreeNode* buildFromPreIn(vector<int>& preorder, int preStart, int preEnd,
                         vector<int>& inorder, int inStart, int inEnd,
                         unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart;

    root->left = buildFromPreIn(preorder, preStart + 1, preStart + numsLeft,
                                inorder, inStart, inRoot - 1, inMap);
    root->right = buildFromPreIn(preorder, preStart + numsLeft + 1, preEnd,
                                 inorder, inRoot + 1, inEnd, inMap);
    return root;
}

// Build tree from postorder and inorder
TreeNode* buildFromPostIn(vector<int>& postorder, int postStart, int postEnd,
                          vector<int>& inorder, int inStart, int inEnd,
                          unordered_map<int, int>& inMap) {
    if (postStart > postEnd || inStart > inEnd) return nullptr;

    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart;

    root->left = buildFromPostIn(postorder, postStart, postStart + numsLeft - 1,
                                 inorder, inStart, inRoot - 1, inMap);
    root->right = buildFromPostIn(postorder, postStart + numsLeft, postEnd - 1,
                                  inorder, inRoot + 1, inEnd, inMap);
    return root;
}

// Traversal functions
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

// Main driver
int main() {
    string inputType, outputType;
    int n;
    cout << "Enter input traversal type (preorder/inorder/postorder): ";
    cin >> inputType;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder, inorder, postorder;

    cout << "Enter " << inputType << " traversal: ";
    if (inputType == "preorder") {
        preorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> preorder[i];
    } else if (inputType == "inorder") {
        inorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> inorder[i];
    } else if (inputType == "postorder") {
        postorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> postorder[i];
    } else {
        cout << "Invalid input traversal type!" << endl;
        return 1;
    }

    // If only one traversal is given, we can't uniquely reconstruct the tree
    // So we ask for inorder if it's not provided
    if (inputType != "inorder") {
        cout << "Enter inorder traversal: ";
        inorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> inorder[i];
    }

    cout << "Enter desired output traversal type (preorder/inorder/postorder): ";
    cin >> outputType;

    // Build index map for inorder
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; ++i)
        inMap[inorder[i]] = i;

    TreeNode* root = nullptr;
    if (inputType == "preorder") {
        root = buildFromPreIn(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
    } else if (inputType == "postorder") {
        root = buildFromPostIn(postorder, 0, n - 1, inorder, 0, n - 1, inMap);
    }

    // Output desired traversal
    cout << "Result (" << outputType << "): ";
    if (outputType == "preorder") {
        printPreorder(root);
    } else if (outputType == "inorder") {
        printInorder(root);
    } else if (outputType == "postorder") {
        printPostorder(root);
    } else {
        cout << "Invalid output traversal type!" << endl;
    }

    cout << endl;
    return 0;
}
