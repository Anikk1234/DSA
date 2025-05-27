#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Greedy Graph Coloring
 * Input: Graph as adjacency list
 * Output: Number of colors used and coloring for each vertex
 * Note: Greedy algorithm does NOT guarantee minimum number of colors,
 * but gives a valid coloring.
 */

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    // Initialize adjacency list
    vector<vector<int>> adj(V);

    cout << "Enter adjacency list (neighbors space-separated; -1 to end each line):\n";
    for (int i = 0; i < V; ++i) {
        cout << "Neighbors of vertex " << i << ": ";
        int x;
        while (cin >> x && x != -1) {
            if (x >= 0 && x < V)
                adj[i].push_back(x);
            else
                cout << "Invalid vertex.\n";
        }
    }  

    // Array to store color assigned to each vertex
    vector<int> color(V, -1);  // -1 means uncolored

    // Array to mark unavailable colors
    vector<bool> available(V, false); // max V colors possible

    // Assign the first color to the first vertex
    color[0] = 0;

    // Assign colors to remaining vertices
    for (int u = 1; u < V; ++u) {
        // Mark colors used by adjacent vertices
        for (int neighbor : adj[u]) {
            if (color[neighbor] != -1)
                available[color[neighbor]] = true;
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; ++cr) {
            if (!available[cr])
                break;
        }

        color[u] = cr;  // Assign the found color

        // Reset available[] for next iteration
        for (int neighbor : adj[u]) {
            if (color[neighbor] != -1)
                available[color[neighbor]] = false;
        }
    }

    // Find number of colors used
    int numColors = *max_element(color.begin(), color.end()) + 1;

    cout << "\nTotal colors used: " << numColors << "\n";
    cout << "Vertex coloring:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << " -> Color " << color[i] << "\n";
    }

    return 0;
}
