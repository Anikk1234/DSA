#include <iostream>
#include <queue>
using namespace std;

// Define the structure of a binary tree node
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// Build binary tree using level order input
TreeNode* buildTree() {
    cout << "Enter root value (use '.' or '0' for null): ";
    char val;
    cin >> val;

    if (val == '.' || val == '0') return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        char leftVal, rightVal;
        cout << "Enter left child of " << curr->val << " (use '.' or '0' for null): ";
        cin >> leftVal;
        if (leftVal != '.' && leftVal != '0') {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->val << " (use '.' or '0' for null): ";
        cin >> rightVal;
        if (rightVal != '.' && rightVal != '0') {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

// Recursive function to find K-th node in inorder traversal
void findKthInorder(TreeNode* root, int K, int& count, char& result) {
    if (!root || result != '-') return;

    // Traverse left subtree
    findKthInorder(root->left, K, count, result);

    // Visit current node
    count++;
    if (count == K) {
        result = root->val;
        return;
    }

    // Traverse right subtree
    findKthInorder(root->right, K, count, result);
}

int main() {
    cout << "==== Binary Tree Input ====" << endl;
    TreeNode* root = buildTree();

    int K;
    cout << "\nEnter the value of K (1-based index): ";
    cin >> K;

    int count = 0;
    char result = '-'; // default: not found

    findKthInorder(root, K, count, result);

    if (result != '-') {
        cout << "The " << K << "-th node in inorder traversal is: " << result << endl;
    } else {
        cout << "Invalid K! Tree has fewer than " << K << " nodes.\n";
    }

    return 0;
}
