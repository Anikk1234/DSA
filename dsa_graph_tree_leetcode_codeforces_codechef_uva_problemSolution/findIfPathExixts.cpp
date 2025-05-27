// Problem: Checking if there's a path between two nodes in an undirected graph
//Description: Determine if it's possible to reach from a source node to a destination node in an undirected graph.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        
        // Build the adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // BFS to find path
        vector<bool> visited(n, false);
        queue<int> q;
        
        q.push(source);
        visited[source] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == destination) return true;
            
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return false;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << (sol.validPath(3, edges, 0, 2) ? "true" : "false") << endl;
    return 0;
}