#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

/*
 * Topological Sort (All Possible)
 * Supports vertices like A B C and 1 2 3
 * Input format:
 *   Enter number of edges
 *   Enter each edge in form: FROM TO (e.g., A B or 1 2)
 * Program builds adjacency list and prints all valid topological orderings
 */

// Graph and helper data
unordered_map<string, vector<string>> adj; // Adjacency list
unordered_map<string, int> indegree;       // Indegree of each node
set<string> allNodes;                      // Set of all nodes

// Store current result path
vector<string> current;
vector<vector<string>> allOrders; // Store all topological sorts

// Recursive function to generate all topological sorts
void dfsTopologicalSort() {
    bool hasNext = false;

    for (const string& node : allNodes) {
        if (indegree[node] == 0) {
            hasNext = true;
            indegree[node] = -1; // Mark as visited
            current.push_back(node);

            for (const string& neighbor : adj[node]) {
                indegree[neighbor]--;
            }

            dfsTopologicalSort();

            // Backtrack
            for (const string& neighbor : adj[node]) {
                indegree[neighbor]++;
            }
            current.pop_back();
            indegree[node] = 0;
        }
    }

    if (!hasNext && current.size() == allNodes.size()) {
        allOrders.push_back(current);
    }
}

int main() {
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter each edge (format: FROM TO), e.g., A B or 1 2:\n";
    for (int i = 0; i < E; ++i) {
        string u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
        allNodes.insert(u);
        allNodes.insert(v);
    }

    // Initialize indegrees for all nodes (even those with no incoming edges)
    for (const string& node : allNodes) {
        if (indegree.find(node) == indegree.end())
            indegree[node] = 0;
    }

    cout << "\nAll possible topological orderings:\n";
    dfsTopologicalSort();

    int count = 1;
    for (const auto& order : allOrders) {
        cout << count++ << ": ";
        for (const auto& node : order) {
            cout << node << " ";
        }
        cout << "\n";
    }

    if (allOrders.empty()) {
        cout << "No valid topological ordering exists (graph may have a cycle).\n";
    }

    return 0;
}
