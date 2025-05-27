// Problem: Detecting negative cycles in a directed graph
// Description: Determine if there's a negative cycle in a directed graph.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int from, to, weight;
};

bool hasNegativeCycle(int n, vector<Edge>& edges) {
    vector<int> dist(n, 0);
    
    // Bellman-Ford algorithm
    for (int i = 0; i < n - 1; i++) {
        for (const Edge& edge : edges) {
            if (dist[edge.to] > dist[edge.from] + edge.weight) {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }
    
    // Check for negative cycles
    for (const Edge& edge : edges) {
        if (dist[edge.to] > dist[edge.from] + edge.weight) {
            return true; // Negative cycle exists
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        }
        
        if (hasNegativeCycle(n, edges)) {
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
    }
    
    return 0;
}
