// Problem: Checking if a graph can be colored with two colors such that no adjacent nodes have the same color
// Description: Determine if a graph is bipartite.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1);
    queue<int> q;
    
    for (int start = 0; start < n; start++) {
        if (color[start] != -1) continue; // Already processed
        
        color[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node]; // Alternate color
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // Same color for adjacent nodes
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int m;
        cin >> m;
        
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        if (isBipartite(graph, n)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    
    return 0;
}
