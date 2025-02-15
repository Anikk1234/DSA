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
        block.assign((n + blockSize - 1) / blockSize, INT_MAX);

        // Precompute block minimums
        for (int i = 0; i < n; i++)
            block[i / blockSize] = min(block[i / blockSize], arr[i]);
    }

    // Range Minimum Query
    int query(int L, int R) {
        int minVal = INT_MAX;

        while (L <= R) {
            // If L is at the beginning of a block and the entire block fits in [L, R]
            if (L % blockSize == 0 && L + blockSize - 1 <= R) {
                minVal = min(minVal, block[L / blockSize]);
                L += blockSize;  // Skip the whole block
            } else {
                minVal = min(minVal, arr[L]);
                L++;  // Move one element at a time
            }
        }
        return minVal;
    }

    // Update an element
    void update(int index, int value) {
        int blockIndex = index / blockSize;
        arr[index] = value;
        
        // Recompute block minimum
        int start = blockIndex * blockSize;
        int end = min(start + blockSize, n);
        block[blockIndex] = INT_MAX;
        for (int i = start; i < end; i++)
            block[blockIndex] = min(block[blockIndex], arr[i]);
    }
};

int main() {
    int n, q;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    SqrtDecomposition sqrtDecomp(arr);

    cin >> q;
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {  // Query for minimum in range [a, b]
            cout << sqrtDecomp.query(a, b) << endl;
        } else if (type == 2) {  // Update index a with value b
            sqrtDecomp.update(a, b);
        }
    }

    return 0;
}
