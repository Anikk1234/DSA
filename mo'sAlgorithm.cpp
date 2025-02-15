#include <bits/stdc++.h>

using namespace std;

// Structure to store queries
struct Query {
    int L, R, index;
};

// Mo's algorithm comparator for sorting queries
int blockSize;
bool compare(Query a, Query b) {
    if (a.L / blockSize != b.L / blockSize)
        return a.L / blockSize < b.L / blockSize;
    return a.R < b.R;
}

// Mo's algorithm to process queries
vector<int> mosAlgorithm(vector<int>& arr, vector<Query>& queries) {
    int n = arr.size();
    int q = queries.size();
    vector<int> answers(q);
    
    // Sort queries using Mo’s ordering
    blockSize = sqrt(n);
    sort(queries.begin(), queries.end(), compare);

    int currL = 0, currR = -1, minValue = INT_MAX;
    vector<int> frequency(1000001, 0);  // Assuming numbers fit in [0, 10^6]

    // Function to add an element to the range
    auto add = [&](int idx) {
        minValue = min(minValue, arr[idx]);
    };

    // Function to remove an element from the range
    auto remove = [&](int idx) {
        // Recalculate minValue (if required)
        if (arr[idx] == minValue) {
            minValue = INT_MAX;
            for (int i = currL; i <= currR; i++)
                minValue = min(minValue, arr[i]);
        }
    };

    // Process each query
    for (Query q : queries) {
        while (currL > q.L) add(--currL);
        while (currR < q.R) add(++currR);
        while (currL < q.L) remove(currL++);
        while (currR > q.R) remove(currR--);

        answers[q.index] = minValue;  // Store result
    }

    return answers;
}

int main() {
    int N, Q;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) cin >> arr[i];

    cin >> Q;
    vector<Query> queries(Q);

    for (int i = 0; i < Q; i++) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].index = i;  // Store original index
    }

    vector<int> results = mosAlgorithm(arr, queries);

    for (int res : results)
        cout << res << endl;

    return 0;
}
