#include <bits/stdc++.h>
using namespace std;

void bucketSort() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<float> arr(n);
    cout << "Enter " << n << " elements between 0 and 1:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }

    cout << "Sorted elements:\n";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    bucketSort();
    return 0;
}

