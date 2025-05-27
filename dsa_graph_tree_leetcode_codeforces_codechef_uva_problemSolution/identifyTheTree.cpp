// Problem: Identify the structure of a tree based on its properties
// Description: Given the inorder and preorder traversal of a tree, determine the tree's structure.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char Value;
    Node *Left;
    Node *Right;
    Node(char Value) {
        this->Value = Value;
        this->Left = NULL;
        this->Right = NULL;
    }
};

Node* BuildTreeHelper(string& Preorder, int PreStart, int PreEnd,
                     string& Inorder, int InStart, int InEnd,
                     unordered_map<char, int>& InorderMap) {
    if (PreStart > PreEnd || InStart > InEnd) {
        return NULL;
    }
    
    char RootVal = Preorder[PreStart];
    Node* Root = new Node(RootVal);
    
    int InRoot = InorderMap[RootVal];
    int LeftSize = InRoot - InStart;
    
    Root->Left = BuildTreeHelper(Preorder, PreStart + 1, PreStart + LeftSize,
                               Inorder, InStart, InRoot - 1,
                               InorderMap);
    
    Root->Right = BuildTreeHelper(Preorder, PreStart + LeftSize + 1, PreEnd,
                                Inorder, InRoot + 1, InEnd,
                                InorderMap);
    
    return Root;
}

Node* BuildTree(string& Preorder, string& Inorder) {
    if (Preorder.empty() || Inorder.empty()) {
        return NULL;
    }
    
    // Create a map for O(1) lookups in inorder traversal
    unordered_map<char, int> InorderMap;
    for (int i = 0; i < Inorder.size(); i++) {
        InorderMap[Inorder[i]] = i;
    }
    
    return BuildTreeHelper(Preorder, 0, Preorder.size() - 1,
                          Inorder, 0, Inorder.size() - 1,
                          InorderMap);
}

void Postorder(Node* Root, string& Result) {
    if (Root == NULL) {
        return;
    }
    
    Postorder(Root->Left, Result);
    Postorder(Root->Right, Result);
    Result += Root->Value;
}

int main() {
    string Preorder, Inorder;
    
    while (cin >> Preorder >> Inorder) {
        Node* Root = BuildTree(Preorder, Inorder);
        
        string Result = "";
        Postorder(Root, Result);
        
        cout << Result << endl;
    }
    
    return 0;
}

// Basic complete binary tree implementation with level-order insertion
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

void Insert(Node *&Root, int Value) {
    Node *NewNode = new Node(Value);
    if (Root == NULL) {
        Root = NewNode;
        return;
    }

    queue<Node *> Q;
    Q.push(Root);

    while (!Q.empty()) {
        Node *Temp = Q.front();
        Q.pop();

        if (Temp->Left == NULL) {
            Temp->Left = NewNode;
            return;
        } else {
            Q.push(Temp->Left);
        }

        if (Temp->Right == NULL) {
            Temp->Right = NewNode;
            return;
        } else {
            Q.push(Temp->Right);
        }
    }
}

void PrintLevelOrder(Node *Root) {
    if (Root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node *> Q;
    Q.push(Root);

    while (!Q.empty()) {
        Node *Temp = Q.front();
        Q.pop();

        cout << Temp->Value << " ";

        if (Temp->Left) {
            Q.push(Temp->Left);
        }
        if (Temp->Right) {
            Q.push(Temp->Right);
        }
    }
    cout << endl;
}

int main() {
    Node *Root = NULL;

    Insert(Root, 1);
    Insert(Root, 2);
    Insert(Root, 3);
    Insert(Root, 4);
    Insert(Root, 5);
    Insert(Root, 6);
    Insert(Root, 7);

    cout << "Level-order traversal of the complete binary Tree: ";
    PrintLevelOrder(Root);

    return 0;
}