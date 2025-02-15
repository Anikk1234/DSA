#include <bits/stdc++.h>

using namespace std;

class SqrtDecomposition {
    vector<int> arr, block;
    int blockSize, n;

public:
    // Constructor: Initialize data structures
    SqrtDecomposition(vector<int>& input) {
        n = input.size();
        blockSize = sqrt(n);
        arr = input;
        block.resize((n + blockSize - 1) / blockSize, 0);

        // Precompute block sums
        for (int i = 0; i < n; i++)
            block[i / blockSize] += arr[i];
    }

    // Range sum query
    int query(int left, int right) {
        int sum = 0;

        while (left <= right) {
            // If within a full block, add the whole block sum
            if (left % blockSize == 0 && left + blockSize - 1 <= right) {
                sum += block[left / blockSize];
                left += blockSize;
            }
            // Otherwise, add individual elements
            else {
                sum += arr[left];
                left++;
            }
        }

        return sum;
    }

    // Update an element
    void update(int index, int value) {
        int blockIndex = index / blockSize;
        block[blockIndex] += value - arr[index];  // Update block sum
        arr[index] = value;  // Update actual array
    }
};

// Driver function
int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SqrtDecomposition sqrtDecomp(input);

    cout << "Sum of range [1, 7]: " << sqrtDecomp.query(1, 7) << endl;  // Output: 35
    sqrtDecomp.update(3, 10);  // Update arr[3] = 10
    cout << "Sum of range [1, 7] after update: " << sqrtDecomp.query(1, 7) << endl;  // Output: 41

    return 0;
}
