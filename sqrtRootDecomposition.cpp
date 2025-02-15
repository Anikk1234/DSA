#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 30000;
const int MAX_A = 1000000;
const int MAX_Q = 200000;

struct Query {
    int L, R, index;
};

// Mo's Algorithm Comparator
int blockSize;
bool compare(Query a, Query b) {
    if (a.L / blockSize != b.L / blockSize)
        return a.L / blockSize < b.L / blockSize;
    return (a.L / blockSize & 1) ? (a.R < b.R) : (a.R > b.R);
}

vector<int> moAlgorithm(vector<int>& arr, vector<Query>& queries) {
    int n = arr.size();
    int q = queries.size();
    vector<int> answers(q);
    vector<int> freq(MAX_A + 1, 0);
    
    blockSize = sqrt(n);
    sort(queries.begin(), queries.end(), compare);

    int currL = 0, currR = -1, distinctCount = 0;

    // Add function
    auto add = [&](int idx) {
        if (freq[arr[idx]] == 0) distinctCount++;
        freq[arr[idx]]++;
    };

    // Remove function
    auto remove = [&](int idx) {
        freq[arr[idx]]--;
        if (freq[arr[idx]] == 0) distinctCount--;
    };

    for (Query q : queries) {
        while (currL > q.L) add(--currL);
        while (currR < q.R) add(++currR);
        while (currL < q.L) remove(currL++);
        while (currR > q.R) remove(currR--);

        answers[q.index] = distinctCount;
    }

    return answers;
}

int main() {
    int n, q;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    cin >> q;
    vector<Query> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].L--; // Convert to 0-based indexing
        queries[i].R--;
        queries[i].index = i; // Store query index
    }

    vector<int> results = moAlgorithm(arr, queries);

    for (int res : results)
        cout << res << endl;

    return 0;
}
