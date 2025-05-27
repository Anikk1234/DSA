//Problem: Finding the time for all nodes to receive a signal
//Description: Calculate the time it takes for all nodes to receive a signal sent from a given node.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
        }
        
        // Dijkstra's algorithm
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (d > dist[node]) continue;
            
            for (auto& neighbor : graph[node]) {
                int next = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[next] > dist[node] + weight) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        
        int max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; // Some node is unreachable
            max_time = max(max_time, dist[i]);
        }
        
        return max_time;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << sol.networkDelayTime(times, 4, 2) << endl;  // Output: 2
    return 0;
}

