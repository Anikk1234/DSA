#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]); // undirected graph
    }

    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            queue<pair<int, int>> q;
            q.push({i, -1});
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, node});
                    } else if (neighbor != parent) {
                        return true; // Cycle detected
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int V1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << "Output 1: " << (hasCycle(V1, edges1) ? "true" : "false") << endl;

    int V2 = 4;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}};
    cout << "Output 2: " << (hasCycle(V2, edges2) ? "true" : "false") << endl;

    return 0;
}
