#include <iostream>
#include <algorithm> // For max()
using namespace std;

// Define the structure of a node in BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert a node in BST
Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// Search for a value in BST
bool search(Node* root, int key) {
    if (!root)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Find the node with the minimum value
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Find the node with the maximum value
Node* findMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (!root)
        return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// In-order traversal (Left, Root, Right)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Pre-order traversal (Root, Left, Right)
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order traversal (Left, Right, Root)
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Compute height of BST
int height(Node* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}

// Display menu
void menu() {
    cout << "\n=== Binary Search Tree Operations ===\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. In-order Traversal\n";
    cout << "5. Pre-order Traversal\n";
    cout << "6. Post-order Traversal\n";
    cout << "7. Find Minimum\n";
    cout << "8. Find Maximum\n";
    cout << "9. Tree Height\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Node* root = nullptr;
    int n, key, choice;

    // Initial input for creating BST
    cout << "Enter the number of keys to insert initially in BST: ";
    cin >> n;
    cout << "Enter " << n << " key(s): ";
    for (int i = 0; i < n; i++) {
        cin >> key;
        root = insert(root, key);
    }

    // Menu-driven operations
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> key;
                root = insert(root, key);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> key;
                cout << (search(root, key) ? "Found\n" : "Not found\n");
                break;
            case 4:
                cout << "In-order Traversal: ";
                inorder(root);
                cout << "\n";
                break;
            case 5:
                cout << "Pre-order Traversal: ";
                preorder(root);
                cout << "\n";
                break;
            case 6:
                cout << "Post-order Traversal: ";
                postorder(root);
                cout << "\n";
                break;
            case 7:
                if (root)
                    cout << "Minimum value: " << findMin(root)->data << "\n";
                else
                    cout << "Tree is empty.\n";
                break;
            case 8:
                if (root)
                    cout << "Maximum value: " << findMax(root)->data << "\n";
                else
                    cout << "Tree is empty.\n";
                break;
            case 9:
                cout << "Tree Height: " << height(root) << "\n";
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
