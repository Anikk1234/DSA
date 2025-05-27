//Problem: Finding the minimum cost to spread a rumor in connected components
//Description: Calculate the minimum cost to spread a rumor to all connected people.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<long long>& cost, long long& min_cost) {
    visited[node] = true;
    min_cost = min(min_cost, cost[node]);
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, cost, min_cost);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> cost(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    vector<bool> visited(n + 1, false);
    long long total_cost = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            long long min_cost = cost[i];
            dfs(i, graph, visited, cost, min_cost);
            total_cost += min_cost;
        }
    }
    
    cout << total_cost << endl;
    
    return 0;
}
