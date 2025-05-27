#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    
    // Custom comparator for priority queue:
    // Order by frequency descending, then by value descending
    auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
        if (a.second == b.second)
            return a.first < b.first; // larger element first if freq tie
        return a.second < b.second;   // larger frequency first
    };
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    
    for (auto& it : freq) {
        pq.push(it);
    }
    
    vector<int> result;
    for (int i = 0; i < k && !pq.empty(); i++) {
        result.push_back(pq.top().first);
        pq.pop();
    }
    
    return result;
}

int main() {
    vector<int> arr1 = {3, 1, 4, 4, 5, 2, 6, 1};
    int k1 = 2;
    vector<int> res1 = topKFrequent(arr1, k1);
    for (int x : res1) cout << x << " ";
    cout << "\n";  // Output: 4 1

    vector<int> arr2 = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int k2 = 4;
    vector<int> res2 = topKFrequent(arr2, k2);
    for (int x : res2) cout << x << " ";
    cout << "\n";  // Output: 5 11 7 10

    return 0;
}
