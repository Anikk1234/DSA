#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int K) {
    // Min heap: smallest element at the top
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        // Keep only K elements in the heap
        if (minHeap.size() > K)
            minHeap.pop();
    }

    // Top of minHeap is the Kth largest
    return minHeap.top();
}

int main() {
    int n, K;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << "Enter value of K: ";
    cin >> K;

    if (K > 0 && K <= n) {
        int result = findKthLargest(nums, K);
        cout << "The " << K << "th largest element is: " << result << endl;
    } else {
        cout << "Invalid K!\n";
    }

    return 0;
}
