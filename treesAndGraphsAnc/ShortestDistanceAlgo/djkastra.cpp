#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
using namespace std;

typedef pair<int, int> PII;

// Dijkstra's algorithm to compute shortest path from source to destination
int dijkstra(int source, int destination, vector<vector<PII>>& graph, int V, vector<int>& parent) {
    vector<int> dist(V, INT_MAX);
    parent.assign(V, -1);  // Track the parent of each node for path reconstruction

    dist[source] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (u == destination) break;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;  // Update parent
                pq.push({dist[v], v});
            }
        }
    }

    return dist[destination] == INT_MAX ? -1 : dist[destination];
}

// Function to print the path from source to destination using the parent array
void printPath(int source, int destination, const vector<int>& parent) {
    stack<int> path;
    int current = destination;

    // Traverse from destination to source using parent[]
    while (current != -1) {
        path.push(current);
        current = parent[current];
    }

    // Check if we could reach the source
    if (path.top() != source) {
        cout << "No path exists from " << source << " to " << destination << endl;
        return;
    }

    cout << "Shortest path: ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<PII>> graph(V);
    cout << "Enter edges (format: from to weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For undirected graph
    }

    int source, destination;
    cout << "Enter source vertex (0 to " << V - 1 << "): ";
    cin >> source;

    cout << "Enter destination vertex (0 to " << V - 1 << "): ";
    cin >> destination;

    vector<int> parent(V);
    int distance = dijkstra(source, destination, graph, V, parent);

    if (distance == -1) {
        cout << "There is no path from " << source << " to " << destination << ".\n";
    } else {
        cout << "Shortest distance from " << source << " to " << destination << ": " << distance << endl;
        printPath(source, destination, parent);
    }

    return 0;
}
