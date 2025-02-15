/*Given a sequence of n numbers a1, a2 ... an and a number of d-queries. A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct elements in the subsequence ai, ai+1 ... aj.

Input
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2 ... an (1 ≤ ai ≤ 106).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).
Output
For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1 ... aj in a single line.
 

Example
Input
5
1 1 2 1 3
3
1 5
2 4
3 5

Output
3
2
3 

*/

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
