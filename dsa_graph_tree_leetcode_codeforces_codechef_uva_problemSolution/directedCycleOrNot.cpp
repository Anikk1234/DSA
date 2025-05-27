#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack)) return true;
        } else if (recStack[neighbor]) {
            return true; // Cycle found
        }
    }

    recStack[node] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]); // Directed edge u -> v
    }

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) return true;
        }
    }

    return false;
}

int main() {
    int V1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};
    cout << "Output 1: " << (isCyclic(V1, edges1) ? "true" : "false") << endl;

    int V2 = 4;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << "Output 2: " << (isCyclic(V2, edges2) ? "true" : "false") << endl;

    return 0;
}
