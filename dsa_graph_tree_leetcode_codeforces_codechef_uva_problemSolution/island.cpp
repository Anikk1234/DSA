#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

// 8 directions: (row, col) movements
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && 
            grid[x][y] == 'L' && !visited[x][y]);
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (isValid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}

int countIslands() {
    int count = 0;
    visited.assign(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'L' && !visited[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Example 1
    grid = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}
    };
    n = grid.size();
    m = grid[0].size();
    cout << "Number of islands: " << countIslands() << endl;  // Output: 4

    // Example 2
    grid = {
        {'W', 'L', 'L', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'L', 'L', 'W', 'L', 'W'}
    };
    n = grid.size();
    m = grid[0].size();
    cout << "Number of islands: " << countIslands() << endl;  // Output: 2

    return 0;
}
