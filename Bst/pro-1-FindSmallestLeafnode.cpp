#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = right = nullptr;
    }
};

Node *AddChild(Node *&node, int value)
{
    if (node == nullptr)
    {
        return new Node(value);
    }
    if (node->data > value)
    {
        node->left = AddChild(node->left, value);
    }
    else
    {
        node->right = AddChild(node->right, value);
    }
    return node;
}
void Inorder(Node *root, int &minvalue)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, minvalue);
    cout << root->data << " ";
    if (root->data < minvalue)
    {
        minvalue = root->data;
    }
    Inorder(root->right, minvalue);
}

int minvalue(Node *root)
{
    int minvalue = INT_MAX;
    Inorder(root, minvalue);
    return minvalue;
}

int main()
{
    Node *root = nullptr;
    cout << "Enter the value of child(-1 for stop insert):" << endl;
    int value;
    while (cin >> value && value != -1)
    {
        root = AddChild(root, value);
    }
    int ans = minvalue(root);
    cout << endl;
    cout << "Minleaf node is:" << ans << endl;

    return 0;
}