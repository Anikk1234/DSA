#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BSTFixer {
private:
    TreeNode *first, *middle, *last, *prev;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = nullptr;
        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};

// Utility function to print inorder traversal
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Example usage
int main() {
    /*
        Original BST:         Fixed BST:
            10                    10
           /  \                  /  \
         5     8               5    20
        / \                    / \
       2  20                 2   8
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(20); // Should be 8
    root->right = new TreeNode(20);       // Should be 8

    cout << "Before Fixing (Inorder): ";
    printInOrder(root);
    cout << endl;

    BSTFixer fixer;
    fixer.recoverTree(root);

    cout << "After Fixing (Inorder): ";
    printInOrder(root);
    cout << endl;

    return 0;
}
