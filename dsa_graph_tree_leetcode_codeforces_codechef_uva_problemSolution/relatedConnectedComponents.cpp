//Problem: Finding the largest connected component in a grid
//Description: Identify the largest connected component of cells with water in a grid.

#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == 0) {
        return 0;
    }
    
    visited[i][j] = true;
    int size = grid[i][j];
    
    // Visit all 4 neighbors
    size += dfs(grid, i+1, j, visited);
    size += dfs(grid, i-1, j, visited);
    size += dfs(grid, i, j+1, visited);
    size += dfs(grid, i, j-1, visited);
    
    return size;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int max_size = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] > 0) {
                int size = dfs(grid, i, j, visited);
                max_size = max(max_size, size);
            }
        }
    }
    
    cout << max_size << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

