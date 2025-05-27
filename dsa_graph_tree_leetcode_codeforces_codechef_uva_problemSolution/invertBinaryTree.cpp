// Problem: Invert a binary tree
// Description: Given the root of a binary tree, invert the tree, and return its root.

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

Node* InvertTree(Node* Root) {
    if (Root == NULL) {
        return NULL;
    }
    
    // Swap the left and right subtrees
    Node* Temp = Root->Left;
    Root->Left = Root->Right;
    Root->Right = Temp;
    
    // Recursively invert the left and right subtrees
    InvertTree(Root->Left);
    InvertTree(Root->Right);
    
    return Root;
}

// Level order traversal to verify inversion
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
    // Create a sample tree
    Node *Root = NULL;
    Insert(Root, 4);
    Insert(Root, 2);
    Insert(Root, 7);
    Insert(Root, 1);
    Insert(Root, 3);
    Insert(Root, 6);
    Insert(Root, 9);
    
    cout << "Original tree: ";
    PrintLevelOrder(Root);
    
    Root = InvertTree(Root);
    
    cout << "Inverted tree: ";
    PrintLevelOrder(Root);
    
    return 0;
}
