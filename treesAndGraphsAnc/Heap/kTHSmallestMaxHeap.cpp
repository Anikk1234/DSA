#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthSmallest(vector<int>& nums, int K) {
    // Max Heap: largest element on top
    priority_queue<int> maxHeap;

    for (int num : nums) {
        maxHeap.push(num);
        // Keep only K smallest elements
        if (maxHeap.size() > K)
            maxHeap.pop();  // remove largest among them
    }

    // Root is the Kth smallest
    return maxHeap.top();
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
        int result = findKthSmallest(nums, K);
        cout << "The " << K << "th smallest element is: " << result << endl;
    } else {
        cout << "Invalid K!\n";
    }

    return 0;
}
