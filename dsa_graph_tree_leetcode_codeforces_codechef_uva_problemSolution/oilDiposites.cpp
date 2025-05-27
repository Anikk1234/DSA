// Problem: Counting connected components in a 2D grid
// Description: Count the number of connected oil deposits in a 2D grid.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '@') {
        return;
    }
    
    grid[i][j] = '*'; // Mark as visited
    
    // Visit all 8 neighbors (including diagonals)
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            dfs(grid, i + dx, j + dy, m, n);
        }
    }
}

int main() {
    int m, n;
    while (cin >> m >> n && m != 0) {
        vector<vector<char>> grid(m, vector<char>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        int deposits = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    deposits++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        cout << deposits << endl;
    }
    
    return 0;
}

