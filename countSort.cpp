#include <bits/stdc++.h>
using namespace std;

void countSort() {
    int arr[] = {1, 6, 4, 8, 5, 3, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = arr[0];
    for (int i = 0; i < n; i++) {
        k = max(k, arr[i]);
    }

    vector<int> count(k + 1, 0);
    vector<int> output(n);

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
}

int main() {
    countSort();
    return 0;
}

