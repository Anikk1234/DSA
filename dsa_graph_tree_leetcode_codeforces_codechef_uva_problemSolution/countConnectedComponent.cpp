// Problem: Counting connected components that are complete graphs
// Description: Count the number of connected components in an undirected graph where each component forms a complete graph.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, component);
            }
        }
    }
    
    bool isComplete(vector<vector<int>>& graph, vector<int>& component) {
        int n = component.size();
        
        // Check if each node connects to every other node
        for (int node : component) {
            if (graph[node].size() != n - 1) {
                return false;
            }
        }
        
        return true;
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, graph, visited, component);
                
                if (isComplete(graph, component)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

