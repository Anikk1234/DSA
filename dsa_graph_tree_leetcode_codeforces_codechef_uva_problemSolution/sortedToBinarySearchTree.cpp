// Problem: Create a height-balanced BST from a sorted array
// Description: Given an integer array sorted in ascending order, convert it to a height-balanced BST.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int Value;
    Node *Left;
    Node *Right;
    Node(int Value) {
        this->Value = Value;
        this->Left = NULL;
        this->Right = NULL;
    }
};

Node* BuildBST(vector<int>& Nums, int Left, int Right) {
    if (Left > Right) {
        return NULL;
    }
    
    // Choose the middle element as the root
    int Mid = Left + (Right - Left) / 2;
    Node* Root = new Node(Nums[Mid]);
    
    // Recursively build left and right subtrees
    Root->Left = BuildBST(Nums, Left, Mid - 1);
    Root->Right = BuildBST(Nums, Mid + 1, Right);
    
    return Root;
}

Node* SortedArrayToBST(vector<int>& Nums) {
    return BuildBST(Nums, 0, Nums.size() - 1);
}

// Inorder traversal to verify BST property
void InorderTraversal(Node* Root) {
    if (!Root) return;
    InorderTraversal(Root->Left);
    cout << Root->Value << " ";
    InorderTraversal(Root->Right);
}

int main() {
    vector<int> Nums = {-10, -3, 0, 5, 9};
    
    Node* Root = SortedArrayToBST(Nums);
    
    cout << "Inorder traversal of balanced BST: ";
    InorderTraversal(Root);
    cout << endl;
    
    return 0;
}

