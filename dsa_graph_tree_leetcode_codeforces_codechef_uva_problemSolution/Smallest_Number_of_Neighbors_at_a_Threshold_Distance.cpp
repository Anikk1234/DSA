#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Initialize distances
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall: compute all-pairs shortest distances
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int minReachable = INT_MAX;
    int cityWithMinReach = -1;

    // Count reachable cities for each city
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && dist[i][j] <= distanceThreshold)
                count++;
        }
        // Update the city if it has fewer or equal reachable cities and a higher index
        if (count <= minReachable) {
            minReachable = count;
            cityWithMinReach = i;
        }
    }

    return cityWithMinReach;
}

int main() {
    vector<vector<int>> edges1 = {
        {0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}
    };
    int n1 = 4, m1 = 4, threshold1 = 4;
    cout << "Output 1: " << findCity(n1, m1, edges1, threshold1) << endl; // Expected: 3

    vector<vector<int>> edges2 = {
        {0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}
    };
    int n2 = 5, m2 = 6, threshold2 = 2;
    cout << "Output 2: " << findCity(n2, m2, edges2, threshold2) << endl; // Expected: 0

    return 0;
}
