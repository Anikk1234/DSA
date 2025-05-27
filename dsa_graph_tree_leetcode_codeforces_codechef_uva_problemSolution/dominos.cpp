// Problem: Counting the total number of dominos that fall
// Description: Count the number of dominos that will fall when knocking down some initial dominos.

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;
        
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        
        vector<bool> visited(n + 1, false);
        
        for (int i = 0; i < l; i++) {
            int z;
            cin >> z;
            if (!visited[z]) {
                dfs(z, graph, visited);
            }
        }
        
        int fallen = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                fallen++;
            }
        }
        
        cout << fallen << endl;
    }
    
    return 0;
}

