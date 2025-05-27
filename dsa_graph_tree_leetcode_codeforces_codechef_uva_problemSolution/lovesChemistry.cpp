// Problem: Finding the maximum possible product based on a graph structure
//Description: Calculate the maximum product possible based on a given undirected graph.

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    vector<bool> visited(n + 1, false);
    int components = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            components++;
        }
    }
    
    // The maximum value will be 2^(n-components)
    long long result = 1;
    for (int i = 0; i < n - components; i++) {
        result *= 2;
    }
    
    cout << result << endl;
    
    return 0;
}

