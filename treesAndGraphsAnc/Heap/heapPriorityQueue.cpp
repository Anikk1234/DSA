#include <iostream>
#include <vector>
using namespace std;

// Max-Heap based Priority Queue
class MaxHeap {
    vector<int> heap;

    // Get parent index
    int parent(int i) { return (i - 1) / 2; }

    // Get left child index
    int leftChild(int i) { return 2 * i + 1; }

    // Get right child index
    int rightChild(int i) { return 2 * i + 2; }

    // Maintain heap after insertion
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    // Maintain heap after removal
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert element
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Remove max element
    void pop() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Get max element
    int top() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }
        return heap[0];
    }

    // Display the heap
    void display() {
        cout << "Current Heap: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;
    int choice, val;

    cout << "== Max Heap Priority Queue ==\n";

    do {
        cout << "\n1. Insert\n2. Remove Max\n3. Show Max\n4. Display Heap\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            pq.push(val);
            break;

        case 2:
            pq.pop();
            break;

        case 3:
            cout << "Max Element: " << pq.top() << endl;
            break;

        case 4:
            pq.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
