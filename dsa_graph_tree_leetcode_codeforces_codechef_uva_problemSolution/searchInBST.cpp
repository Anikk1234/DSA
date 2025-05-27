// Problem: Search for a value in a BST
// Description: Given the root node of a BST and a value, find the node in the BST that has the given value.

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

Node* InsertIntoBST(Node* Root, int Value) {
    if (Root == NULL) {
        return new Node(Value);
    }
    
    if (Value < Root->Value) {
        Root->Left = InsertIntoBST(Root->Left, Value);
    } else {
        Root->Right = InsertIntoBST(Root->Right, Value);
    }
    
    return Root;
}

Node* SearchBST(Node* Root, int Value) {
    // Base cases: root is null or root's value matches the target
    if (Root == NULL || Root->Value == Value) {
        return Root;
    }
    
    // If target value is less than root's value, search in left subtree
    if (Value < Root->Value) {
        return SearchBST(Root->Left, Value);
    }
    
    // If target value is greater than root's value, search in right subtree
    return SearchBST(Root->Right, Value);
}

int main() {
    // Create a sample BST
    Node* Root = NULL;
    Root = InsertIntoBST(Root, 4);
    Root = InsertIntoBST(Root, 2);
    Root = InsertIntoBST(Root, 7);
    Root = InsertIntoBST(Root, 1);
    Root = InsertIntoBST(Root, 3);
    
    int ValueToSearch = 2;
    Node* Result = SearchBST(Root, ValueToSearch);
    
    if (Result) {
        cout << "Found value " << Result->Value << " with children ";
        cout << (Result->Left ? to_string(Result->Left->Value) : "NULL") << " and ";
        cout << (Result->Right ? to_string(Result->Right->Value) : "NULL") << endl;
    } else {
        cout << "Value not found in the BST" << endl;
    }
    
    return 0;
}

