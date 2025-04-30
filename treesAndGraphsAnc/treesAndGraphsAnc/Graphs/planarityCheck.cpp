#include <iostream>
#include <vector>
using namespace std;

/*
 * A simple C++ program to check planarity using Euler’s inequality:
 * For a simple connected planar graph: E <= 3V - 6
 * Input: Adjacency list
 * Works correctly for small, simple graphs only.
 */

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);
    int totalEdges = 0;

    cout << "Enter adjacency list (space separated; -1 to end each vertex's list):\n";
    for (int i = 0; i < V; ++i) {
        cout << "Neighbors of vertex " << i << ": ";
        int x;
        while (cin >> x && x != -1) {
            if (x >= 0 && x < V) {
                adj[i].push_back(x);
            } else {
                cout << "Invalid vertex.\n";
            }
        }
    }

    // Count total edges (avoid double-counting)
    for (int i = 0; i < V; ++i) {
        for (int j : adj[i]) {
            if (i < j) totalEdges++;  // count each edge once
        }
    }

    cout << "\nTotal vertices (V): " << V << "\n";
    cout << "Total edges (E): " << totalEdges << "\n";

    if (V >= 3 && totalEdges <= 3 * V - 6) {
        cout << "Graph *might* be planar (passes Euler’s inequality).\n";
    } else {
        cout << "Graph is NOT planar (fails Euler’s inequality).\n";
    }

    return 0;
}
