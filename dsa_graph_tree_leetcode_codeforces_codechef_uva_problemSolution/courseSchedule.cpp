// Problem: Checking if it's possible to finish all courses by detecting cycles in a directed graph
// Description: Determine if it's possible to finish all courses given their prerequisites.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        // 0: not visited, 1: visiting, 2: visited
        if (visited[node] == 1) return false; // Cycle detected
        if (visited[node] == 2) return true;  // Already processed
        
        visited[node] = 1; // Mark as visiting
        
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, visited)) {
                return false;
            }
        }
        
        visited[node] = 2; // Mark as visited
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto& prereq : prerequisites) {
            graph[prereq[0]].push_back(prereq[1]);
        }
        
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, graph, visited)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    cout << (sol.canFinish(2, prerequisites) ? "true" : "false") << endl;  // Output: false
    return 0;
}
