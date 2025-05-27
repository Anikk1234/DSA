#include <bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &adj, int u, int v, int dir) {
    adj[u].push_back(v);
    if (dir == 0) {  // If undirected graph, add reverse edge
        adj[v].push_back(u);
    }
}

void Display(vector<vector<int>>& adj, int vertices) {
    for (int i = 1; i <= vertices; i++) { // Fixed loop to include all nodes
        cout << i << " -> ";
        for (int ele : adj[i]) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

void bfs(vector<vector<int>>& adj, int start) {
    queue<int> q;
    vector<bool> visit(adj.size(), false);
    
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int x : adj[curr]) {
            if (!visit[x]) {
                visit[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    vector<vector<int>> adj;

    int n, u, v, m, dir;
    cout << "Enter number of vertices: ";
    cin >> n;
    adj.resize(n + 1);  // Ensuring proper adjacency list size

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Notation for directed graph = 1 or undirected graph = 0: ";
    cin >> dir;

    cout << "Now enter starting and ending vertex:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        addedge(adj, u, v, dir);
    }

    cout << "Graph:" << endl;
    Display(adj, n);

    cout << "For BFS ...insert starting position: ";
    int st;
    cin >> st;

    cout << "BFS Traversal: ";
    bfs(adj, st);

    return 0;
}
