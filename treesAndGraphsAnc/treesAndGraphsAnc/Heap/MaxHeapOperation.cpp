#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to maintain the max-heap property by "bubbling down"
void heapify(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child is larger than root
    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }

    // Check if right child is larger than largest so far
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

// Function to build a max-heap from an unsorted array
void buildHeap(vector<int>& heap) {
    int n = heap.size();
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(heap, n, i);
    }
}

// Function to insert a new element into the heap
void insert(vector<int>& heap, int value) {
    // Insert the new element at the end of the heap
    heap.push_back(value);
    int i = heap.size() - 1;
    
    // "Bubble up" the new element to maintain the heap property
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete any element in the heap
void deleteNode(vector<int>& heap, int value) {
    int n = heap.size();
    if (n == 0) return;

    // Find the index of the node to delete
    int indexToDelete = -1;
    for (int i = 0; i < n; ++i) {
        if (heap[i] == value) {
            indexToDelete = i;
            break;
        }
    }

    // If the value is not found
    if (indexToDelete == -1) {
        cout << "Value not found in heap." << endl;
        return;
    }

    // Replace the node to be deleted with the last node
    heap[indexToDelete] = heap[n - 1];
    heap.pop_back(); // Remove the last element

    // Heapify the affected subtree
    heapify(heap, heap.size(), indexToDelete);
}

// Function to print the heap in level-order traversal
void printLevelOrder(const vector<int>& heap) {
    int n = heap.size();
    if (n == 0) {
        cout << "Heap is empty!" << endl;
        return;
    }

    // Using a queue to perform level-order traversal
    queue<int> q;
    q.push(0);  // Start with the root node (index 0)

    while (!q.empty()) {
        int index = q.front();
        q.pop();
        cout << heap[index] << " ";

        // Push the left child and right child indices into the queue
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n) {
            q.push(left);
        }
        if (right < n) {
            q.push(right);
        }
    }
    cout << endl;
}

int main() {
    vector<int> heap;
    int n, value, choice;

    cout << "Enter the number of elements to build the heap: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        heap.push_back(value);
    }

    buildHeap(heap);
    cout << "Max-Heap after building: ";
    printLevelOrder(heap);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete a specific element\n";
        cout << "3. Print the heap in level-order\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                insert(heap, value);
                cout << "Max-Heap after insertion: ";
                printLevelOrder(heap);
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                deleteNode(heap, value);
                cout << "Max-Heap after deletion: ";
                printLevelOrder(heap);
                break;

            case 3:
                cout << "Current Max-Heap in level-order: ";
                printLevelOrder(heap);
                break;

            case 4:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
