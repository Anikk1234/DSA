#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int minCostToConnectHouses(vector<vector<int>>& houses) {
    int n = houses.size();
    vector<bool> inMST(n, false);     // Track included houses
    vector<int> minDist(n, INT_MAX);  // Min cost to connect each house
    minDist[0] = 0;

    // Min-Heap: (cost, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // Start from house 0

    int totalCost = 0;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalCost += cost;

        // Update costs of connecting to remaining houses
        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                    pq.push({dist, v});
                }
            }
        }
    }

    return totalCost;
}

int main() {
    vector<vector<int>> houses1 = {{0, 7}, {0, 9}, {20, 7}, {30, 7}, {40, 70}};
    cout << "Output 1: " << minCostToConnectHouses(houses1) << endl;  // Expected: 105

    vector<vector<int>> houses2 = {{4, 12}, {15, 20}, {17, 0}};
    cout << "Output 2: " << minCostToConnectHouses(houses2) << endl;  // Expected: 41

    return 0;
}
