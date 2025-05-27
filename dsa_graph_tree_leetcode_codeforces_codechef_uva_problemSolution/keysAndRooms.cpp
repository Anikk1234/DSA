// Problem: Checking if all rooms can be visited starting from room 0
// Description: Determine if all rooms can be visited using the keys found in each room.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        // Start from room 0
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            
            // Visit all rooms that can be accessed using keys from the current room
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        
        // Check if all rooms were visited
        for (bool v : visited) {
            if (!v) return false;
        }
        
        return true;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    cout << (sol.canVisitAllRooms(rooms) ? "true" : "false") << endl;  // Output: true
    return 0;
}
