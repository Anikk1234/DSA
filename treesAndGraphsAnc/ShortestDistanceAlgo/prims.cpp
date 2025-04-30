#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define INF INT_MAX

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Prim's algorithm to find the MST
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V);       // To store constructed MST
    vector<int> key(V, INF);     // Key values to pick min weight edge
    vector<bool> mstSet(V, false); // To represent set of vertices included in MST

    key[0] = 0;      // Starting vertex has 0 weight
    parent[0] = -1;  // Root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "\nEdges in MST:\n";
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        cout << char(parent[i] + 'A') << " - " << char(i + 'A') << " : " << graph[i][parent[i]] << "\n";
        totalCost += graph[i][parent[i]];
    }
    cout << "Total cost of MST: " << totalCost << "\n";
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}
