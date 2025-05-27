// Problem: Implement preorder traversal of an N-ary tree
// Description: Given the root of an N-ary tree, return the preorder traversal of its nodes' values.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int Value;
    vector<Node*> Children;

    Node() {}

    Node(int Value) {
        this->Value = Value;
    }

    Node(int Value, vector<Node*> Children) {
        this->Value = Value;
        this->Children = Children;
    }
};

void PreorderHelper(Node* Root, vector<int>& Result) {
    if (Root == NULL) {
        return;
    }
    
    // Process current node first
    Result.push_back(Root->Value);
    
    // Then process all children
    for (Node* Child : Root->Children) {
        PreorderHelper(Child, Result);
    }
}

vector<int> Preorder(Node* Root) {
    vector<int> Result;
    PreorderHelper(Root, Result);
    return Result;
}

int main() {
    // Create a sample N-ary tree
    Node* Root = new Node(1);
    Node* Child1 = new Node(3);
    Node* Child2 = new Node(2);
    Node* Child3 = new Node(4);
    Node* Grandchild1 = new Node(5);
    Node* Grandchild2 = new Node(6);
    
    Child1->Children = {Grandchild1, Grandchild2};
    Root->Children = {Child1, Child2, Child3};
    
    vector<int> Result = Preorder(Root);
    
    cout << "Preorder traversal: ";
    for (int Val : Result) {
        cout << Val << " ";
    }
    cout << endl;
    
    return 0;
}

