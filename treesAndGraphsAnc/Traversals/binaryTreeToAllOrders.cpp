#include <iostream>
#include <queue>
using namespace std;

// Binary Tree Node Definition
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// Traversal Functions
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Function to build tree from user input (level order)
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

int main() {
    cout << "==== Binary Tree Input ====" << endl;
    TreeNode* root = buildTree();

    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
