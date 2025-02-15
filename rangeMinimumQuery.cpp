#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    // Build the segment tree
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INT_MAX); // Allocate enough space
        build(arr, 0, 0, n - 1);
    }

    // Recursive function to build the tree
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start]; // Leaf node
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]); // Store min value
        }
    }

    // Query the minimum in range [L, R]
    int query(int L, int R) {
        return queryHelper(0, 0, n - 1, L, R);
    }

    // Recursive helper function for querying
    int queryHelper(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return INT_MAX; // No overlap
        if (L <= start && end <= R) return tree[node]; // Complete overlap

        int mid = (start + end) / 2;
        int leftMin = queryHelper(2 * node + 1, start, mid, L, R);
        int rightMin = queryHelper(2 * node + 2, mid + 1, end, L, R);
        return min(leftMin, rightMin);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) cin >> arr[i];

    SegmentTree st(arr);

    int Q;
    cin >> Q;

    while (Q--) {
        int i, j;
        cin >> i >> j;
        cout << st.query(i, j) << endl;
    }

    return 0;
}
