// Problem: Finding shortest path in a graph with special movement rules
// Description: Find the shortest path in a graph where movement follows specific rules based on the current state.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

// Direction arrays
int dr[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
int dc[] = {0, 1, 0, -1};

struct State {
    int r, c, dir, moves;
    
    bool operator==(const State& other) const {
        return r == other.r && c == other.c && dir == other.dir;
    }
};

struct StateHash {
    size_t operator()(const State& state) const {
        return (state.r * 10000) + (state.c * 100) + state.dir;
    }
};

int main() {
    int n, m;
    while (cin >> n >> m && n && m) {
        vector<vector<char>> grid(n, vector<char>(m));
        
        // Read the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        // Find start and end positions
        int sr = -1, sc = -1, er = -1, ec = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (grid[i][j] == 'T') {
                    er = i;
                    ec = j;
                }
            }
        }
        
        // BFS to find the shortest path
        unordered_map<State, int, StateHash> dist;
        queue<State> q;
        
        // Try all 4 starting directions
        for (int d = 0; d < 4; d++) {
            State start = {sr, sc, d, 0};
            q.push(start);
            dist[start] = 0;
        }
        
        int minMoves = INT_MAX;
        
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            
            // If reached target
            if (grid[curr.r][curr.c] == 'T') {
                minMoves = min(minMoves, curr.moves);
                continue;
            }
            
            // Try all possible next moves
            for (int turn = -1; turn <= 1; turn++) {  // -1: turn left, 0: straight, 1: turn right
                int newDir = (curr.dir + turn + 4) % 4;
                int nr = curr.r + dr[newDir];
                int nc = curr.c + dc[newDir];
                
                // Check if valid move
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#') {
                    State next = {nr, nc, newDir, curr.moves + 1};
                    
                    // If this state hasn't been visited or we found a shorter path
                    if (dist.find(next) == dist.end() || dist[next] > curr.moves + 1) {
                        dist[next] = curr.moves + 1;
                        q.push(next);
                    }
                }
            }
        }
        
        if (minMoves != INT_MAX) {
            cout << minMoves << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}

