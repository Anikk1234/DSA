#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minTimeToRotAll(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    int freshCount = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Enqueue all rotten oranges and count fresh ones
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = true;
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // Edge case: no fresh oranges
    if (freshCount == 0) return 0;

    int time = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // BFS traversal
    while (!q.empty()) {
        int sz = q.size();
        bool rotted = false;

        for (int i = 0; i < sz; ++i) {
            auto [x, y] = q.front(); q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !visited[nx][ny] && grid[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    freshCount--;
                    rotted = true;
                }
            }
        }

        if (rotted) time++; // Increase time only if any orange rotted this round
    }

    return (freshCount == 0) ? time : -1;
}

int main() {
    vector<vector<int>> mat1 = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    vector<vector<int>> mat2 = {{2, 2, 0, 1}};
    vector<vector<int>> mat3 = {{2, 2, 2}, {0, 2, 0}};

    cout << "Output 1: " << minTimeToRotAll(mat1) << endl;  // Output: 1
    cout << "Output 2: " << minTimeToRotAll(mat2) << endl;  // Output: -1
    cout << "Output 3: " << minTimeToRotAll(mat3) << endl;  // Output: 0

    return 0;
}
